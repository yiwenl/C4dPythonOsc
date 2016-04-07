//
//  SceneApp.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "SceneApp.hpp"


void SceneApp::_initTextures() {
    cout << "Init textures" << endl;
}

void SceneApp::_initViews() {
    cout << "Init views" << endl;
    
    _vAxis = new ViewAxis();
    _vDots = new ViewDotsPlane();
    
    _vTest = new ViewTest();
    
    
    orbitalControl->rx->setValue(.3);
    orbitalControl->ry->setValue(.3);
}

void SceneApp::render() {
    
    _vAxis->render();
    _vDots->render();
    
//    _vTest->render();
    
}