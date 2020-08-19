//outputClass.cpp - prepares data for output in a neat data structure
//Connor Nicholson
//05 May 2020

#include "outputClass.h"

// SETTERS / GETTERS
Map<int, Map<int, float>> OutputClass::getWindAvg() const {return m_windAvg;}
Map<int, Map<int, float>> OutputClass::getWindStdDev() const {return m_windStdDev;}
Map<int, Map<int, float>> OutputClass::getTempAvg() const {return m_tempAvg;}
Map<int, Map<int, float>> OutputClass::getTempStdDev() const {return m_tempStdDev;}
Map<int, Map<int, float>> OutputClass::getSolarTotal() const {return m_solarTotal;}
float OutputClass::getHighSolar() const {return m_highSolar;}
Vector<Time> OutputClass::getHighSolarTime() const {return m_highSolarTime;}
// END SETTERS GETTERS



OutputClass::OutputClass(Map<int, Map<int, WindlogType>> &windlog)
    : m_windAvg(), m_windStdDev(), m_tempAvg(), m_tempStdDev(), m_solarTotal(), m_search(), m_highSolar(0), m_highSolarTime()
{
    computeData(windlog);
}

//windlog format = Map<first=Year, Second = Map<first=month, seccond = vector>>
void OutputClass::computeData(Map<int, Map<int, WindlogType>> &windlog)
{
    WindlogType temp;

    int year, month;
    windlog.getIt() = windlog.itBegin();        //initialise year iterator
    while(windlog.getIt() != windlog.itEnd())       //for each year
    {
        year = windlog.getIt()->first;      //set current year
        windlog.getIt()->second.getIt() = windlog.getIt()->second.itBegin();        //initialise month iterator
        while(windlog.getIt()->second.getIt() != windlog.getIt()->second.itEnd())       //for each month
        {
            month = windlog.getIt()->second.getIt()->first;     //set current month
            for(int i=0; i< windlog.getIt()->second.getIt()->second.date.getSize(); i++)       //for each element in the vector
            {
                temp.date[i] = windlog.getIt()->second.getIt()->second.date[i];       //builds temp windlog Vector for each month
                temp.speed[i] = windlog.getIt()->second.getIt()->second.speed[i] * 3.6;     // converts to km/h
                temp.airTemp[i] = windlog.getIt()->second.getIt()->second.airTemp[i];
                if(windlog.getIt()->second.getIt()->second.solarRad[i] >= 100)
                    temp.solarRad[i] = (windlog.getIt()->second.getIt()->second.solarRad[i] / 6 ) / 1000 ;        //convert to KWh
                else
                    temp.solarRad[i] = 0;
            }

            //cycle through all the temp month vectors and calculate averages
            if(temp.date.getSize() > 0)
            {
                m_windAvg[std::move(year)][std::move(month)] = stats::calcAvg(temp.speed);           //std::move required tomore &&rvalue reference
                m_windStdDev[std::move(year)][std::move(month)] = stats::calcStdDev(temp.speed, stats::calcAvg(temp.speed));
                m_tempAvg[std::move(year)][std::move(month)] = stats::calcAvg(temp.airTemp);
                m_tempStdDev[std::move(year)][std::move(month)] = stats::calcStdDev(temp.airTemp, stats::calcAvg(temp.airTemp));
                m_solarTotal[std::move(year)][std::move(month)] = stats::calcTotal(temp.solarRad);

                m_search.addLeaf(year*100 + month); //year*100 + month creates unique int, in order eg. Jul 2014 becomes 201407
            }
            windlog.getIt()->second.getIt()++;      //iterate month
        }
        windlog.getIt()++;          //iterate year
    }
}

bool OutputClass::searchOutput(int yearMonth)
{
    return(m_search.searchKey(yearMonth));
}

//It's unreasonable to calculate highest for every day, so seperate function waiting for the user input.
void OutputClass::calculateHighSolar(Map<int, Map<int, WindlogType>> &windlog, Date date)
{
    m_highSolar = 0;        //reset highest to 0
    m_highSolarTime.clearVector();      //clear time array

    //Vectors for the given month
    Vector<Date> dateVector = windlog[std::move(date.getYear())][std::move(date.getMonth())].date;      //vector of dates within month
    Vector<Time> timeVector = windlog[std::move(date.getYear())][std::move(date.getMonth())].time;      //vector of times within month
    Vector<float> solarVector = windlog[std::move(date.getYear())][std::move(date.getMonth())].solarRad;        //vector ov solar radiation within month

    Vector<int> dayIndex;       //will hold list of month index of the day we want
    for(int i=0; i< dateVector.getSize(); i++)      //for every day in the month
    {
        if(dateVector[i] == date)       //find the all index that have the day we want
            dayIndex.push(i);
    }

    for(int i=0; i<dayIndex.getSize(); i++)     //for every element in the day
    {
        if(solarVector[dayIndex[i]] == m_highSolar)     //if it's equal to current highest, add the time to vector
            m_highSolarTime.push(timeVector[dayIndex[i]]);

        if(solarVector[dayIndex[i]] > m_highSolar)      //if it's higher than current highest, clear time array and set new highest
        {
            m_highSolar = solarVector[dayIndex[i]];
            m_highSolarTime.clearVector();
            m_highSolarTime.push(timeVector[dayIndex[i]]);
        }
    }
}
