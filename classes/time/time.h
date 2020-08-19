// TIME.H - Time class definition
// author Connor Nicholson

#ifndef TIME_H
#define TIME_H

#include <string>
#include <sstream>

        /**
        * @class Time
        * @brief  Creates time object
        *
        *
        * @author Connor Nicholson
        * @version 03
        * @date 09/06/2020
        *
        * @todo Nil
        * @bug Nil
        *
        */
class Time {
public:
        /**
        *@brief default constructor
        */
    Time();

        /**
        *@brief Overloaded constructor
        *@param hours, minutes
        */
    Time(int hrs, int mins);

        /**
        *@brief Overloaded constructor
        *@param string 'HH:MM'
        */
    Time(std::string time);

        /**
        *@brief Set hours
        *@param new hours
        */
    void setHrs(int hrs);

        /**
        *@brief Gets hours
        *@return hours
        */
    int getHrs() const;

        /**
        *@brief Set minute
        *@param new minutes
        */
    void setMins(int mins);

        /**
        *@brief Gets minutes
        *@return minutes
        */
    int getMins() const;

        /**
        *@brief Combines hours and minutes as a string
        *@return the time as a string
        */
    std::string getTimeString() const;

        /**
        *@brief Assignment operator definition
        */
    Time& operator=(std::string &time);

            /**
        *@brief less than operator declaration
        *@param time object to compare
        */
    bool operator<(const Time& other);

        /**
        *@brief greater than operator declaration
        *@param time object to compare
        */
    bool operator>(const Time& other);

        /**
        *@brief equal to operator declaration
        *@param time object to compare
        */
    bool operator==(const Time& other);

        /**
        *@brief not equal to than operator declaration
        *@param time object to compare
        */
    bool operator!=(const Time& other);

private:
    int m_hrs;
    int m_mins;
};

#endif // TIME_H
