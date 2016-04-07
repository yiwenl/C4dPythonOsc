//
//  SceneApp.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "SceneApp.hpp"
#include "cinder/System.h"
#include "GlobalSettings.hpp"


void SceneApp::_initTextures() {
    cout << "Init textures" << endl;
    
    gl::Fbo::Format format;
    format.setColorInternalFormat(GL_RGBA32F_ARB);
    format.setMinFilter(GL_NEAREST);
    format.setMagFilter(GL_NEAREST);
    int size = GlobalSettings::getInstance().numParticles;
    
    _fboCurrPos = new Fbo(size, size, format);
    _fboNextPos = new Fbo(size, size, format);
    _fboCurrVel = new Fbo(size, size, format);
    _fboNextVel = new Fbo(size, size, format);
    _fboExtra   = new Fbo(size, size, format);
    
    _fboCurrPos->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboCurrPos->unbindFramebuffer();
    
    _fboNextPos->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboNextPos->unbindFramebuffer();
    
    _fboCurrVel->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboCurrVel->unbindFramebuffer();
    
    _fboNextVel->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboNextVel->unbindFramebuffer();

    _fboExtra->bindFramebuffer();
    gl::clear(ColorAf(0, 0, 0, 0));
    _fboExtra->unbindFramebuffer();

}

void SceneApp::_initViews() {
    _vAxis = new ViewAxis();
    _vDots = new ViewDotsPlane();
    
    _vTest = new ViewTest();
    _vSave = new ViewSave();
    _vCopy = new ViewCopy();
    _vRender    = new ViewRender();
    _vAddVel    = new ViewAddVel();
    _vSim       = new ViewSim();
    
    
    gl::setMatrices(*cameraOrtho);
    Area viewport = gl::getViewport();
    gl::setViewport(_fboCurrPos->getBounds());
    
    _fboCurrPos->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vSave->render();
    _fboCurrPos->unbindFramebuffer();
    
    _fboExtra->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vSave->renderExtra();
    _fboExtra->unbindFramebuffer();
    
    
    gl::setViewport(viewport);
    orbitalControl->radius->setValue(20.0);
    orbitalControl->rx->setValue(.3);
    orbitalControl->ry->setValue(1.3);
}

void SceneApp::_initOSC() {
    // assume the broadcast address is this machine's IP address but with 255 as the final value
    // so to multicast from IP 192.168.1.100, the host should be 192.168.1.255
    host = System::getIpAddress();
    if( host.rfind( '.' ) != string::npos )
        host.replace( host.rfind( '.' ) + 1, 3, "255" );
    
    cout << "Host : "<< host << endl;
    sender.setup( "localhost", port, true );
}

void SceneApp::render() {
    
    _vAxis->render();
    _vDots->render();
    
    
    Area viewport = gl::getViewport();
    gl::setViewport(_fboCurrPos->getBounds());
    
    _fboNextVel->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vSim->render(_fboCurrPos->getTexture(), _fboCurrVel->getTexture(), _fboExtra->getTexture());
    _fboNextVel->unbindFramebuffer();
    
    _fboNextPos->bindFramebuffer();
    gl::clear(Color(0, 0, 0));
    _vAddVel->render(_fboCurrPos->getTexture(), _fboNextVel->getTexture());
    _fboNextPos->unbindFramebuffer();
    
    
    gl::setViewport(viewport);
    _vRender->render(_fboCurrPos->getTexture(), _fboExtra->getTexture());
    
//    int size = 256;
//    
//    Area bounds = gl::getViewport();
//    gl::setViewport(Area(0, 0, size, size));
//    _vCopy->render(_fboNextPos->getTexture());
//    
//    gl::setViewport(Area(size, 0, size*2, size));
//    _vCopy->render(_fboNextVel->getTexture());
//    gl::setViewport(bounds);
    
    _sendOSC();
    
    swap(_fboCurrVel, _fboNextVel);
    swap(_fboCurrPos, _fboNextPos);
    
}


void SceneApp::_sendOSC() {
    _surface = Surface32f(_fboCurrPos->getTexture());
    Surface32f::Iter iter = _surface.getIter();
    
    int count=0;
    while(iter.line()) {
        while(iter.pixel()) {
            float r = iter.r();
            float g = iter.g();
            float b = iter.b();
            
            osc::Message message;
            message.setAddress("/positions");
            message.addFloatArg(r);
            message.addFloatArg(g);
            message.addFloatArg(b);
            message.addFloatArg(float(count));
            sender.sendMessage(message);
            
            count++;
        }
    }
    
    osc::Message message;
    message.setAddress("/update");
    sender.sendMessage(message);
}
