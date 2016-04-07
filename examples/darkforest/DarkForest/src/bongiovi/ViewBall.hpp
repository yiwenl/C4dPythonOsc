//
//  ViewBall.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef ViewBall_hpp
#define ViewBall_hpp

#include <stdio.h>

#include "cinder/gl/Texture.h"
#include "View.hpp"

using namespace bongiovi;

class ViewBall : public View {
public:
    ViewBall();
    ViewBall(string vsPath, string fsPath);
    Vec3f                   position = Vec3f(0.0, 0.0, 0.0);
    Vec3f                   scale = Vec3f(1.0, 1.0, 1.0);
    Vec3f                   color = Vec3f(1.0, 1.0, 1.0);
    float                   opacity = 1.0;
    void                    render();
    
private:
    void                    _init();
};


#endif /* ViewBall_hpp */
