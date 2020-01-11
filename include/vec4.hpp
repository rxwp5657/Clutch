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

        #if defined(STORAGE_SSE)

        Vec4<float> (const __m128 v)
        :storage{v}
        {
        } 

        Vec4<float>& operator+=(const Vec4<float>& v)
        {
            storage = _mm_add_ps(storage, v.storage);
            return *this;
        }

        Vec4<float>& operator-=(const Vec4<float>& v)
        {
            storage = _mm_sub_ps(storage, v.storage);
            return *this;
        }

        Vec4<float>& operator*=(const Vec4<float>& v)
        {
            storage = _mm_mul_ps(storage, v.storage);
            return *this;
        }

        Vec4<float>& operator/=(const Vec4<float>& v)
        {
            storage = _mm_div_ps(storage, v.storage);
            return *this;
        }

        #endif
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

    #if defined(STORAGE_SSE)

    inline bool operator == (const Vec4<float>& a, 
                             const Vec4<float>& b)
    {
        __m128 r = _mm_cmpeq_ps(a.storage, b.storage);

        u_int16_t res = _mm_movemask_ps(r);

        return res == 0xf;
    }

    inline auto operator + (const Vec4<float>& a, const Vec4<float>& b)
    {
        return Vec4<float>{_mm_add_ps(a.storage, b.storage)};
    }

    inline auto operator - (const Vec4<float>& a, const Vec4<float>& b)
    {
        return  Vec4<float> {_mm_sub_ps(a.storage, b.storage)};
    }

    inline auto operator * (const  Vec4<float>& v, const float s)
    {
        return  Vec4<float>{_mm_mul_ps(v.storage, _mm_load_ps1(&s))};
    }

    inline auto operator / (const Vec4<float>& v, const float s)
    {
        return Vec4<float>{_mm_div_ps(v.storage, _mm_load_ps1(&s))};
    }

    inline auto Neg(const Vec4<float>& v)
    {
        float neg = -1.0;
        return Vec4<float>{_mm_mul_ps(v.storage, _mm_load_ps1(&neg))};
    }

    inline float Dot(const Vec4<float>& a, const Vec4<float>& b)
    {
        __m128 temp = _mm_mul_ps(a.storage,b.storage);
        __m128 x = _mm_replicate_x_ps(temp);
        __m128 y = _mm_replicate_y_ps(temp);
        __m128 z = _mm_replicate_z_ps(temp);
        __m128 w = _mm_replicate_w_ps(temp);
        
        temp = _mm_add_ps(x,y);
        temp = _mm_add_ps(temp,z);
        temp = _mm_add_ps(temp,w);
        
        float result __attribute__((aligned(16)));
        
        _mm_store_ss(&result,temp);
        
        return result;
    }

    inline auto Cross(const Vec4<float>& a, const Vec4<float>& b)
    {
        __m128 a_yzx = _mm_shuffle_ps(a.storage, a.storage, _MM_SHUFFLE(3, 0, 2, 1));
        __m128 b_yzx = _mm_shuffle_ps(b.storage, b.storage, _MM_SHUFFLE(3, 0, 2, 1));
        __m128 c = _mm_sub_ps(_mm_mul_ps(a.storage, b_yzx), _mm_mul_ps(a_yzx, b.storage));
        return Vec4<float>{_mm_shuffle_ps(c, c, _MM_SHUFFLE(3, 0, 2, 1))};
    }

    inline auto Mag(const Vec4<float>& v)
    {
        return sqrt(Dot(v,v));
    }

    inline auto Normalize(const Vec4<float>& v)
    {
        return Vec4<float>{_mm_div_ps(v.storage, _mm_set1_ps(Mag(v)))};
    }
    
    #endif
}

#endif