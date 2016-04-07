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
#include "cinder/gl/Fbo.h"
#include "cinder/Surface.h"
#include "bongiovi/Scene.hpp"
#include "bongiovi/ViewAxis.hpp"
#include "bongiovi/ViewDotsPlane.hpp"
#include "ViewTest.hpp"
#include "ViewSave.hpp"
#include "ViewCopy.hpp"
#include "ViewRender.hpp"
#include "ViewAddVel.hpp"
#include "ViewSim.hpp"
#include "OscSender.h"

using namespace ci;
using namespace gl;
using namespace std;
using namespace bongiovi;

class SceneApp : public Scene {
public:
    SceneApp() : Scene() {
        _initTextures();
        _initViews();
        _initOSC();
    };
    void render();
    
    
    
private:
    
    void _initTextures();
    void _initViews();
    void _initOSC();
    void _sendOSC();
    
    
    ViewAxis*       _vAxis;
    ViewDotsPlane*  _vDots;
    ViewTest*       _vTest;
    ViewSave*       _vSave;
    ViewCopy*       _vCopy;
    ViewRender*     _vRender;
    ViewAddVel*     _vAddVel;
    ViewSim*        _vSim;
    
    Fbo*            _fboCurrPos;
    Fbo*            _fboNextPos;
    Fbo*            _fboCurrVel;
    Fbo*            _fboNextVel;
    Fbo*            _fboExtra;
    
    Surface32f      _surface;
    
    osc::Sender     sender;
    std::string     host;
    int             port = 8897;
};

#endif /* SceneApp_hpp */
