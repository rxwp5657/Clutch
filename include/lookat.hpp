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
        // Calculate the basis vectors 

        auto forward = Normalize(target - position);
        auto left    = Normalize(Cross(forward,up));
        auto true_up = Cross(left,forward);

        Mat4<float> rotation{left,true_up,-forward,Vec4<float>{0.0f,0.0f,0.0f,1.0f}};
        
        auto translation = Translation(-position.x, -position.y, -position.z);
        
        return rotation * translation;
    }
}

#endif