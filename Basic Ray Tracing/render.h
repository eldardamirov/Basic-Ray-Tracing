//
//  render.h
//  Basic Ray Tracing
//
//  Created by Эльдар Дамиров on 26.01.2019.
//  Copyright © 2019 Эльдар Дамиров. All rights reserved.
//

#ifndef render_h
#define render_h

//#include <fstream>
//#include <limits.h>
//
//const size_t width  = 1024;
//const size_t height = 768;
//
//void render()
//    {
//    std::vector <gVector3f> frameBuffer ( width * height );
//     
//    for ( size_t currentY = 0; currentY < height; currentY++ )
//        {
//        for ( size_t currentX = 0; currentX < width; currentX++ )
//            {
//            frameBuffer [ currentY + ( currentX * width ) ] = gVector3f ( ( currentY / static_cast <double> ( height ) ), ( currentX / static_cast <double> ( width ) ), 0 );
//            }
//        }
//    
//    
//    }

#include <fstream>
#include <limits.h>

const size_t width = 1024;
const size_t height = 768;

Vec3f rayCasting ( const Vec3f& origin, const Vec3f& direction, const Sphere &sphere )
    {
    float distanceToSphere = std::numeric_limits <float>::max(); // pointing alongside axis Z, in infinity;
    
    if ( !sphere.areRayIntersecting ( origin, direction, distanceToSphere ) )
        {
        return Vec3f ( 0.2, 0.7, 0.8 ); // we look pass sphere;
        }
    
    return Vec3f ( 0.4, 0.4, 0.3 ); // we look at sphere;
    }

void render()
    {
    std::vector <Vec3f> frameBuffer ( width * height );
    
    for ( size_t currentY = 0; currentY < height; currentY++ )
        {
        for ( size_t currentX = 0; currentX < width; currentX++ )
            {
            frameBuffer [ currentX + ( currentY * width ) ] = Vec3f ( ( currentY / static_cast <double> ( height ) ), ( currentX / static_cast <double> ( width ) ), 0 );
            }
        }
        
    std::ofstream outputStream;
    outputStream.open ( "./out.ppm" );
    
    outputStream << "P6\n" << width << " " << height << "\n255\n";
    for ( size_t i = 0; i < ( height * width ); i++ )
        {
        for ( size_t j = 0; j < 3; j++ )
            {
            outputStream << static_cast <char> ( 255 * std::max ( 0.f, std::min ( 1.f, frameBuffer [ i ] [ j ] ) ) );
            }
        }
    
    outputStream.close();
    }
    
   

void render ( const Sphere& sphere, const float visionAngle = M_PI / 2 )
    {
    std::vector <Vec3f> frameBuffer ( width * height );
    
    for ( size_t j = 0; j < height; j++ )
        {
        for ( size_t i = 0; i < width; i++ )
            {
            float x =  ( 2 * ( i + 0.5 ) / static_cast <float> ( width )  - 1 ) * tan ( visionAngle / 2.f ) * width / static_cast <float> ( height );
            float y = -( 2 * ( j + 0.5 ) / static_cast <float> ( height ) - 1 ) * tan ( visionAngle / 2.f );
            
            Vec3f direction = Vec3f ( x, y, -1 ).normalize();
            
            frameBuffer [ j * width + i ] = rayCasting ( Vec3f ( 0, 0, 0 ), direction, sphere );
            }
        }
        
    std::ofstream outputStream;
    outputStream.open ( "./out.ppm" );
    
    outputStream << "P6\n" << width << " " << height << "\n255\n";
    for ( size_t i = 0; i < ( height * width ); i++ )
        {
        for ( size_t j = 0; j < 3; j++ )
            {
            outputStream << static_cast <char> ( 255 * std::max ( 0.f, std::min ( 1.f, frameBuffer [ i ] [ j ] ) ) );
            }
        }
    
    outputStream.close();
    }

//void render(const Sphere &sphere) {
//￼    [...]
//    for (size_t j = 0; j<height; j++) {
//        for (size_t i = 0; i<width; i++) {
//            float x =  (2*(i + 0.5)/(float)width  - 1)*tan(fov/2.)*width/(float)height;
//            float y = -(2*(j + 0.5)/(float)height - 1)*tan(fov/2.);
//            Vec3f dir = Vec3f(x, y, -1).normalize();
//            framebuffer[i+j*width] = cast_ray(Vec3f(0,0,0), dir, sphere);
//        }
//    }
//￼    [...]
//}
    

    

#endif /* render_h */
