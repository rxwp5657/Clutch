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