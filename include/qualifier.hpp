//
//  qualifier.hpp
//  Clutch
//
//  Created by Juan Carlos Sanchez Ruiz on 08/01/20.
//  Copyright © 2020 Juan Carlos Sanchez Ruiz. All rights reserved.
//

#ifndef QUALIFIERS_H
#define QUALIFIERS_H

#include "intrinsics.hpp"

namespace clutch
{
    /*
        In order to not delegate the responsibility of specifying 
        the SSE or container type to the user when instantiating
        (Vec2, Vec3 and Vec4), types are defined previously
        and "defined" during instantiation based on struct length
        and type (e.g Vec4<float>)
    */

    /*
        When SIMD are not defined, the container shall be 
        an array.
    */
    template<size_t N, typename T> struct Container
    {
        typedef struct alignas(N * sizeof(T)) container {
			T data[N];
		} container;
    };

    template<>
    struct alignas(16) Container<4, float>
    {   
        typedef __m128 container;
    };
    
    template<>
    struct Container<4, int>
    {   
        typedef __m128i container;
    };

    template<>
    struct Container<4, unsigned int>
    {   
        typedef __m128i container;
    };

    template<>
    struct alignas(16) Container<2, double>
    {   
        typedef __m128d container;
    };
}

#endif