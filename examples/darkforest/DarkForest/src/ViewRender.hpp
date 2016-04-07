//
//  ViewRender.hpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#ifndef ViewRender_hpp
#define ViewRender_hpp

#include <stdio.h>

#include "cinder/gl/Texture.h"
#include "bongiovi/View.hpp"

using namespace bongiovi;

class ViewRender : public View {
public:
    ViewRender();
    ViewRender(string vsPath, string fsPath);
    virtual void            render(gl::Texture, gl::Texture);
    
private:
    void                    _init();
};


#endif /* ViewRender_hpp */
