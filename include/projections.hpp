#ifndef PROJECTION_H
#define PROJECTION_H

#include "mat4.hpp"

namespace clutch
{
    Mat4<float> Perspective(const float fov, 
                            const float aspect_ratio,
                            const float near,
                            const float far)
    {
        auto g = 1.0f / tan(fov/2);

        return Mat4<float> {g/aspect_ratio, 0.0f, 0.0f, 0.0f, 
                            0.0f, g, 0.0f, 0.0f,
                            0.0f, 0.0f, - ((far + near) / (far - near)),-((2*far*near)/(far - near)), 
                            0.0f, 0.0f, -1.0f, 0};
    }

    Mat4<float> Orthopraphic(const float top,
                             const float right,
                             const float bottom,
                             const float left,
                             const float near,
                             const float far)
    {
        auto w_inv = 1.0f / (right  - left);
        auto h_inv = 1.0f / (bottom - top);
        auto d_inv = 1.0f / (far - near);

            return Mat4<float>  {2.0f * w_inv, 0.0,  0.0,  -(right  + left) * w_inv, 
                                 0.0f, 2.0f * h_inv, 0.0f, -(bottom + top)  * h_inv,
                                 0.0f, 0.0f, d_inv, -near * d_inv, 
                                 0.0f, 0.0f, 0.0f, 1.0f}; 
    }


}

#endif