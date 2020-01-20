//
//  vec3.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 08/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//
#ifndef VEC2_H 
#define VEC2_H

#include "commons.hpp"
#include "qualifier.hpp"

namespace clutch
{
    /*
        SIMD Trick 1. 
            By defining a SSE register 
            inside a union type all variables
            share the same address space thus,
            no load_pd and set_pd is needed and,
            member access is easier.

        Warning of Trick 1.
            If all member variables share the same
            address, the struct should be aligned 
            for efficient loading and unloading otherwise
            there will be a performance impact
    */
    template<typename T>
    struct Vec2
    {
        union
        {
            struct{T x, y;};
            typename Container<2,T>::container storage;
        };

        Vec2<T>()
        :x{0},
         y{0}
        {
        }

        Vec2<T>(const T v)
        :x{v},
         y{v}
        {
        }

        Vec2<T>(const T a, const T b)
        : x{a},
          y{b}
        {
        }

        Vec2<T>(const Vec2<T>& v)
        : x{v.x},
          y{v.y}
        {
        }

        Vec2<T>& operator=(const Vec2<T>& v)
        {
            x = v.x;
            y = v.y;
            
            return *this;
        }

        /*
        Vec2<T>(const Vec2<T>&&);
        Vec2<T>& operator=(const Vec2<T>&&);
        */

       template<typename U>
        Vec2<T>& operator+=(const U scalar)
        {
            x += static_cast<T>(scalar);
            y += static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec2<T>& operator+=(const Vec2<U>& v)
        {
            x += static_cast<T>(v.x);
            y += static_cast<T>(v.y);
            
            return *this;
        }

        template<typename U>
        Vec2<T>& operator-=(const U scalar)
        {
            x -= static_cast<T>(scalar);
            y -= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec2<T>& operator-=(const Vec2<U>& v)
        {
            x -= static_cast<T>(v.x);
            y -= static_cast<T>(v.y);

            return *this;
        }

        template<typename U>
        Vec2<T>& operator*=(const U scalar)
        {
            x *= static_cast<T>(scalar);
            y *= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec2<T>& operator*=(const Vec2<U>& v)
        {
            x *= static_cast<T>(v.x);
            y *= static_cast<T>(v.y);

            return *this;
        }

        template<typename U>
        Vec2<T>& operator/=(const U scalar)
        {
            x /= static_cast<T>(scalar);
            y /= static_cast<T>(scalar);

            return *this;
        }

        template<typename U>
        Vec2<T>& operator/=(const Vec2<U>& v)
        {
            x /= static_cast<T>(v.x);
            y /= static_cast<T>(v.y);

            return *this;
        }

        Vec2<T>& operator++()
        {
            x += 1;
            y += 1;

            return *this;
        }

        Vec2<T>& operator++(int)
        {
            x += 1;
            y += 1;

            return *this;
        }

        Vec2<T>& operator--()
        {
            x -= 1;
            y -= 1;

            return *this;
        }

        Vec2<T>& operator--(int)
        {
            x -= 1;
            y -= 1;

            return *this;
        }

        #if defined(STORAGE_SSE)

        Vec2<double>(const __m128d v)
        : storage{v}
        {
        }
        
        template<typename U>
        Vec2<double>& operator+=(const Vec2<double>& v)
        {
            storage = _mm_add_pd(storage, v.storage);
            
            return *this;
        }

        template<typename U>
        Vec2<double>& operator-=(const Vec2<double>& v)
        {
            storage = _mm_sub_pd(storage, v.storage);
            return *this;
        }

        template<typename U>
        Vec2<double>& operator*=(const Vec2<double>& v)
        {
            storage = _mm_mul_pd(storage, v.storage);

            return *this;
        }

        template<typename U>
        Vec2<double>& operator/=(const Vec2<double>& v)
        {

            storage = _mm_div_pd(storage, v.storage);

            return *this;
        }

        #endif
    };

    template<typename T>
    constexpr inline bool operator == (const Vec2<T>& a, const Vec2<T>& b)
    {
        assert(std::is_arithmetic<T>::value);

        return cmpf(a.x,b.x) && 
               cmpf(a.y,b.y);
    }
    
    template<typename T>
    constexpr inline Vec2<T> operator - (const Vec2<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return Vec2<T>{-v.x,
                       -v.y};
    }

    template<typename T, typename U>
    constexpr inline auto operator + (const Vec2<T>& a, const Vec2<U>& b)
    -> Vec2<decltype(a.x + b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);
        
        typedef decltype(a.x + b.x) type;

        return Vec2<type>{a.x + b.x,
                          a.y + b.y};
    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator + (const Vec2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x + casted_scalar,
                       a.y + casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator + (const U scalar, const Vec2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x + casted_scalar,
                       a.y + casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator - (const Vec2<T>& a, const Vec2<U>& b)
    -> Vec2<decltype(a.x - b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x * b.x) type;

        return Vec2<type>{a.x - b.x,
                          a.y - b.y};
    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator - (const Vec2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x - casted_scalar,
                       a.y - casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator - (const U scalar, const Vec2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x - casted_scalar,
                       a.y - casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator * (const Vec2<T>& a, const Vec2<U>& b)
    -> Vec2<decltype(a.x * b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x * b.x) type;

        return Vec2<type>{a.x * b.x,
                          a.y * b.y};
    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator * (const Vec2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x * casted_scalar,
                       a.y * casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator * (const U scalar, const Vec2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x * casted_scalar,
                       a.y * casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline auto operator / (const Vec2<T>& a, const Vec2<U>& b)
    -> Vec2<decltype(a.x / b.x)>
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        typedef decltype(a.x / b.x) type;

        return Vec2<type>{a.x / b.x,
                          a.y / b.y};
    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator / (const Vec2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x / casted_scalar,
                       a.y / casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline Vec2<T> operator / (const U scalar, const Vec2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Vec2<T>{a.x / casted_scalar,
                       a.y / casted_scalar};

    }

    template<typename T, typename U>
    constexpr inline float Dot(const Vec2<T>& a, const Vec2<U>& b)
    {
        assert(std::is_arithmetic<T>::value && 
               std::is_arithmetic<U>::value);

        return a.x * static_cast<T>(b.x) + 
               a.y * static_cast<T>(b.y);
    }

    template<typename T>
    constexpr inline Vec2<T> Normalize(const Vec2<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return Vec2<T>{v / Mag(v)};
    }

    template<typename T>
    constexpr inline float Mag(const Vec2<T>& v)
    {
        assert(std::is_arithmetic<T>::value);

        return sqrt(Dot(v,v));
    }

    #if defined(STORAGE_SSE)

    inline bool operator == (const Vec2<double>& a, 
                             const Vec2<double>& b)
    {
        __m128d r = _mm_cmpeq_pd(a.storage, b.storage);
        u_int16_t res = _mm_movemask_pd(r);
        return res == 0xf;
    }

    inline Vec2<double> operator - (const Vec2<double>& v)
    {
        const double __attribute__((aligned(8))) neg{-1.0};
        return Vec2<double>{_mm_mul_pd(v.storage, _mm_load_pd1(&neg))};
    }

    inline Vec2<double> operator + (const Vec2<double>& a,const Vec2<double>& b)
    {
        return Vec2<double>{_mm_add_pd(a.storage, b.storage)};
    }

    inline Vec2<double> operator - (const Vec2<double>& a,const Vec2<double>& b)
    {
        return Vec2<double>{_mm_sub_pd(a.storage, b.storage)};
    }

    inline Vec2<double> operator * (const Vec2<double>& a,const Vec2<double>& b)
    {
        return Vec2<double>{_mm_mul_pd(a.storage, b.storage)};
    }

    inline Vec2<double> operator / (const Vec2<double>& a,const Vec2<double>& b)
    {
        return Vec2<double>{_mm_div_pd(a.storage, b.storage)};
    }

    inline float Dot (const Vec2<double>& a,const Vec2<double>& b)
    {
        __m128d temp = _mm_mul_pd(a.storage,b.storage);
        __m128d x = _mm_replicate_x_pd(temp);
        __m128d y = _mm_replicate_y_pd(temp);
        
        temp = _mm_add_pd(x,y);
        
        double result __attribute__((aligned(16)));
        
        _mm_store_sd(&result,temp);
        return result;
    }

    inline Vec2<double> Normalize(const Vec2<double>& v)
    {
        return Vec2<double>{_mm_div_pd(v.storage, _mm_set_pd1(Mag(v)))};
    }

    #endif
}

#endif