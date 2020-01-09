//
//  intrinsics.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 08/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//

#ifndef INTRINSICS_H
#define INTRINSICS_H

#include <pmmintrin.h>
#include <xmmintrin.h> 
#include <cmath>

namespace gear {
    
    namespace math
    {
        //Common instinsic operations
        
        inline __m128 _mm_replicate_x_ps(const __m128 v)
        {
            __m128 result = _mm_shuffle_ps(v, v,_MM_SHUFFLE(0,0,0,0)); //replicate x value accross a SSE register.
            return result;
        }
        
        inline __m128 _mm_replicate_y_ps(const __m128 v)
        {
            __m128 result = _mm_shuffle_ps(v, v,_MM_SHUFFLE(1,1,1,1)); //replicate y value accross a SSE register.
            return result;
        }
        
        inline __m128 _mm_replicate_z_ps(const __m128 v)
        {
            __m128 result = _mm_shuffle_ps(v, v,_MM_SHUFFLE(2,2,2,2)); //replicate z value accross a SSE register.
            return result;
        }
        
        inline __m128 _mm_replicate_w_ps(const __m128 v)
        {
            __m128 result = _mm_shuffle_ps(v, v,_MM_SHUFFLE(3,3,3,3)); //replicate w value accross a SSE register.
            return result;
        }
        
        inline __m128 _mm_madd_ps(const __m128 a, const __m128 b, const __m128 c)
        { //multiply vectors a , b and add the result to c.
            return _mm_add_ps(_mm_mul_ps(a,b),c);
        }
    }
}

#endif /* INTRINSICS_H */