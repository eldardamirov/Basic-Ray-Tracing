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

void render()
    {
    std::vector <Vec3f> frameBuffer ( width * height );
    
    for ( size_t currentY = 0; currentY < height; currentY++ )
        {
        for ( size_t currentX = 0; currentX < width; currentX++ )
            {
            frameBuffer [ currentY + ( currentX * width ) ] = Vec3f ( ( currentY / static_cast <double> ( height ) ), ( currentX / static_cast <double> ( width ) ), 0 );
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
    


#endif /* render_h */
