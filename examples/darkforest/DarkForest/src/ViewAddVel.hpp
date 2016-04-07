//
//  ViewAddVel.hpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#ifndef ViewAddVel_hpp
#define ViewAddVel_hpp

#include <stdio.h>

#include "cinder/gl/Texture.h"
#include "bongiovi/View.hpp"

using namespace bongiovi;

class ViewAddVel : public View {
public:
    ViewAddVel();
    ViewAddVel(string vsPath, string fsPath);
    virtual void            render(gl::Texture, gl::Texture);
    
private:
    void                    _init();
};


#endif /* ViewAddVel_hpp */
