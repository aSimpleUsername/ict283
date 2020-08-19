// stats.h - stats functions
// Connor Nicholsn
// 04 May 2020

#include "vector/vector.h"
#include <cmath>


        /**
        * @namespace
        * @brief simple mathmatical template functions - Average, Standard deviation and Total.
        *
        * @author Connor Nicholson
        * @version 01
        * @date 05 May 20
        */
namespace stats
{
        /**
        * @brief Calculates Average
        * @param Vector
        * @return Avereage
        */
    template<class T>
    float calcAvg(Vector<T> &data);

        /**
        * @brief Calculates standard deviation
        * @param Vector and average
        * @return Standard deviation
        */
    template<class T>
    float calcStdDev(Vector<T> &data, float avg);

        /**
        * @brief Calculates total
        * @param Vector
        * @return total
        */
    template<class T>
    float calcTotal(Vector<T> &data);
}

//***************IMPLEMTATION************************

template<class T>
float stats::calcAvg(Vector<T> &data)
{
    float sum = 0;
    int n = data.getSize();

    for(int i = 0; i<n; i++)
        sum += data[i];

    return(sum/n);
}

template<class T>
float stats::calcStdDev(Vector<T> &data, float avg)
{
    float sum = 0;
    int n = data.getSize();

    for(int i=0; i<n; i++)
        sum += (data[i] - avg) * (data[i] - avg);

    return(sqrt( sum/(n-1) ));
}

template<class T>
float stats::calcTotal(Vector<T> &data)
{
    float sum = 0;
    int n = data.getSize();
    for(int i=0; i<n; i++)
        sum += data[i];

    return(sum);
}

