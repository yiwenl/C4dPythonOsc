//
//  OrbitalControl.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "OrbitalControl.hpp"

using namespace bongiovi;


OrbitalControl::OrbitalControl(CameraPersp* camera) : _camera(camera) {
    _init();
}

void OrbitalControl::_init() {
    radius          = new EaseNumber(5.0, .1f);
    rx              = new EaseNumber(0);
    ry              = new EaseNumber(M_PI*.5);
    rx->limit(-M_PI/2, M_PI/2);
    _preRx          = 0;
    _preRy          = 0;
    
    eye             = Vec3f( 0.0f, 0.0f, radius->getValue() );
    target			= Vec3f::zero();
    up				= Vec3f::yAxis();
    
    
    _window = ci::app::getWindow();
    mCbMouseDown    = _window->getSignalMouseDown().connect( std::bind( &OrbitalControl::mouseDown, this, std::placeholders::_1 ) );
    mCbMouseDrag    = _window->getSignalMouseDrag().connect( std::bind( &OrbitalControl::mouseDrag, this, std::placeholders::_1 ) );
    mCbMouseWheel   = _window->getSignalMouseWheel().connect( std::bind( &OrbitalControl::mouseWheel, this, std::placeholders::_1 ) );
    mCbUpdate       = _window->getSignalDraw().connect( std::bind(&OrbitalControl::update, this ) );
}



void OrbitalControl::mouseDown( MouseEvent &event ) {
    if(_lockRotation) return;
    _preMouse = event.getPos();
    _preRy = rx->getTargetValue();
    _preRy = ry->getTargetValue();
}


void OrbitalControl::mouseDrag( MouseEvent &event ) {
    if(_lockRotation) return;
    _mouse = event.getPos();
    
    float diffX = -(_mouse.x - _preMouse.x);
    float diffY = -(_mouse.y - _preMouse.y);
    
    ry->setValue(_preRy - diffX * .01f);
    rx->setValue(_preRx - diffY * .01f);
    
}

void OrbitalControl::mouseWheel( MouseEvent &event ) {
    if(_lookZoom) return;
    radius->add(event.getWheelIncrement()*0.25f);
}

void OrbitalControl::update() {
    eye.y = sin(rx->getValue()) * radius->getValue();
    float tr = cos(rx->getValue()) * radius->getValue();
    eye.x = cos(ry->getValue()) * tr;
    eye.z = sin(ry->getValue()) * tr;
    
    _camera->lookAt(eye, target, up);
}