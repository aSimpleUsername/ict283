// date.cpp - date class implementation
// author Connor Nicholson - 28 Apr 20

#include "date.h"

Date::Date()
    : m_day(0), m_month(0), m_year(0) {}

Date::Date(int day, int month, int year)
    : m_day(day), m_month(month), m_year(year) {}

Date::Date(std::string date)
    : m_day(0), m_month(0), m_year(0)
{
    std::string d, m, y;

    std::stringstream ss(date);
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    m_day = stoi(d);
    m_month = stoi(m);
    m_year = stoi(y);
}

void Date::setDay(int day) {m_day = day;}

int Date::getDay() const {return m_day;}

void Date::setMonth(int month) {m_month = month;}

int Date::getMonth() const {return m_month;}

void Date::setYear(int year) {m_year = year;}

int Date::getYear() const{return m_year;}

std::string Date::getDateString() const
{
    //converts day to string and gives leading 0 if required
    std::string day = std::to_string(m_day);
    if(m_day < 10)
        day = "0" + day;

    //converts month to string and gives leading 0 if required
    std::string month = std::to_string(m_month);
    if(m_month < 10)
        month = "0" + month;

    std::string year = std::to_string(m_year);

    return(day + "/" + month + "/" + year);
}

Date& Date::operator=(const std::string &date)
{
    std::string d, m, y;

    std::stringstream ss(date);
    getline(ss, d, '/');
    getline(ss, m, '/');
    getline(ss, y);

    m_day = stoi(d);
    m_month = stoi(m);
    m_year = stoi(y);

    return(*this);
}

bool Date::operator<(const Date& other)
{
    return( (m_year < other.m_year) ||
           (m_year == other.m_year && m_month < other.m_month) ||
           (m_year == other.m_year && m_month == other.m_month &&
            m_day < other.m_day));
}

bool Date::operator>(const Date& other)
{
    return( (m_year > other.m_year) ||
       (m_year == other.m_year && m_month > other.m_month) ||
       (m_year == other.m_year && m_month == other.m_month &&
        m_day > other.m_day));
}

bool Date::operator==(const Date& other)
{
    return(m_day == other.m_day &&
           m_month == other.m_month &&
           m_year == other.m_year);
}

bool Date::operator!=(const Date& other)
{
    return(m_day != other.m_day ||
           m_month != other.m_month ||
           m_year != other.m_year);
}

std::string Date::getMonthString(int month)
{
    std::string const months[12] = {"January", "Febuary", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};

    return(months[month-1]);       // -1 because counts from zero
}


