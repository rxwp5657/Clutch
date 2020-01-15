#ifndef LOOKAT_H
#define LOOKAT_H

#include "mat4.hpp"
#include "vec4.hpp"
#include "transforms.hpp"

namespace clutch
{   
    template <typename T>
    Mat4<float> LookAt(const Vec4<T>& position, 
                       const Vec4<T>& target, 
                       const Vec4<T>& up)
    {
        auto forward = Normalize(position - target);
        auto left    = Normalize(Cross(up,forward));
        auto true_up = Cross(forward,left);

        Mat4<float> rotation{left.x, left.y, left.z, 0.0f,
                             true_up.x, true_up.y, true_up.z, 0.0f,
                             forward.x, forward.y, forward.z, 0.0f,
                             0.0f, 0.0f, 0.0f, 1.0f};
        
        auto translation = Translation(-position.x, -position.y, -position.z);

        return rotation * translation;
    }
}

#endif