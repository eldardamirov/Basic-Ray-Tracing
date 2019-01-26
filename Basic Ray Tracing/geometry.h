//
//  geometry.h
//  Basic Ray Tracing
//
//  Created by Эльдар Дамиров on 22.01.2019.
//  Copyright © 2019 Эльдар Дамиров. All rights reserved.
//

#ifndef geometry_h
#define geometry_h


//#define SECURE;   // in case of fire; 🔥

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
    
//------------- Predeclared typenames -------------
    
using gVector2i = gVector<2, int>;
using gVector2f = gVector<2, double>;

using gVector3i = gVector <3, int>;
using gVector3f = gVector <3, double>;

using gVector4i = gVector <4, int>;
using gVector4f = gVector <4, double>;

//-------------------------------------------------

template <typename typeOfData> struct gVector <2, typeOfData>
    {
    public:
        gVector(): x ( typeOfData() ), y ( typeOfData() )
            {
            }
            
        gVector ( typeOfData x, typeOfData y ): x ( x ), y ( y )
            {
            }
        
        typeOfData x, y;
        
        typeOfData& operator[] ( const size_t dimensionId )
            {
            #ifdef SECURE
                assert ( dimensionId < dimensionNumber );
            #endif
            
            return ( dimensionId == 0 )? x : y;
            }
            
        const typeOfData& operator[] ( const size_t dimensionId ) const
            {
            #ifdef SECURE
                assert ( dimensionId < dimensionNumber );
            #endif
            
            return ( dimensionId == 0 )? x : y;
            }
            
    private:
        const int dimensionNumber = 2;
    
    };
    
    
template <typename typeOfData> struct gVector <3, typeOfData>
    {
    public:
        gVector(): x ( typeOfData() ), y ( typeOfData() ), z ( typeOfData() )
            {
            }
            
        gVector ( typeOfData x, typeOfData y, typeOfData z ): x ( x ), y ( y ), z ( z )
            {
            }
        
        typeOfData x, y, z;
        
        typeOfData& operator[] ( const size_t dimensionId )
            {
            #ifdef SECURE
                assert ( dimensionId < dimensionNumber );
            #endif
            
            return ( dimensionId == 0 )? x : ( ( dimensionId == 1 )? y : z );
            }
            
        const typeOfData& operator[] ( const size_t dimensionId ) const
            {
            #ifdef SECURE
                assert ( dimensionId < dimensionNumber );
            #endif
            
            return ( dimensionId == 0 )? x : ( ( dimensionId == 1 )? y : z );
            }
            
        double normal()
            {
            return std::sqrt ( ( x * x ) + ( y * y ) + ( z * z ) );
            }
            
        gVector <3, typeOfData>& normalize ( typeOfData length = 1 ) 
            {
            *this = ( *this ) * ( length / normal() );
            return *this;
            }
            
    private:
        const int dimensionNumber = 3;
    
    };




#endif /* geometry_h */
