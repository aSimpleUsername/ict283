//outputClass.h - prepares data for output in a neat data structure
//Connor Nicholson
//05 May 2020

#ifndef OUTPUTCLASS_H
#define OUTPUTCLASS_H


#include <iostream>

#include <string>
#include "stats/stats.h"
#include "windlog/windlogType.h"
#include "BST/BST.h"
#include "map/map.h"

struct WindlogType; //Forward declaration


        /**
        * @class
        * @brief Prepares data for output for cleaner main file
        *
        * @author Connor Nicholson
        * @version 01
        * @date 05 May 20
        */
class OutputClass
{
public:
        /**
        *@brief Constructs and fills the relevant data ready for output
        *@param The full windlog struct, and the specified year
        */
    OutputClass(Map<int, Map<int, WindlogType>> &windlog);

        /**
        *@brief Gets month
        *@return The month
        */
    Map<int, Map<int, std::string>> getMonth() const;

        /**
        *@brief Gets the average wind speed
        *@return wind average
        */
    Map<int, Map<int, float>> getWindAvg() const;

        /**
        *@brief Gets wind standard deviation
        *@return the wind standard deviation
        */
    Map<int, Map<int, float>> getWindStdDev() const;

        /**
        *@brief Average temperature
        *@return temperature average
        */
    Map<int, Map<int, float>> getTempAvg() const;

        /**
        *@brief Gets temperature standard deviation
        *@return temperature standard deviation
        */
    Map<int, Map<int, float>> getTempStdDev() const;

        /**
        *@brief Gets Solar radiation total
        *@return Solar radiation total
        */
    Map<int, Map<int, float>> getSolarTotal() const;

        /**
        *@brief Gets the highest solar value for specified day
        *@return the highest solar value
        */
    float getHighSolar() const;

        /**
        *@brief Gets the time of day the highest solar value was recorded
        *@return Vector of the times
        */
    Vector<Time> getHighSolarTime() const;

        /**
        *@brief searches quickly if there's data for that year/month
        *@param int specifying year and month with the formula year*100 + month
        *@return true if data exists for that year/month
        */
    bool searchOutput(int yearMonth);

        /**
        *@brief Calculates the highest solar in a given a day
        *@param the complete windlog reference and the given date
        */
    void calculateHighSolar(Map<int, Map<int, WindlogType>> &windlog, Date date);

private:

    BST<int> m_search;

    Map<int, Map<int, float>> m_windAvg;
    Map<int, Map<int, float>> m_windStdDev;
    Map<int, Map<int, float>> m_tempAvg;
    Map<int, Map<int, float>> m_tempStdDev;
    Map<int, Map<int, float>> m_solarTotal;
    float m_highSolar;
    Vector<Time> m_highSolarTime;


        /**
        *@brief computes the data from windlog into the desired ouput information - called by the constructor
        *@param the windlog reference
        */
    void computeData(Map<int, Map<int, WindlogType>> &windlog);
};

#endif // OUTPUTCLASS_H
