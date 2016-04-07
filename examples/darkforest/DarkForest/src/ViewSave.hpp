//
//  ViewSave.hpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef ViewSave_hpp
#define ViewSave_hpp

#include <stdio.h>

#include "cinder/gl/Texture.h"
#include "bongiovi/View.hpp"

using namespace bongiovi;

class ViewSave : public View {
public:
    ViewSave();
    ViewSave(string vsPath, string fsPath);
    virtual void            render();
    virtual void            renderExtra();
    gl::VboMesh             meshExtra;
    
private:
    void                    _init();
};


#endif /* ViewSave_hpp */
