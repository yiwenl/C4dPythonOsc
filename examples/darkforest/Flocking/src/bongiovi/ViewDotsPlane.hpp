//
//  ViewDotsPlane.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#ifndef ViewDotsPlane_hpp
#define ViewDotsPlane_hpp

#include <stdio.h>
#include "View.hpp"

using namespace bongiovi;

class ViewDotsPlane : public View {
public:
    ViewDotsPlane();
    ViewDotsPlane(string vsPath, string fsPath);
    virtual void            render();
    
    Vec3f   color           = Vec3f(1.0, 1.0, 1.0);
    float   opacity         = 0.5;
    
private:
    void                    _init();
};

#endif /* ViewDotsPlane_hpp */
