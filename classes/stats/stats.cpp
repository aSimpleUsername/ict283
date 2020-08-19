// stats.cpp - implementaition of stats namespace

//#include "stats.h"


std::string getMonthString(int month)
{
    std::string months[12] = {"January", "Febuary", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};

    return(months[month-1]);       // -1 because counts from zero
}
