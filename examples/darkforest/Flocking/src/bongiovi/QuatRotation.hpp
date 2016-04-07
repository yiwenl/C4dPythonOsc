//
//  QuatRotation.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef QuatRotation_hpp
#define QuatRotation_hpp

#include <stdio.h>

#include "cinder/App/App.h"
#include "EaseNumber.hpp"


using namespace ci;
using namespace ci::app;

namespace bongiovi {
    class QuatRotation {
    public:
        QuatRotation(){
            _init();
        };
        void    update();
        void    lock(bool mValue) {
            _isLocked = mValue;
        }
        
        void    inverseControl(bool mValue) {
            _isInvertControl = mValue;
        }
        
        void    moveTo(Quatf);
        Quatf   getRotation();
        
    protected:
        void        _init();
        bool        _isLocked = false;
        bool        _isInvertControl = false;
        bool        _isMouseDown = false;
        Vec2i       _preMouse;
        Vec2i       _mouse;
        float       _offset = 0.004;
        EaseNumber  _diffX;
        EaseNumber  _diffY;
        EaseNumber  _slerp;
        
        Quatf       _rotation;
        Quatf       _tempRotation;
        Quatf       _targetQuat;
        
        void        mouseUp( MouseEvent &event );
        void        mouseDown( MouseEvent &event );
        void        mouseDrag( MouseEvent &event );
        void        mouseWheel( MouseEvent &event );
        Quatf       _updateRotation(Quatf);
        
        signals::scoped_connection	mCbMouseDown, mCbMouseUp, mCbMouseDrag, mCbMouseWheel, mCbUpdate;
    };
}

#endif /* QuatRotation_hpp */
