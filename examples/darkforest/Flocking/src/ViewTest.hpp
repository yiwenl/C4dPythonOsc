//
//  ViewTest.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef ViewTest_hpp
#define ViewTest_hpp

#include <stdio.h>

#include "cinder/gl/Texture.h"
#include "bongiovi/View.hpp"

using namespace bongiovi;

class ViewTest : public View {
public:
    ViewTest();
    ViewTest(string vsPath, string fsPath);
    virtual void            render();
    
private:
    void                    _init();
};


#endif /* ViewTest_hpp */
