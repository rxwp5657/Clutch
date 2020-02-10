#ifndef LOOKAT_H
#define LOOKAT_H

#include "mat4.hpp"
#include "vec4.hpp"
#include "transforms.hpp"

namespace clutch
{   
    template <typename T>
    Mat4<float> LookAt(const Vec4<T>& eye, 
                       const Vec4<T>& center, 
                       const Vec4<T>& up)
    {
        // Calculate the basis vectors 

        auto f{Normalize(center - eye)};
		auto s{Normalize(Cross(f, up))};
		auto u{Cross(s, f)};

        Mat4<float>result{s.x, s.y, s.z, -Dot(s, eye),
                          u.x, u.y, u.z, -Dot(u, eye),
                         -f.x,-f.y,-f.z,  Dot(f, eye),
                          0.0f, 0.0f, 0.0f, 1.0f};
        
        return result;
    }
}

#endif