#include <iostream>
#include "map.h"
#include "string"


int main()
{
    /*Map<int, int> testMap;

    for(int i=0; i<10; i++)
        testMap.add(i, i*3);

    std::cout << testMap.getSize() << " Elements in Map\n";

    for(int i=0; i<10; i++)
        std::cout << testMap.getAt(i) << std::endl;*/

    //**********************************************************

    /*Map<int, Map<int, int>> testMap;
    int year =  1997;
    int month = 7;
    int value = 69;

    testMap[std::move(year)][std::move(month)] = value;

    std::cout << testMap[std::move(year)][std::move(month)];*/

    //*******************************************************

    /*Map<std::string, int> testMap;
    testMap["First"] = 1;
    testMap["Second"] = 2;
    testMap["Third"] = 3;
    testMap["Fourth"] = 4;
    testMap["Fifth"] = 5;

    testMap.getIt() = testMap.itBegin();
    while(testMap.getIt() != testMap.itEnd())
    {
        std::cout << testMap.getIt()->first << " : " <<  testMap.getIt()->second << std::endl;
        testMap.getIt()++;
    }*/


    Map<int, Map<int, std::string>> testMap;
    testMap[2001][01] = "January 2001";
    testMap[2001][02] = "Febuary 2001";
    testMap[2003][07] = "July 2003";
    testMap[2004][12] = "December 2004";
    testMap[2003][11] = "November 2003";
    testMap[2004][07] = "July 2004";

    testMap.getIt() = testMap.itBegin();
    while(testMap.getIt() != testMap.itEnd())
    {
        testMap.getIt()->second.getIt() = testMap.getIt()->second.itBegin();
        while(testMap.getIt()->second.getIt() != testMap.getIt()->second.itEnd())
        {
            std::cout << testMap.getIt()->second.getIt()->second << std::endl;
            testMap.getIt()->second.getIt()++;
        }
        testMap.getIt()++;
    }


    std::cout << "Hello World";


    return(0);
}
