//
//  ViewTest.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "ViewTest.hpp"

#include "bongiovi/Geom.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bongiovi;

ViewTest::ViewTest() : View("shaders/basic.vert", "shaders/light.frag") {
    _init();
}

ViewTest::ViewTest(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewTest::_init() {
    mesh = Geom::plane(2, 1, 1);
    mesh = Geom::sphere(1, 24);
//    mesh = Geom::cube(1);
//    mesh = Geom::bigTriangle();
}

void ViewTest::render() {
    shader->bind();
    shader->uniform("color", Vec3f(1.0, 1.0, 1.0));
    shader->uniform("opacity", 1.0f);
    gl::draw(mesh);
    shader->unbind();
}