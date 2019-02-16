//
//  main.cpp
//  Basic Ray Tracing
//
//  Created by Эльдар Дамиров on 22.01.2019.
//  Copyright © 2019 Эльдар Дамиров. All rights reserved.
//

#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

#include "geometry.h"
#include "basicFigures.h"
#include "render.h"

int main() 
    {
    Sphere mySphere = Sphere ( Vec3f ( 512, 384, 10 ), 100 );
    render ( mySphere );
//    render();
    
    return 0;
    }


//#include <limits>
//#include <cmath>
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include "geometry.h"
//
//void render() {
//    const int width    = 1024;
//    const int height   = 768;
//    std::vector<Vec3f> framebuffer(width*height);
//
//    for (size_t j = 0; j<height; j++) {
//        for (size_t i = 0; i<width; i++) {
//            framebuffer[i+j*width] = Vec3f(j/float(height),i/float(width), 0);
//        }
//    }
//
//    std::ofstream ofs; // save the framebuffer to file
//    ofs.open("./out.ppm");
//    ofs << "P6\n" << width << " " << height << "\n255\n";
//    for (size_t i = 0; i < height*width; ++i) {
//        for (size_t j = 0; j<3; j++) {
//            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
//        }
//    }
//    ofs.close();
//}
//
//int main() {
//    render();
//    return 0;
//}
