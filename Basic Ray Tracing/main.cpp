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
    Sphere mySphere = Sphere ( Vec3f ( 0.0, 100, 50 ), 1 );
    render ( mySphere );
//    render();
    
    return 0;
    }
