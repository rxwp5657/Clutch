//
//  vec4.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 09/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//
#ifndef VEC4_H 
#define VEC4_H

#include "commons.hpp"
#include "qualifier.hpp"

namespace clutch
{
    template <typename T>
    struct Vec4
    {
        union
        {
            struct{T x, y, z, w;};
            struct{T r, g, b, a;};
            typename Container<4,T>::container storage;
        };

        Vec4<T>()
        :x{0},
         y{0},
         z{0},
         w{0}
        {
        }

        Vec4<T>(const T v)
        :x{v},
         y{v},
         z{v},
         w{v}
        {
        }

        Vec4<T>(const T a, const T b, const T c, const T d)
        :x{a},
         y{b},
         z{c},
         w{d}
        {
        }

        Vec4<T>(const Vec4<T>& v)
        :x{v.x},
         y{v.y},
         z{v.z},
         w{v.w}
        {
        }

        Vec4<T>& operator=(const Vec4<T>& v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        }

        template<typename U>
        Vec4<T>& operator+=(const U scalar)
        {
            x += static_cast<T>(scalar);
            y += static_cast<T>(scalar);
            z += static_cast<T>(scalar);
            w += static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec4<T>& operator+=(const Vec4<U>& v)
        {
            x += static_cast<T>(v.x);
            y += static_cast<T>(v.y);
            z += static_cast<T>(v.z);
            w += static_cast<T>(v.w);
            
            return *this;
        }

        template<typename U>
        Vec4<T>& operator-=(const U scalar)
        {
            x -= static_cast<T>(scalar);
            y -= static_cast<T>(scalar);
            z -= static_cast<T>(scalar);
            w -= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec4<T>& operator-=(const Vec4<U>& v)
        {
            x -= static_cast<T>(v.x);
            y -= static_cast<T>(v.y);
            z -= static_cast<T>(v.z);
            w -= static_cast<T>(v.w);

            return *this;
        }

        template<typename U>
        Vec4<T>& operator*=(const U scalar)
        {
            x *= static_cast<T>(scalar);
            y *= static_cast<T>(scalar);
            z *= static_cast<T>(scalar);
            w *= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec4<T>& operator*=(const Vec4<U>& v)
        {
            x *= static_cast<T>(v.x);
            y *= static_cast<T>(v.y);
            z *= static_cast<T>(v.z);
            w *= static_cast<T>(v.w);

            return *this;
        }

        template<typename U>
        Vec4<T>& operator/=(const U scalar)
        {
            x /= static_cast<T>(scalar);
            y /= static_cast<T>(scalar);
            z /= static_cast<T>(scalar);
            w /= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec4<T>& operator/=(const Vec4<U>& v)
        {
            x /= static_cast<T>(v.x);
            y /= static_cast<T>(v.y);
            z /= static_cast<T>(v.z);
            w /= static_cast<T>(v.w);

            return *this;
        }

        Vec4<T>& operator++()
        {
            x += 1;
            y += 1;
            z += 1;
            w += 1;

            return *this;
        }

        Vec4<T>& operator++(int)
        {
            x += 1;
            y += 1;
            z += 1;
            w += 1;

            return *this;
        }

        Vec4<T>& operator--()
        {
            x -= 1;
            y -= 1;
            z -= 1;
            w -= 1;

            return *this;
        }

        Vec4<T>& operator--(int)
        {
            x -= 1;
            y -= 1;
            z -= 1;
            w -= 1;

            return *this;
        }
    };

    template<typename T>
    constexpr inline bool operator == (const Vec4<T>& a, const Vec4<T>& b)
    {
        assert(std::is_arithmetic<T>::value);

        return cmpf(a.x,b.x) && 
               cmpf(a.y,b.y) &&
               cmpf(a.z,b.z) &&
               cmpf(a.w,b.w); 
    }
    
    template<typename T>
    constexpr inline Vec4<T> operator - (const Vec4<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return Vec4<T>{-v.x,
                       -v.y,
                       -v.z,
                       -v.w};
    }

    template<typename T, typename U>
    constexpr inline auto operator + (const Vec4<T>& a, const Vec4<U>& b)
    -> Vec4<decltype(a.x + b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);
        
        typedef decltype(a.x + b.x) type;

        return Vec4<type>{a.x + b.x,
                          a.y + b.y,
                          a.z + b.z,
                          a.w + b.w};
    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator + (const Vec4<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x + casted_scalar,
                       a.y + casted_scalar,
                       a.z + casted_scalar,
                       a.w + casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator + (const U scalar, const Vec4<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x + casted_scalar,
                       a.y + casted_scalar,
                       a.z + casted_scalar,
                       a.w + casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator - (const Vec4<T>& a, const Vec4<U>& b)
    -> Vec4<decltype(a.x - b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x * b.x) type;

        return Vec4<type>{a.x - b.x,
                          a.y - b.y,
                          a.z - b.z,
                          a.w - b.w};
    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator - (const Vec4<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x - casted_scalar,
                       a.y - casted_scalar,
                       a.z - casted_scalar,
                       a.w - casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator - (const U scalar, const Vec4<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x - casted_scalar,
                       a.y - casted_scalar,
                       a.z - casted_scalar,
                       a.w - casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline auto operator * (const Vec4<T>& a, const Vec4<U>& b)
    -> Vec4<decltype(a.x * b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x * b.x) type;

        return Vec4<type>{a.x * b.x,
                          a.y * b.y,
                          a.z * b.z,
                          a.w * b.w};
    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator * (const Vec4<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x * casted_scalar,
                       a.y * casted_scalar,
                       a.z * casted_scalar,
                       a.w * casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator * (const U scalar, const Vec4<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x * casted_scalar,
                       a.y * casted_scalar,
                       a.z * casted_scalar,
                       a.w * casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator / (const Vec4<T>& a, const Vec4<U>& b)
    -> Vec4<decltype(a.x / b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x / b.x) type;

        return Vec4<type>{a.x / b.x,
                          a.y / b.y,
                          a.z / b.z,
                          a.w / b.w};
    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator / (const Vec4<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x / casted_scalar,
                       a.y / casted_scalar,
                       a.z / casted_scalar,
                       a.w / casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec4<T> operator / (const U scalar, const Vec4<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec4<T>{a.x / casted_scalar,
                       a.y / casted_scalar,
                       a.z / casted_scalar,
                       a.w / casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline float Dot(const Vec4<T>& a, const Vec4<U>& b)
    {
        assert(std::is_arithmetic<T>::value && 
               std::is_arithmetic<U>::value);

        return a.x * static_cast<T>(b.x) + 
               a.y * static_cast<T>(b.y) +
               a.z * static_cast<T>(b.z) + 
               a.w * static_cast<T>(b.w);
    }

    template<typename T>
    constexpr inline float Mag(const Vec4<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return sqrt(Dot(v,v));
    }

    template<typename T>
    constexpr inline Vec4<T> Normalize(const Vec4<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return Vec4<T>{v / Mag(v)};
    }
}

#endif