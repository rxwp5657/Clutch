//
//  mat4.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 11/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//
#ifndef MAT3_H 
#define MAT3_H

#include <assert.h>
#include "commons.hpp"
#include "qualifier.hpp"
#include "mat2.hpp"
#include "vec3.hpp"

namespace clutch
{
    template <typename T>
    struct Mat3
    {
        Vec3<T> columns[3];

        Mat3()
        :columns{Vec3<T>{1,0,0}, 
                 Vec3<T>{0,1,0}, 
                 Vec3<T>{0,0,1}}
        {
        }

        Mat3(const T x0, const T y0, const T z0,
             const T x1, const T y1, const T z1, 
             const T x2, const T y2, const T z2)
        :columns{Vec3<T>{x0,x1,x2}, 
                 Vec3<T>{y0,y1,y2}, 
                 Vec3<T>{z0,z1,z2}}
        {
        }
        
        Mat3(const Vec3<T>& c0, 
             const Vec3<T>& c1, 
             const Vec3<T>& c2)
        :columns{c0,c1,c2}
        {
        }
        
        Mat3<T>& operator=(const Mat3<T>& m)
        {
            columns[0] = m.columns[0];
            columns[1] = m.columns[1];
            columns[2] = m.columns[2];

            return *this;
        }
        
        Mat3<T>& operator+=(const Mat3<T>& m)
        {
            columns[0] += m.columns[0];
            columns[1] += m.columns[1];
            columns[2] += m.columns[2];

            return *this;
        }

        Mat3<T>& operator-=(const Mat3<T>& m)
        {
            columns[0] -= m.columns[0];
            columns[1] -= m.columns[1];
            columns[2] -= m.columns[2];

            return *this;
        }

        Mat3<T>& operator*=(const Mat3<T>& m)
        {
            auto a = (*this) * m.columns[0];
            auto b = (*this) * m.columns[1];
            auto c = (*this) * m.columns[2];
            
            columns[0] = a;
            columns[1] = b;
            columns[2] = c;

            return *this;
        }

        Vec3<T> operator[](const unsigned int i)
        {
            assert(i < 3);
            return columns[i];
        }

        T get(const unsigned int i, const unsigned int j) const
        {
            assert(i < 3 && j < 3);
            switch (i)
            {
            case 0:
                return columns[j].x;
                break;
            case 1:
                return columns[j].y;
                break;
            default:
                return columns[j].z;
                break;
            }
        }

        Mat2<T> submatrix(const unsigned int i, const unsigned int j) const
        {
            T results[4]{};
            int acc{0};

            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    if(k != i && l != j)
                    {
                        results[acc] = (*this).get(k,l);
                        acc++;
                    }
                }
            }
            return Mat2<T>{results[0],results[1],
                           results[2],results[3]};
        }
    };

    template<typename T>
    constexpr inline bool operator == (const Mat3<T>& a, const Mat3<T>& b)
    {
        assert(std::is_arithmetic<T>::value);

        return a.columns[0] == b.columns[0] &&
               a.columns[1] == b.columns[1] &&
               a.columns[2] == b.columns[2];
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator + (const Mat3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] + casted_scalar,
                       a.columns[1] + casted_scalar,
                       a.columns[2] + casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator + (const U scalar, const Mat3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] + casted_scalar,
                       a.columns[1] + casted_scalar,
                       a.columns[2] + casted_scalar};
    }

    template <typename T>
    constexpr inline Mat3<T> operator+(const Mat3<T>& a, const Mat3<T>& b)
    {
        return Mat3<T>{a.columns[0] + b.columns[0], 
                       a.columns[1] + b.columns[1], 
                       a.columns[2] + b.columns[2]};
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator - (const Mat3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] - casted_scalar,
                       a.columns[1] - casted_scalar,
                       a.columns[2] - casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator - (const U scalar, const Mat3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] - casted_scalar,
                       a.columns[1] - casted_scalar,
                       a.columns[2] - casted_scalar};
    }
    
    template <typename T>
    constexpr inline Mat3<T> operator-(const Mat3<T>& a, const Mat3<T>& b)
    {
        return Mat3<T>{a.columns[0] - b.columns[0], 
                       a.columns[1] - b.columns[1], 
                       a.columns[2] - b.columns[2]};
    }

    template <typename T, typename U>
    constexpr inline auto operator*(const Mat3<T>& m, const Vec3<U>& v)
    -> Vec3<decltype(m.columns[0].x * v.x)>
    {
        return m.columns[0] * v.x + m.columns[1] * v.y + m.columns[2] * v.z;
    }

    template <typename T, typename U>
    constexpr inline auto operator*(const Mat3<T>& a, const Mat3<U>& b)
    -> Mat3<decltype(a.columns[0].x * b.columns[0].x)>
    {
        return Mat3<decltype(a.columns[0].x * b.columns[0].x)>
        {a * b.columns[0], a * b.columns[1], a * b.columns[2]};
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator * (const Mat3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] * casted_scalar,
                       a.columns[1] * casted_scalar,
                       a.columns[2] * casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator * (const U scalar, const Mat3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] * casted_scalar,
                       a.columns[1] * casted_scalar,
                       a.columns[2] * casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator / (const Mat3<T>& a, const U scalar)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] / casted_scalar,
                       a.columns[1] / casted_scalar,
                       a.columns[2] / casted_scalar};
    }

    template<typename T, typename U>
    constexpr inline Mat3<T> operator / (const U scalar, const Mat3<T>& a)
    {
        assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value);

        auto casted_scalar = static_cast<T>(scalar);

        return Mat3<T>{a.columns[0] / casted_scalar,
                       a.columns[1] / casted_scalar,
                       a.columns[2] / casted_scalar};
    }

    template <typename T>
    constexpr inline Mat3<T> Transpose(const Mat3<T>& m)
    {
        T results[9]{};
        int k = 0;
        for(auto i = 0; i < 3; i++)
            for(auto j = 0; j < 3; j++)
            {
                results[k] = m.get(j,i);
                k++;
            }
        return Mat3<T>{results[0],results[1],results[2],
                       results[3],results[4],results[5],
                       results[6],results[7],results[8]};
    }

    template<typename T>
    auto Determinant(const Mat3<T>& m)
    {
        const Vec3<T> a = m.columns[0];
        const Vec3<T> b = m.columns[1];
        const Vec3<T> c = m.columns[2];
        
        auto a1 = a.x * b.y * c.z;
        auto a2 = b.x * c.y * a.z;
        auto a3 = c.x * a.y * b.z;

        auto b1 = a.z * b.y * c.x;
        auto b2 = b.z * c.y * a.x;
        auto b3 = c.z * a.y * b.x;

        return a1 + a2 + a3 - b1 - b2 - b3; 
    }

    template<typename T>
    Mat3<T> Inverse(const Mat3<T>& m)
    {
        auto determinant = Determinant(m);
        auto transposed  = Transpose(m);
        assert(determinant != 0);

        Mat3<T> cofactor{Determinant(transposed.submatrix(0,0)),-Determinant(transposed.submatrix(0,1)),Determinant(transposed.submatrix(0,2)), 
                        -Determinant(transposed.submatrix(1,0)),Determinant(transposed.submatrix(1,1)),-Determinant(transposed.submatrix(1,2)),
                         Determinant(transposed.submatrix(2,0)),-Determinant(transposed.submatrix(2,1)),Determinant(transposed.submatrix(2,2))};

        return (1.0f / determinant) * cofactor;
    }
}

#endif