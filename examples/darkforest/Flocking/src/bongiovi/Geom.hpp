//
//  Geom.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef Geom_hpp
#define Geom_hpp

#include <stdio.h>
#include "cinder/gl/Vbo.h"

using namespace ci;

namespace bongiovi {
    class Geom {
        public :
        static gl::VboMesh      bigTriangle();
        static gl::VboMesh      plane(float size, int segments);
        static gl::VboMesh      plane(float width, float height, int segments);
        static gl::VboMesh      sphere(float size, int segments);
        static gl::VboMesh      sphere(float size, int segments, bool isInvert);
        static gl::VboMesh      cube(float size);
        static gl::VboMesh      cube(float width, float height, float depth);
        
        
        private :
        static Vec3f            _getSpherePos(int, int, int);
    };
}


#endif /* Geom_hpp */
