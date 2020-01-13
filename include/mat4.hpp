//
//  mat4.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 11/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//
#ifndef MAT4_H 
#define MAT4_H

#include <assert.h>
#include "commons.hpp"
#include "qualifier.hpp"
#include "vec4.hpp"

namespace clutch
{
    template <typename T>
    struct Mat4
    {
        Vec4<T> columns[4];

        Mat4()
        :columns{Vec4<T>{1,0,0,0}, 
                 Vec4<T>{0,1,0,0}, 
                 Vec4<T>{0,0,1,0},
                 Vec4<T>{0,0,0,1}}
        {
        }

        Mat4(const T x0, const T y0, const T z0, const T w0,
             const T x1, const T y1, const T z1, const T w1, 
             const T x2, const T y2, const T z2, const T w2, 
             const T x3, const T y3, const T z3, const T w3)
        :columns{Vec4<T>{x0,y0,z0,w0}, 
                 Vec4<T>{x1,y1,z1,w1}, 
                 Vec4<T>{x2,y2,z2,w2},
                 Vec4<T>{x3,y3,z3,w3}}
        {
        }
        
        Mat4(const Vec4<T>& c0, 
             const Vec4<T>& c1, 
             const Vec4<T>& c2, 
             const Vec4<T>& c3)
        :columns{c0,c1,c2,c3}
        {
        }
        
        Mat4<T>& operator=(const Mat4<T>& m)
        {
            columns[0] = m.r0;
            columns[1] = m.r1;
            columns[2] = m.r2;
            columns[3] = m.r3;
        }
        
        Mat4<T>& operator+=(const Mat4<T>& m)
        {
            columns[0] += m.r0;
            columns[1] += m.r1;
            columns[2] += m.r2;
            columns[3] += m.r3;
        }

        Mat4<T>& operator-=(const Mat4<T>& m)
        {
            columns[0] -= m.r0;
            columns[1] -= m.r1;
            columns[2] -= m.r2;
            columns[3] -= m.r3;
        }

        Mat4<T>& operator*=(const Mat4<T>& m)
        {
            columns[0] = columns[0] * m.r0.x + columns[1] * m.r0.y + columns[2] * m.r0.z + columns[3] *  m.r0.w;
            columns[1] = columns[0] * m.r1.x + columns[1] * m.r1.y + columns[2] * m.r1.z + columns[3] *  m.r1.w;
            columns[2] = columns[0] * m.r2.x + columns[1] * m.r2.y + columns[2] * m.r2.z + columns[3] *  m.r2.w;
            columns[3] = columns[0] * m.r3.x + columns[1] * m.r3.y + columns[2] * m.r3.z + columns[3] *  m.r3.w;
        }

        Vec4<T> operator[](const unsigned int i)
        {
            assert(i < 4);
            return columns[i];
        }

        T get(const unsigned int i, const unsigned int j) const
        {
            assert(i < 4 && j < 4);
            switch (j)
            {
            case 0:
                return columns[i].x;
                break;
            case 1:
                return columns[i].y;
                break;
            case 2:
                return columns[i].z;
                break;
            default:
                return columns[i].w;
                break;
            }
        }

    };

    template<typename T>
    constexpr inline bool operator == (const Mat4<T>& a, const Mat4<T>& b)
    {
        assert(std::is_arithmetic<T>::value);

        return a.columns[0] == b.columns[0] &&
               a.columns[1] == b.columns[1] &&
               a.columns[2] == b.columns[2] &&
               a.columns[3] == b.columns[3];
    }

    template <typename T>
    constexpr inline Mat4<T> operator+(const Mat4<T>& a, const Mat4<T>& b)
    {
        return Mat4<T>{a.columns[0] + b.columns[0], 
                       a.columns[1] + b.columns[1], 
                       a.columns[2] + b.columns[2],
                       a.columns[3] + b.columns[3]};
    }
    
    template <typename T>
    constexpr inline Mat4<T> operator-(const Mat4<T>& a, const Mat4<T>& b)
    {
        return Mat4<T>{a.columns[0] - b.columns[0], 
                       a.columns[1] - b.columns[1], 
                       a.columns[2] - b.columns[2],
                       a.columns[3] - b.columns[3]};
    }

    template <typename T, typename U>
    constexpr inline auto operator*(const Mat4<T>& m, const Vec4<U>& v)
    -> Vec4<decltype(m.columns[0].x * v.x)>
    {
        return m.columns[0] * v.x + m.columns[1] * v.y + m.columns[2] * v.z + m.columns[3] * v.w;
    }

    template <typename T, typename U>
    constexpr inline auto operator*(const Mat4<T>& a, const Mat4<U>& b)
    -> Mat4<decltype(a.columns[0].x * b.columns[0].x)>
    {
        return Mat4<decltype(a.columns[0].x * b.columns[0].x)>
        {a * b.columns[0], a * b.columns[1], a * b.columns[2], a * b.columns[3]};
    }

    #if defined(STORAGE_SSE)

    inline Vec4<float> operator * (const Mat4<float>& m, const Vec4<float>& v)
    {
        __m128 result = _mm_mul_ps(_mm_replicate_x_ps(v.storage),m.columns[0].storage);
        result = _mm_madd_ps(_mm_replicate_y_ps(v.storage),m.columns[1].storage,result);
        result = _mm_madd_ps(_mm_replicate_z_ps(v.storage),m.columns[2].storage,result);
        result = _mm_madd_ps(_mm_replicate_w_ps(v.storage),m.columns[3].storage,result);
        return Vec4<float>(result);
    }

    inline Mat4<float> Transpose(const Mat4<float>& m)
    {
        __m128 tmp0, tmp1, tmp2, tmp3, r0, r1, r2, r3;
        
        // x0, y0, x1, y1
        tmp0 = _mm_shuffle_ps(m.columns[0].storage, m.columns[1].storage,_MM_SHUFFLE(1, 0, 1, 0)); 
        
        // z0, w0, z1, w1
        tmp1 = _mm_shuffle_ps(m.columns[0].storage, m.columns[1].storage,_MM_SHUFFLE(3, 2, 3, 2)); 
        
        // x2, y2, x3, y3 
        tmp2 = _mm_shuffle_ps(m.columns[2].storage, m.columns[3].storage,_MM_SHUFFLE(1, 0, 1, 0));
        
        // z2, w2, z3, w3 
        tmp3 = _mm_shuffle_ps(m.columns[2].storage, m.columns[3].storage,_MM_SHUFFLE(3, 2, 3, 2));
        
        r0 = _mm_shuffle_ps(tmp0, tmp2, _MM_SHUFFLE(2, 0, 2, 0));
        r1 = _mm_shuffle_ps(tmp0, tmp2, _MM_SHUFFLE(3, 1, 3, 1));
        r2 = _mm_shuffle_ps(tmp1, tmp3, _MM_SHUFFLE(2, 0, 2, 0));
        r3 = _mm_shuffle_ps(tmp1, tmp3, _MM_SHUFFLE(3, 1, 3, 1));

        return Mat4<float>{r0, r1, r2, r3};
    }

    #endif

    template <typename T>
    constexpr inline Mat4<T> Transpose(const Mat4<T>& m)
    {
        T results[16]{};
        int k = 0;
        for(auto i = 0; i < 4; i++)
            for(auto j = 0; j < 4; j++)
            {
                results[k] = m.get(j,i);
                k++;
            }
        return Mat4<T>{results[0],results[1],results[2],results[3],
                       results[4],results[5],results[6],results[7],
                       results[8],results[9],results[10],results[11],
                       results[12],results[13],results[14],results[15]};
    }

    template<typename T>
    auto Determinant(const Mat4<T>& m)
    {
        const Vec4<T> a = m.columns[0];
        const Vec4<T> b = m.columns[1];
        const Vec4<T> c = m.columns[2];
        const Vec4<T> d = m.columns[3];
        
        const float x = m.get(0,3);
        const float y = m.get(1,3);
        const float z = m.get(2,3);
        const float w = m.get(3,3);

        Vec4<T> s = Cross(a,b);
        Vec4<T> t = Cross(c,d);
        Vec4<T> u = (a * y) - (b * x);
        Vec4<T> v = (c * w) - (d * z);

        return Dot(s,v) + Dot(t,u); 
    }

    template<typename T>
    auto Inverse(const Mat4<T>& m)
    {
        const Vec4<T> a = m.columns[0];
        const Vec4<T> b = m.columns[1];
        const Vec4<T> c = m.columns[2];
        const Vec4<T> d = m.columns[3];
        
        const float x = m.get(0,3);
        const float y = m.get(1,3);
        const float z = m.get(2,3);
        const float w = m.get(3,3);

        Vec4<T> s = Cross(a,b);
        Vec4<T> t = Cross(c,d);
        Vec4<T> u = (a * y) - (b * x);
        Vec4<T> v = (c * w) - (d * z);

        float invDet = 1.0 / (Dot(s,v) + Dot(t,u));

        s *= invDet;
        t *= invDet;
        u *= invDet;
        v *= invDet;

        Vec4<T> rv0 = Cross(b,v) + (t * y);
        Vec4<T> rv1 = Cross(v,a) - (t * x);
        Vec4<T> rv2 = Cross(d,u) + (s * w);
        Vec4<T> rv3 = Cross(u,c) - (s * z);

        rv0.w = -Dot(b,t);
        rv1.w =  Dot(a,t);
        rv2.w = -Dot(d,s);
        rv3.w =  Dot(c,s);
        
        return Mat4<T>{rv0.x, rv1.x, rv2.x, rv3.x, 
                       rv0.y, rv1.y, rv2.y, rv3.y, 
                       rv0.z, rv1.z, rv2.z, rv3.z, 
                       rv0.w, rv1.w, rv2.w, rv3.w};
    }

}

#endif