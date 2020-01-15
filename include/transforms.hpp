#ifndef TRANSFORMS_H
#define TRANSFORMS_H

#include "mat4.hpp"

namespace clutch
{
    template <typename T>
    Mat4<T> Translation(T x, T y, T z)
    {
        return Mat4<T>{1, 0, 0, x,
                       0, 1, 0, y,
                       0, 0, 1, z,
                       0, 0, 0, 1};
    }

    template <typename T>
    Mat4<T> Scale(T x, T y, T z)
    {
        return Mat4<T>{x, 0, 0, 0,
                       0, y, 0, 0,
                       0, 0, z, 0,
                       0, 0, 0, 1};
    }

    template <typename T>
    Mat4<T> RotateX(T radians)
    {
        return Mat4<T>{1,0,0,0,
                       0,cos(radians),-sin(radians),0,
                       0,sin(radians),cos(radians), 0,
                       0,0,0,1};
    }

    template <typename T>
    Mat4<T> RotateY(T radians)
    {
        return Mat4<T>{cos(radians),0,sin(radians),0,
                       0,1,0,0,
                      -sin(radians),0,cos(radians), 0,
                       0,0,0,1};
    }

    template <typename T>
    Mat4<T> RotateZ(T radians)
    {
        return Mat4<T>{cos(radians),-sin(radians), 0, 0,
                       sin(radians),cos(radians),  0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1};
    }

    template <typename T>
        auto Shearing(T x1, T x2, T y1, T y2, T z1, T z2)
        {
            return Mat4<T>{1, x1, x2, 0,
                           y1, 1, y2, 0,
                           z1, z2, 1, 0,
                           0,  0,  0, 1};
        }
}

#endif