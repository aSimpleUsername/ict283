//windlogType.h - Simple struct to hold pass group of vectors easier
//Connor Nicholson
//05 May 2020

#ifndef WINDLOGTYPE_H
#define WINDLOGTYPE_H

#include "vector/vector.h"
#include "date/date.h"
#include "time/time.h"

        /**
        *@struct
        *@brief Holds relevant file date
        *
        * @author Connor Nicholson
        * @version 01
        * @date 05 May 20
        */
struct WindlogType
{
        /**
        *@brief  default constructor
        */
    WindlogType();

    Vector<Date> date;
    Vector<Time> time;
    Vector<float> speed;        //meters per second
    Vector<float> airTemp;      //ambient air temperature
    Vector<float> solarRad;     //Solar radiation
};

inline WindlogType::WindlogType()
    : date(), time(), speed(), airTemp(), solarRad() {}

#endif // WINDLOGTYPE_H

