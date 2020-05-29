#ifndef PROJECTION_H
#define PROJECTION_H

#include "mat4.hpp"

namespace clutch
{
    inline Mat4<float> Perspective(const float fov, 
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

    inline Mat4<float> Orthopraphic(const float left,
                                    const float right,
                                    const float bottom,
                                    const float top,
                                    const float near,
                                    const float far)
    {
       
        return Mat4<float>  {2.0f / (right - left), 0.0,   0.0,   - (right + left) / (right - left), 
                            0.0f, (2.0f) / (top - bottom), 0.0f,  - (top + bottom) / (top - bottom),
                            0.0f, 0.0f,  - (2.0f) / (far - near), - (far + near) / (far - near), 
                            0.0f, 0.0f, 0.0f, 1.0f}; 
    }
}

#endif