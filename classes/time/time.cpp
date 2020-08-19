// time.cpp - time class implementation
// author Connor Nicholson - 29 Apr 20

#include "time.h"

Time::Time()
    : m_hrs(0), m_mins(0) {}

Time::Time(int hrs, int mins)
    : m_hrs(hrs), m_mins(mins) {}

Time::Time(std::string time)
    : m_hrs(0), m_mins(0)
{
    std::string h, m;

    std::stringstream ss(time);
    getline(ss, h, ':');
    getline(ss, m);

    m_hrs = stoi(h);
    m_mins = stoi(m);
}

void Time::setHrs(int hrs) {m_hrs = hrs;}
int Time::getHrs() const {return m_hrs;}

void Time::setMins(int mins) {m_mins = mins;}
int Time::getMins() const {return m_mins;}

std::string Time::getTimeString() const
{
    //converts hrs to string and gives leading 0 if required
    std::string hrs = std::to_string(m_hrs);
    if(m_hrs == 0)
        hrs = "00";
    else if(m_hrs < 10)
        hrs = "0" + hrs;

    //converts mins to string and gives leading 0 if required
    std::string mins = std::to_string(m_mins);
    if(m_mins == 0)
        mins = "00";
    else if(m_mins < 10)
        mins = "0" + mins;

    return(hrs + ":" + mins);
}

Time& Time::operator=(std::string &time)
{
    std::string h, m;

    std::stringstream ss(time);
    getline(ss, h, ':');
    getline(ss, m);

    m_hrs = stoi(h);
    m_mins = stoi(m);
}

bool Time::operator<(const Time& other)
{
    return((m_hrs < other.m_hrs) ||
           (m_hrs == other.m_hrs && m_mins < other.m_mins));
}

bool Time::operator>(const Time& other)
{
    return((m_hrs > other.m_hrs) ||
           (m_hrs == other.m_hrs && m_mins > other.m_mins));
}

bool Time::operator==(const Time& other)
{
    return(m_hrs == other.m_hrs &&
           m_mins == other.m_mins );
}

