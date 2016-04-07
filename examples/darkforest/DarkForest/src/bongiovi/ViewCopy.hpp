//
//  ViewCopy.hpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#ifndef ViewCopy_hpp
#define ViewCopy_hpp

#include <stdio.h>

#include "cinder/gl/Texture.h"
#include "View.hpp"

using namespace bongiovi;

class ViewCopy : public View {
public:
    ViewCopy();
    ViewCopy(string vsPath, string fsPath);
    virtual void            render(gl::Texture);
    virtual void            render(gl::TextureRef);
    
private:
    void                    _init();
};


#endif /* ViewCopy_hpp */
