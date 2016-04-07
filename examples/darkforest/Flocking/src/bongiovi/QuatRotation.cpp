//
//  QuatRotation.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "QuatRotation.hpp"

using namespace std;
using namespace bongiovi;

void QuatRotation::_init() {
    app::WindowRef window = ci::app::getWindow();
    mCbMouseDown    = window->getSignalMouseDown().connect( std::bind( &QuatRotation::mouseDown, this, std::placeholders::_1 ) );
    mCbMouseUp      = window->getSignalMouseUp().connect( std::bind( &QuatRotation::mouseUp, this, std::placeholders::_1 ) );
    mCbMouseDrag    = window->getSignalMouseDrag().connect( std::bind( &QuatRotation::mouseDrag, this, std::placeholders::_1 ) );
    mCbMouseWheel   = window->getSignalMouseWheel().connect( std::bind( &QuatRotation::mouseWheel, this, std::placeholders::_1 ) );
    mCbUpdate       = window->getSignalDraw().connect( std::bind(&QuatRotation::update, this ) );
}


void QuatRotation::moveTo(Quatf mQuat) {
    _targetQuat = mQuat;
    _diffX.setTo(0);
    _diffY.setTo(0);
    _slerp.setTo(1);
    _slerp.setValue(0);
    _isMouseDown = false;
}


void QuatRotation::mouseDown( MouseEvent &event ) {
    if(_isLocked) return;
    _mouse = event.getPos();
    _rotation = _updateRotation(_rotation);
    _isMouseDown = true;
    _preMouse = event.getPos();
    
    _diffX.setTo(0);
    _diffY.setTo(0);
}


void QuatRotation::mouseUp( MouseEvent &event ) {
    if(_isLocked) return;
    _isMouseDown = false;
}


void QuatRotation::mouseDrag( MouseEvent &event ) {
    if(_isLocked) return;
    _mouse = event.getPos();
}


void QuatRotation::mouseWheel( MouseEvent &event ) {
    if(_isLocked) return;
}


Quatf QuatRotation::_updateRotation(Quatf mTempRotation) {
    if(_isMouseDown && !_isLocked) {
        float dir = _isInvertControl ? -1.0 : 1.0;
        _diffX.setValue( -(float(_mouse.x) - float(_preMouse.x)) * dir );
        _diffY.setValue(  (float(_mouse.y) - float(_preMouse.y)) * dir );
    }
    
    if(_diffX.getValue() == 0 && _diffY.getValue() == 0) {
        return mTempRotation;
    }
    
    Vec3f v(_diffX.getValue(), _diffY.getValue(), 0);
    Vec3f axis = cross(v, Vec3f::zAxis());
    
    axis.normalize();
    
    float angle = v.length() * _offset;
    Quatf quat(axis, angle);
    return mTempRotation * quat;
}


void QuatRotation::update() {
    if(_slerp.getValue() > 0) {
        _tempRotation = lerp(_targetQuat, _rotation, _slerp.getValue());
        
        if(_slerp.getValue() <= 0.001) {
            _rotation = Quatf(_targetQuat);
            _slerp.setTo(0);
        }
    } else {
        _tempRotation = _updateRotation(_rotation);
    }
}


Quatf QuatRotation::getRotation() {
    return _tempRotation;
}

