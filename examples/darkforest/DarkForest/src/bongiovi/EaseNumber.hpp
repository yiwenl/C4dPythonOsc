//
//  EaseNumber.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#ifndef EaseNumber_hpp
#define EaseNumber_hpp

#include <stdio.h>

using namespace ci;
using namespace ci::app;

namespace bongiovi {
    
    class EaseNumber {
        private :
        float _value;
        float _targetValue;
        float _min = -99999999.9f;
        float _max =  99999999.9f;
        
        app::WindowRef _window;
        signals::scoped_connection mCbUpdate;
        
        
    public:
        float easing;
        
        EaseNumber() : _value(0.0f), easing(0.1f), _targetValue(0.0f){
            _init();
        }
        
        EaseNumber(float mValue) : easing(0.1f) {
            _value = mValue;
            _targetValue = mValue;
            
            _init();
        }
        
        EaseNumber(float mValue, float mEasing) {
            _value = mValue;
            _targetValue = mValue;
            easing = mEasing;
            
            _init();
        }
        
        
        void _init() {
            _window = app::getWindow();
            mCbUpdate = _window->getSignalDraw().connect( std::bind(&EaseNumber::_loop, this));
        }
        
        
        void _loop() {
            _value += (_targetValue - _value) * easing;
        }
        
        void setTo(float mValue) {
            _targetValue = _value = mValue;
        }
        
        
        void add(float mValue) {
            _targetValue += mValue;
        }
        
        
        //  getter / setter for value;
        float getValue() {
            return _value;
        }
        
        void setValue(float mValue) {
            _targetValue = mValue;
        }
        
        float getTargetValue() {
            return _targetValue;
        }
        
        void limit(float min, float max) {
            _min = min;
            _max = max;
            _checkLimit();
        }
        
        void _checkLimit() {
            if(_targetValue < _min) _targetValue = _min;
            if(_targetValue > _max) _targetValue = _max;
        }
    };

}



#endif /* EaseNumber_hpp */
