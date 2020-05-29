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

    template<typename T>
    T radians(T degrees)
    {
        return static_cast<T>((PI * degrees) / 180.0f);
    }
}

#endif