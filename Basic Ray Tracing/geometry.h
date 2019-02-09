////
////  geometry.h
////  Basic Ray Tracing
////
////  Created by Эльдар Дамиров on 22.01.2019.
////  Copyright © 2019 Эльдар Дамиров. All rights reserved.
////
//
//#ifndef geometry_h
//#define geometry_h
//
//
////#define SECURE;   // in case of fire; 🔥
//
//#include <cmath>
//#include <vector>
//#include <cassert>
//#include <iostream>
//
//
//template <size_t dimensionNumber, typename typeOfData> struct gVector 
//    {
//    public:
//        gVector()
//            {
//            for ( size_t currentDimension = dimensionNumber; currentDimension--; data [ currentDimension ] = typeOfData() );
//            }
//    
//        typeOfData& operator[] ( const size_t dimensionId )
//            {
//            #ifdef SECURE
//                assert ( dimensionId < dimensionNumber );
//            #endif
//            
//            return data [ dimensionId ];
//            }
//            
//        const typeOfData& operator[] ( const size_t dimensionId ) const
//            {
//            #ifdef SECURE
//                assert ( dimensionId < dimensionNumber );
//            #endif
//            
//            return data [ dimensionId ];
//            }
//            
////        gVector <dimensionNumber, typeOfData>& operator = ( const gVector <dimensionNumber, typeOfData>& rhs )
////            {
////            return *this;
////            }
//         gVector <dimensionNumber, typeOfData>& operator = ( const gVector <dimensionNumber, typeOfData>& rhs )
//            {
//            for ( size_t i = 0; i < dimensionNumber; ( *this [ i ] = rhs [ i ] ) );
//            
//            return *this;
//            }
//        
//    private:
//        typeOfData data [ dimensionNumber ]{}; 
//
//    };
//    
////------------- Predeclared typenames -------------
//    
//using gVector2i = gVector <2, int>;
//using gVector2f = gVector <2, double>;
//
//using gVector3i = gVector <3, int>;
//using gVector3f = gVector <3, double>;
//
//using gVector4i = gVector <4, int>;
//using gVector4f = gVector <4, double>;
//
////-------------------------------------------------
//
//template <typename typeOfData> struct gVector <2, typeOfData>
//    {
//    public:
//        gVector(): x ( typeOfData() ), y ( typeOfData() )
//            {
//            }
//            
//        gVector ( typeOfData x, typeOfData y ): x ( x ), y ( y )
//            {
//            }
//        
//        typeOfData x, y;
//        
//        typeOfData& operator [] ( const size_t dimensionId )
//            {
//            #ifdef SECURE
//                assert ( dimensionId < dimensionNumber );
//            #endif
//            
//            return ( dimensionId == 0 )? x : y;
//            }
//            
//        const typeOfData& operator [] ( const size_t dimensionId ) const
//            {
//            #ifdef SECURE
//                assert ( dimensionId < dimensionNumber );
//            #endif
//            
//            return ( dimensionId == 0 )? x : y;
//            }
//            
//    private:
//        const int dimensionNumber = 2;
//    
//    };
//    
//    
//template <typename typeOfData> struct gVector <3, typeOfData>
//    {
//    public:
//        gVector(): x ( typeOfData() ), y ( typeOfData() ), z ( typeOfData() )
//            {
//            }
//            
//        gVector ( typeOfData x, typeOfData y, typeOfData z ): x ( x ), y ( y ), z ( z )
//            {
//            }
//        
//        typeOfData x, y, z;
//        
//        typeOfData& operator [] ( const size_t dimensionId )
//            {
//            #ifdef SECURE
//                assert ( dimensionId < dimensionNumber );
//            #endif
//            
//            return ( dimensionId == 0 )? x : ( ( dimensionId == 1 )? y : z );
//            }
//            
//        const typeOfData& operator [] ( const size_t dimensionId ) const
//            {
//            #ifdef SECURE
//                assert ( dimensionId < dimensionNumber );
//            #endif
//            
//            return ( dimensionId == 0 )? x : ( ( dimensionId == 1 )? y : z );
//            }
//            
//        double normal()
//            {
//            return std::sqrt ( ( x * x ) + ( y * y ) + ( z * z ) );
//            }
//            
//        gVector <3, typeOfData>& normalize ( typeOfData length = 1 ) 
//            {
//            *this = ( *this ) * ( length / normal() );
//            return *this;
//            }
//            
//    private:
//        const int dimensionNumber = 3;
//    
//    };
//    
////template <typename typeOfData> gVector <4, typeOfData> struct 
////    {
////  
////
////    public:
////  
////    };
//
//
//template <size_t dimensionNumber, typename typeOfData> typeOfData operator * (const gVector <dimensionNumber, typeOfData>& lhs, const gVector <dimensionNumber, typeOfData>& rhs) 
//    {
//    typeOfData ret = typeOfData();
//    for (size_t i = dimensionNumber; i--; ( ret += lhs [ i ] * rhs [ i ] ) );
//    
//    return ret;
//    }
//    
//template <size_t dimensionNumber, typename typeOfData> gVector <dimensionNumber, typeOfData> operator + ( gVector <dimensionNumber, typeOfData> lhs, const gVector <dimensionNumber, typeOfData>& rhs ) 
//    {
//    for ( size_t i = dimensionNumber; i--; ( lhs [ i ] += rhs [ i ] ) );
//    
//    return lhs;
//    }
//    
//template<size_t dimensionNumber,typename typeOfData>gVector<dimensionNumber, typeOfData> operator - ( gVector <dimensionNumber, typeOfData> lhs, const gVector <dimensionNumber, typeOfData>& rhs ) 
//    {
//    for ( size_t i = dimensionNumber; i--; ( lhs [ i ] -= rhs [ i ] ) );
//    
//    return lhs;
//    }
//    
//template <size_t dimensionNumber, typename typeOfData, typename U> gVector <dimensionNumber, typeOfData> operator * ( const gVector <dimensionNumber, typeOfData> &lhs, const U& rhs ) 
//    {
//    gVector <dimensionNumber, typeOfData> ret;
//    for ( size_t i = dimensionNumber; i--; ret [ i ] = ( lhs [ i ] * rhs ) );
//    
//    return ret;
//    }
//    
//template <size_t dimensionNumber, typename typeOfData> gVector <dimensionNumber, typeOfData> operator - ( const gVector <dimensionNumber, typeOfData> &lhs ) 
//    {
//    return lhs * typeOfData ( -1 );
//    }
//    
//template <typename typeOfData> gVector <3, typeOfData> cross ( gVector <3, typeOfData> v1, gVector <3, typeOfData> v2) 
//    {
//    return gVector <3, typeOfData> ( ( ( v1.y * v2.z ) - ( v1.z * v2.y ) ), ( ( v1.z * v2.x ) - ( v1.x * v2.z ) ), ( ( v1.x * v2.y ) - ( v1.y * v2.x ) ) );
//    }
//    
//template <size_t dimensionNumber, typename typeOfData> std::ostream& operator << ( std::ostream& out, const gVector <dimensionNumber, typeOfData>& v ) 
//    {
//    for ( unsigned int i = 0; i < dimensionNumber; i++ ) 
//        {
//        out << v [ i ] << " ";
//        }
//    return out;
//    }
//    
////template <size_t dimensionNumber, typename typeOfData> gVector <dimensionNumber, typeOfData>& operator = ( const gVector <dimensionNumber, typeOfData>& lhs, const gVector <dimensionNumber, typeOfData>& rhs )
////    {
////    for ( size_t i = 0; i < dimensionNumber; ( lhs [ i ] = rhs [ i ] ) );
////    
////    return lhs;
////    }
//
//
//
//#endif /* geometry_h */


#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

template <size_t DIM, typename T> struct vec {
    vec() { for (size_t i=DIM; i--; data_[i] = T()); }
          T& operator[](const size_t i)       { assert(i<DIM); return data_[i]; }
    const T& operator[](const size_t i) const { assert(i<DIM); return data_[i]; }
private:
    T data_[DIM];
};

typedef vec<2, float> Vec2f;
typedef vec<3, float> Vec3f;
typedef vec<3, int  > Vec3i;
typedef vec<4, float> Vec4f;

template <typename T> struct vec<2,T> {
    vec() : x(T()), y(T()) {}
    vec(T X, T Y) : x(X), y(Y) {}
    template <class U> vec<2,T>(const vec<2,U> &v);
          T& operator[](const size_t i)       { assert(i<2); return i<=0 ? x : y; }
    const T& operator[](const size_t i) const { assert(i<2); return i<=0 ? x : y; }
    T x,y;
};

template <typename T> struct vec<3,T> {
    vec() : x(T()), y(T()), z(T()) {}
    vec(T X, T Y, T Z) : x(X), y(Y), z(Z) {}
          T& operator[](const size_t i)       { assert(i<3); return i<=0 ? x : (1==i ? y : z); }
    const T& operator[](const size_t i) const { assert(i<3); return i<=0 ? x : (1==i ? y : z); }
    float norm() { return std::sqrt(x*x+y*y+z*z); }
    vec<3,T> & normalize(T l=1) { *this = (*this)*(l/norm()); return *this; }
    T x,y,z;
};

template <typename T> struct vec<4,T> {
    vec() : x(T()), y(T()), z(T()), w(T()) {}
    vec(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W) {}
          T& operator[](const size_t i)       { assert(i<4); return i<=0 ? x : (1==i ? y : (2==i ? z : w)); }
    const T& operator[](const size_t i) const { assert(i<4); return i<=0 ? x : (1==i ? y : (2==i ? z : w)); }
    T x,y,z,w;
};

template<size_t DIM,typename T> T operator*(const vec<DIM,T>& lhs, const vec<DIM,T>& rhs) {
    T ret = T();
    for (size_t i=DIM; i--; ret+=lhs[i]*rhs[i]);
    return ret;
}

template<size_t DIM,typename T>vec<DIM,T> operator+(vec<DIM,T> lhs, const vec<DIM,T>& rhs) {
    for (size_t i=DIM; i--; lhs[i]+=rhs[i]);
    return lhs;
}

template<size_t DIM,typename T>vec<DIM,T> operator-(vec<DIM,T> lhs, const vec<DIM,T>& rhs) {
    for (size_t i=DIM; i--; lhs[i]-=rhs[i]);
    return lhs;
}

template<size_t DIM,typename T,typename U> vec<DIM,T> operator*(const vec<DIM,T> &lhs, const U& rhs) {
    vec<DIM,T> ret;
    for (size_t i=DIM; i--; ret[i]=lhs[i]*rhs);
    return ret;
}

template<size_t DIM,typename T> vec<DIM,T> operator-(const vec<DIM,T> &lhs) {
    return lhs*T(-1);
}

template <typename T> vec<3,T> cross(vec<3,T> v1, vec<3,T> v2) {
    return vec<3,T>(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

template <size_t DIM, typename T> std::ostream& operator<<(std::ostream& out, const vec<DIM,T>& v) {
    for(unsigned int i=0; i<DIM; i++) out << v[i] << " " ;
    return out ;
}
#endif //__GEOMETRY_H__
