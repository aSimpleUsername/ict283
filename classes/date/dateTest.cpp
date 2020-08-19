// dateTest.cpp - test program for date class
// author Connor Nicholson
// 28 Apr 20

#include <iostream>
#include "date.h"

void displayDate(Date &date)
{
    std::cout << "Day: " << date.getDay() << std::endl;
    std::cout << "Month: " << date.getMonth() <<std::endl;
    std::cout << "Year: " << date.getYear() << std::endl;
}

void testConstruct()
{
    std::cout << "*** TEST DEFAULT CONSTRUCTOR ***" << std::endl;
    Date date;
    displayDate(date);
}

void testParamConstruct()
{
    std::cout << "*** TEST OVERLOADED CONSTRUCTOR ***" << std::endl;
    Date date(02, 07, 1997);
    displayDate(date);
}

void testStringConstruct()
{
    std::cout << "*** TEST OVERLOADED CONSTRUCTOR WITH STRING ***" << std::endl;
    Date date("02/07/1997");
    displayDate(date);
}

void testSetters()
{
    std::cout << "*** TEST SETTERS ***" << std::endl;
    Date date;
    date.setDay(28);
    date.setMonth(03);
    date.setYear(2020);
    displayDate(date);
}

void testGetDateString()
{
    std::cout << "*** TEST getDateString() ***" << std::endl;
    Date date;
    std::cout << date.getDateString();
}

void testAssign()
{
    std::cout << "*** TEST ASSIGNMENT WITH STRING ***" << std::endl;
    Date date;
    std::cout << date.getDateString() << std::endl;
    date = "02/07/1994";
    displayDate(date);
}

void testGreatLessThan()
{
     std::cout << "*** TEST < and > operators ***" << std::endl;

     Date date, date2, date3;
     date = "02/07/1997";
     date2 = "03/08/1990";
     date3 = "20/05/2020";

     if(date > date2)
        std::cout << "PASSED\n";
     else
        std::cout << "FAILED\n";

     if(date < date3)
        std::cout << "PASSED \n";
    else
        std::cout << "FAILED\n";
}

void testEqualTo()
{
    std::cout << "*** TEST < and > operators ***" << std::endl;

    Date date, date2, date3;
    date = "02/07/1997";
    date2 = "02/07/1997";
    date3 = "20/05/2020";

    if(date == date2)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    if(date != date3)
        std::cout << "PASSED \n";
    else
        std::cout << "FAILED\n";
}

int main()
{
    //testConstruct();
    //testParamConstruct();
    //testStringConstruct();
    //testSetters();
    //testGetDateString();
    //testAssign();
    //testGreatLessThan();
    //testEqualTo();
    return(0);
}
