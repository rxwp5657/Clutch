//
//  vec3.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 08/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//

#ifndef VEC3_H 
#define VEC3_H

#include <assert.h>
#include <type_traits>
#include "qualifier.hpp"
#include "commons.hpp"

namespace clutch
{
    template<typename T>
    struct Vec3
    {
        union
        {
            struct{T x, y, z;};
            struct{T r, g, b;};
        };

        Vec3<T>()
        :x{0},
         y{0},
         z{0}
        {
        }

        Vec3<T>(const T v)
        :x{v},
         y{v},
         z{v}
        {
        }

        Vec3<T>(const T a, const T b, const T c)
        : x{a},
          y{b},
          z{c}
        {
        }

        Vec3<T>(const Vec3<T>& v)
        : x{v.x},
          y{v.y},
          z{v.z}
        {
        }

        Vec3<T>& operator=(const Vec3<T>& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
        }
        
        /*
        Vec3<T>(const Vec3<T>&&);
        Vec3<T>& operator=(const Vec3<T>&&);
        */

        template<typename U>
        Vec3<T>& operator+=(const U scalar)
        {
            x += static_cast<T>(scalar);
            y += static_cast<T>(scalar);
            z += static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec3<T>& operator+=(const Vec3<U>& v)
        {
            x += static_cast<T>(v.x);
            y += static_cast<T>(v.y);
            z += static_cast<T>(v.z);
            
            return *this;
        }

        template<typename U>
        Vec3<T>& operator-=(const U scalar)
        {
            x -= static_cast<T>(scalar);
            y -= static_cast<T>(scalar);
            z -= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec3<T>& operator-=(const Vec3<U>& v)
        {
            x -= static_cast<T>(v.x);
            y -= static_cast<T>(v.y);
            z -= static_cast<T>(v.z);

            return *this;
        }

        template<typename U>
        Vec3<T>& operator*=(const U scalar)
        {
            x *= static_cast<T>(scalar);
            y *= static_cast<T>(scalar);
            z *= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec3<T>& operator*=(const Vec3<U>& v)
        {
            x *= static_cast<T>(v.x);
            y *= static_cast<T>(v.y);
            z *= static_cast<T>(v.z);

            return *this;
        }

        template<typename U>
        Vec3<T>& operator/=(const U scalar)
        {
            x /= static_cast<T>(scalar);
            y /= static_cast<T>(scalar);
            z /= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec3<T>& operator/=(const Vec3<U>& v)
        {
            x /= static_cast<T>(v.x);
            y /= static_cast<T>(v.y);
            z /= static_cast<T>(v.z);

            return *this;
        }

        Vec3<T>& operator++()
        {
            x += 1;
            y += 1;
            z += 1;

            return *this;
        }

        Vec3<T>& operator++(int)
        {
            x += 1;
            y += 1;
            z += 1;

            return *this;
        }

        Vec3<T>& operator--()
        {
            x -= 1;
            y -= 1;
            z -= 1;

            return *this;
        }

        Vec3<T>& operator--(int)
        {
            x -= 1;
            y -= 1;
            z -= 1;

            return *this;
        }
        
    };

    template<typename T>
    constexpr inline bool operator == (const Vec3<T>& a, const Vec3<T>& b)
    {
        assert(std::is_arithmetic<T>::value);

        return cmpf(a.x,b.x) && 
               cmpf(a.y,b.y) &&
               cmpf(a.z,b.z);
    }
    
    template<typename T>
    constexpr inline Vec3<T> operator - (const Vec3<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return Vec3<T>{-v.x,
                       -v.y,
                       -v.z};
    }

    template<typename T, typename U>
    constexpr inline auto operator + (const Vec3<T>& a, const Vec3<U>& b)
    -> Vec3<decltype(a.x + b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);
        
        typedef decltype(a.x + b.x) type;

        return Vec3<type>{a.x + b.x,
                          a.y + b.y,
                          a.z + b.z};
    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator + (const Vec3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x + casted_scalar,
                       a.y + casted_scalar,
                       a.z + casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator + (const U scalar, const Vec3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x + casted_scalar,
                       a.y + casted_scalar,
                       a.z + casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator - (const Vec3<T>& a, const Vec3<U>& b)
    -> Vec3<decltype(a.x - b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x * b.x) type;

        return Vec3<type>{a.x - b.x,
                          a.y - b.y,
                          a.z - b.z};
    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator - (const Vec3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x - casted_scalar,
                       a.y - casted_scalar,
                       a.z - casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator - (const U scalar, const Vec3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x - casted_scalar,
                       a.y - casted_scalar,
                       a.z - casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator * (const Vec3<T>& a, const Vec3<U>& b)
    -> Vec3<decltype(a.x * b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x * b.x) type;

        return Vec3<type>{a.x * b.x,
                          a.y * b.y,
                          a.z * b.z};
    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator * (const Vec3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x * casted_scalar,
                       a.y * casted_scalar,
                       a.z * casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator * (const U scalar, const Vec3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x * casted_scalar,
                       a.y * casted_scalar,
                       a.z * casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator / (const Vec3<T>& a, const Vec3<U>& b)
    -> Vec3<decltype(a.x / b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x / b.x) type;

        return Vec3<type>{a.x / b.x,
                          a.y / b.y,
                          a.z / b.z};
    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator / (const Vec3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x / casted_scalar,
                       a.y / casted_scalar,
                       a.z / casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec3<T> operator / (const U scalar, const Vec3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec3<T>{a.x / casted_scalar,
                       a.y / casted_scalar,
                       a.z / casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline float Dot(Vec3<T>& a,Vec3<U>& b)
    {
        assert(std::is_arithmetic<T>::value && 
               std::is_arithmetic<U>::value);

        return a.x * static_cast<T>(b.x) + 
               a.y * static_cast<T>(b.y) +
               a.z * static_cast<T>(b.z);
    }

    template<typename T>
    constexpr inline float Mag(Vec3<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return sqrt(Dot(v,v));
    }
    
    template<typename T, typename U>
    constexpr inline auto Cross(Vec3<T>& a,Vec3<U>& b)
    -> Vec3<decltype(a.x * b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        return Vec3<T>{a.y * b.z - a.z * b.y, 
                       a.z * b.x - a.x * b.z,
                       a.x * b.y - a.y * b.x};
    }
}

#endif