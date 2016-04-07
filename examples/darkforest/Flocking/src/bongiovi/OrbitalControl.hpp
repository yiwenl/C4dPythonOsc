//
//  OrbitalControl.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef OrbitalControl_hpp
#define OrbitalControl_hpp

#include <stdio.h>
#include "cinder/Camera.h"
#include "cinder/App/App.h"
#include "EaseNumber.hpp"

using namespace ci;
using namespace ci::app;


namespace bongiovi {
    class OrbitalControl {
    private:
        CameraPersp*    _camera;
        ci::app::WindowRef _window;
        void _init();
        
        
        void	mouseDown( ci::app::MouseEvent &event );
        void	mouseDrag( ci::app::MouseEvent &event );
        void	mouseWheel( ci::app::MouseEvent &event );
        
        signals::scoped_connection	mCbMouseDown, mCbMouseDrag, mCbMouseWheel, mCbUpdate;
        
        
        bool    _lookZoom = false;
        bool    _lockRotation = false;
        Vec2i   _preMouse;
        Vec2i   _mouse;
        
    public:
        
        OrbitalControl();
        OrbitalControl(CameraPersp* camera);
        EaseNumber          *radius, *rx, *ry;
        float               _preRx, _preRy;
        Vec3f				eye, target, up;
        
        
        void lockZoom(bool mValue) {
            _lookZoom = mValue;
        }
        
        void lockRotation(bool mValue) {
            _lockRotation = mValue;
        }
        
        void lock(bool mValue) {
            _lookZoom = _lockRotation = mValue;
        }
        
        void	update();
    };
}



#endif /* OrbitalControl_hpp */
