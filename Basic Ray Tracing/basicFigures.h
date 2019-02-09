//
//  basicFigures.h
//  Basic Ray Tracing
//
//  Created by Эльдар Дамиров on 09.02.2019.
//  Copyright © 2019 Эльдар Дамиров. All rights reserved.
//

#ifndef basicFigures_h
#define basicFigures_h

struct Sphere
    {
    Vec3f center{};
    float radius = 0.0;
    
    Sphere ( const Vec3f& centerT, const float& radiusT = 1.0 ): center ( centerT ), radius ( radiusT )
        {
        
        }
    
    
    bool areRayIntersecting ( const Vec3f& origin, const Vec3f& direction, float& t0 ) const // from point origin in "direction" direction;
        {
        Vec3f L = center - origin;
        float touching = L * direction;
        float d2 = ( L * L ) - ( touching * touching );
        
        if ( d2 > ( radius * radius ) )
            {
            return false;
            }
        
        float thc = sqrtf ( ( radius * radius ) - d2 );
        t0        = touching - thc;
        float t1  = touching + thc;
        
        if ( t0 < 0 )
            {
            t0 = t1;
            return false;
            }
        
        return true;
        }
    
//    bool ray_intersect(const Vec3f &orig, const Vec3f &dir, float &t0) const {
//        Vec3f L = center - orig;
//        float tca = L*dir;
//        float d2 = L*L - tca*tca;
//        if (d2 > radius*radius) return false;
//        float thc = sqrtf(radius*radius - d2);
//        t0       = tca - thc;
//        float t1 = tca + thc;
//        if (t0 < 0) t0 = t1;
//        if (t0 < 0) return false;
//        return true;
//    }
    
    
    };



#endif /* basicFigures_h */
