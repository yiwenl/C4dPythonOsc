//
//  ViewSim.hpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#ifndef ViewSim_hpp
#define ViewSim_hpp

#include <stdio.h>
#include "cinder/Rand.h"
#include "cinder/gl/Texture.h"
#include "bongiovi/View.hpp"

using namespace bongiovi;

class ViewSim : public View {
public:
    ViewSim();
    ViewSim(string vsPath, string fsPath);
    virtual void            render(gl::Texture, gl::Texture, gl::Texture);
    
private:
    void                    _init();
    float                   _time = Rand::randFloat(1000.0f);
};


#endif /* ViewSim_hpp */
