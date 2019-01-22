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

#endif /* geometry_h */
