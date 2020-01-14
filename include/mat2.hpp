//
//  mat4.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 13/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//
#ifndef MAT2_H 
#define MAT2_H

#include <assert.h>
#include <iostream>
#include "commons.hpp"
#include "qualifier.hpp"
#include "vec2.hpp"

namespace clutch
{   
    template <typename T>
    struct Mat2
    {
        Vec2<T> columns[2];

        Mat2()
        :columns{Vec2<T>{1,0}, 
                 Vec2<T>{0,1}}
        {
        }

        Mat2(const T x0, const T y0,
             const T x1, const T y1)        
        :columns{Vec2<T>{x0,x1}, 
                 Vec2<T>{y0,y1}}
        {
        }

        Mat2(const Vec2<T>& c0, 
             const Vec2<T>& c1)
        :columns{c0,c1}
        {
        }        

        Mat2<T>& operator=(const Mat2<T>& m)
        {
            columns[0] = m.columns[0];
            columns[1] = m.columns[1];

            return *this;
        }
        
        Mat2<T>& operator+=(const Mat2<T>& m)
        {
            columns[0] += m.columns[0];
            columns[1] += m.columns[1];

            return *this;
        }

        Mat2<T>& operator-=(const Mat2<T>& m)
        {
            columns[0] -= m.columns[0];
            columns[1] -= m.columns[1];

            return *this;
        }

        Mat2<T>& operator*=(const Mat2<T>& m)
        {
            auto a = (*this) * m.columns[0];
            auto b = (*this) * m.columns[1];
            
            columns[0] = a;
            columns[1] = b;

            return *this;
        }

        Vec2<T> operator[](const unsigned int i)
        {
            assert(i < 2);
            return columns[i];
        }

        T get(const unsigned int i, const unsigned int j) const
        {
            assert(i < 2 && j < 2);
            switch (i)
            {
            case 0:
                return columns[j].x;
                break;
            default:
                return columns[j].y;
                break;
            }
        }
    };

    #if defined(STORAGE_SSE)

    inline Vec2<double> operator * (const Mat2<double>& m, const Vec2<double>& v)
    {   
        __m128 result = _mm_mul_pd(_mm_replicate_x_pd(v.storage),m.columns[0].storage);
        result = _mm_madd_pd(_mm_replicate_y_pd(v.storage),m.columns[1].storage,result);
        return Vec2<double>(result);
    }

    inline Mat2<double> Transpose(const Mat2<double>& m)
    {
        __m128d r0, r1;
        r0 = _mm_shuffle_pd(m.columns[0].storage, m.columns[1].storage,_MM_SHUFFLE2(0, 0)); 
        r1 = _mm_shuffle_pd(m.columns[0].storage, m.columns[1].storage,_MM_SHUFFLE2(1, 1)); 
        return Mat2<double>{r0, r1};
    }

    #endif

    template<typename T>
    constexpr inline bool operator == (const Mat2<T>& a, const Mat2<T>& b)
    {
        assert(std::is_arithmetic<T>::value);

        return a.columns[0] == b.columns[0] &&
               a.columns[1] == b.columns[1];
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator + (const Mat2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] + casted_scalar,
                       a.columns[1] + casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator + (const U scalar, const Mat2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] + casted_scalar,
                       a.columns[1] + casted_scalar};
    }

    template <typename T>
    constexpr inline Mat2<T> operator+(const Mat2<T>& a, const Mat2<T>& b)
    {
        return Mat2<T>{a.columns[0] + b.columns[0], 
                       a.columns[1] + b.columns[1]};
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator - (const Mat2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] - casted_scalar,
                       a.columns[1] - casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator - (const U scalar, const Mat2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] - casted_scalar,
                       a.columns[1] - casted_scalar};
    }
    
    template <typename T>
    constexpr inline Mat2<T> operator-(const Mat2<T>& a, const Mat2<T>& b)
    {
        return Mat2<T>{a.columns[0] - b.columns[0], 
                       a.columns[1] - b.columns[1]};
    }

    template <typename T, typename U>
    constexpr inline auto operator*(const Mat2<T>& m, const Vec2<U>& v)
    -> Vec2<decltype(m.columns[0].x * v.x)>
    {
        return m.columns[0] * v.x + m.columns[1] * v.y;
    }

    template <typename T, typename U>
    constexpr inline auto operator*(const Mat2<T>& a, const Mat2<U>& b)
    -> Mat2<decltype(a.columns[0].x * b.columns[0].x)>
    {
        return Mat2<decltype(a.columns[0].x * b.columns[0].x)>
        {a * b.columns[0], a * b.columns[1]};
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator * (const Mat2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] * casted_scalar,
                       a.columns[1] * casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator * (const U scalar, const Mat2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] * casted_scalar,
                       a.columns[1] * casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator / (const Mat2<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] / casted_scalar,
                       a.columns[1] / casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat2<T> operator / (const U scalar, const Mat2<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat2<T>{a.columns[0] / casted_scalar,
                       a.columns[1] / casted_scalar};
    }

    template <typename T>
    constexpr inline Mat2<T> Transpose(const Mat2<T>& m)
    {
        T results[4]{};
        int k = 0;
        for(auto i = 0; i < 2; i++)
            for(auto j = 0; j < 2; j++)
            {
                results[k] = m.get(j,i);
                k++;
            }
        return Mat2<T>{results[0],results[1],
                       results[2],results[3]};
    }

    template<typename T>
    auto Determinant(const Mat2<T>& m)
    {
        return m.columns[0].x * m.columns[1].y - m.columns[1].x * m.columns[0].y;
    }

    template<typename T>
    Mat2<T> Inverse(const Mat2<T>& m)
    {
        auto determinant = Determinant(m);
        assert(determinant != 0);
        auto inv_d  = 1.0f / Determinant(m);

        return Mat2<T>{m.columns[1].y * inv_d,-m.columns[1].x * inv_d, 
                      -m.columns[0].y * inv_d, m.columns[0].x * inv_d};
    }
}

#endif