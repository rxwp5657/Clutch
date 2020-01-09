#ifndef COMMONS_H
#define COMMONS_H

#include <math.h>

namespace clutch
{
    auto const PI = 3.14159265358979323846f;

    template <typename T>
    bool cmpf(T& A, T& B, float epsilon = 0.005f)
    { 
        return (fabs(A - B) < epsilon);
    }   
}

#endif