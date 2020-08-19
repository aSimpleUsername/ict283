// date.h - date class declaration
// author Connor Nicholson - 28 APR 20

#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>


	/**
	 * @class Date
	 * @brief  Creates Date object
	 *
	 *
	 * @author Connor Nicholson
	 * @version 03
	 * @date 28/04/2020
	 *
	 * @todo Nil
	 * @bug Nil
	 *
	 */
class Date {
public:
        /**
        *@brief default constructor
        */
    Date();

        /**
        *@brief constructor
        *@param construct a Date with day of the month, month and year
        */
    Date(int day, int month, int year);

        /**
        * @brief construct a date from string dd/mm/yyyy
        * @param date as a string
        */
    Date(std::string date);

        /**
        *@brief sets day
        *@param the new day value
        */
    void setDay(int day);

        /**
        *@brief gets day
        *@return returns day
        */
    int getDay() const;

        /**
        *@brief sets month
        *@param the new month value
        */
    void setMonth(int month);

        /**
        *@brief gets month
        *@return returns month
        */
    int getMonth() const;

        /**
        *@brief sets year
        *@param the new year value
        */
    void setYear(int day);

        /**
        *@brief gets year
        *@return returns year
        */
    int getYear() const;

        /**
        *@brief converts date into string
        *@return returns date as string
        */
    std::string getDateString() const;

        /**
        *@brief Assignment operator declaration
        *@param the date as a string 'dd/mm/yyy/
        */
    Date& operator=(const std::string &date);

        /**
        *@brief less than operator declaration
        *@param date object to compare
        */
    bool operator<(const Date& other);

        /**
        *@brief greater than operator declaration
        *@param date object to compare
        */
    bool operator>(const Date& other);

        /**
        *@brief equal to operator declaration
        *@param date object to compare
        */
    bool operator==(const Date& other);

        /**
        *@brief not equal to than operator declaration
        *@param date object to compare
        */
    bool operator!=(const Date& other);


        /**
        *@brief Returns the month as a string
        *@return month as a string
        */
    static std::string getMonthString(int month);

private:
    int m_day;
    int m_month;
    int m_year;
};

#endif
