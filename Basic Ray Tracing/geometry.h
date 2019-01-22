//
//  geometry.h
//  Basic Ray Tracing
//
//  Created by Эльдар Дамиров on 22.01.2019.
//  Copyright © 2019 Эльдар Дамиров. All rights reserved.
//

#ifndef geometry_h
#define geometry_h

//#define SECURE;

#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>



template <size_t dimensionNumber, typename typeOfData> struct gVector 
    {
    public:
        gVector()
            {
            for ( size_t currentDimension = dimensionNumber; currentDimension--; data [ currentDimension ] = typeOfData() );
            }
    
        typeOfData& operator[] ( const size_t dimensionId )
            {
            #ifdef SECURE
                assert ( dimensionId < dimensionNumber );
            #endif
            
            return data [ dimensionId ];
            }
            
        const typeOfData& operator[] ( const size_t dimensionId ) const
            {
            #ifdef SECURE
                assert ( dimensionId < dimensionNumber );
            #endif
            
            return data [ dimensionId ];
            }
    
    private:
        typeOfData data [ dimensionNumber ]{}; 

    };
    
using gVector2i = gVector<2, int>;
using gVector2f = gVector<2, double>;

using gVector3i = gVector <3, int>;
using gVector3f = gVector <3, double>;

using gVector4i = gVector <4, int>;
using gVector4f = gVector <4, double>;

#endif /* geometry_h */
