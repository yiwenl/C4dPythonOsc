//
//  SceneApp.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef SceneApp_hpp
#define SceneApp_hpp

#include <stdio.h>
#include "bongiovi/Scene.hpp"
#include "bongiovi/ViewAxis.hpp"
#include "bongiovi/ViewDotsPlane.hpp"

#include "ViewTest.hpp"

using namespace ci;
using namespace std;
using namespace bongiovi;

class SceneApp : public Scene {
public:
    SceneApp() : Scene() {
        _initTextures();
        _initViews();
    };
    void render();
    
    
    
private:
    
    void _initTextures();
    void _initViews();
    
    ViewAxis*       _vAxis;
    ViewDotsPlane*  _vDots;
    ViewTest*       _vTest;
};

#endif /* SceneApp_hpp */
