// timeTest.cpp - test program for Time class
// author Connor Nicholson
// 29 Apr 20

#include <iostream>
#include "time.h"

void testConstruct()
{
    std::cout << "*** Test default constructor ***" << std::endl;
    Time time;
    std::cout << time.getTimeString() << std::endl;
}

void testParamConstruct()
{
    std::cout << "*** Test overloaded constructor ***" << std::endl;
    Time time(12, 10);
    std::cout << time.getTimeString() << std::endl;
}

void testStringConstruct()
{
    std::cout << "*** Test overloaded constructor with string ***" << std::endl;
    Time time("10:40");
    std::cout << time.getTimeString() << std::endl;
}

void testSetGet()
{
    std::cout << "*** Test mins setters/getters ***" << std::endl;
    Time time;
    std::cout << time.getTimeString() << std::endl;
    time.setMins(10);
    time.setHrs(20);
    std::cout << "Time: " << time.getHrs() << ":" << time.getMins() << std::endl;
    std::cout << time.getTimeString() << std::endl;
}

void testAssign()
{
    std::cout << "*** TEST ASSIGNMENT WITH STRING ***" << std::endl;
    Time time;
    std::cout << time.getTimeString() << std::endl;
    time = "10:45";
    std::cout << time.getTimeString() << std::endl;
}


int main()
{
    testConstruct();
    testParamConstruct();
    testStringConstruct();
    testSetGet();
    testAssign();

    return(0);
}
