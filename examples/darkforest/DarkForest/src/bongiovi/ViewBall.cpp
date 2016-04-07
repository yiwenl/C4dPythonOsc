//
//  ViewBall.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "ViewBall.hpp"
#include "Geom.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace bongiovi;

ViewBall::ViewBall() : View("shaders/general.vert", "shaders/simpleColor.frag") {
    _init();
}


void ViewBall::_init() {
    mesh = Geom::sphere(1, 24);
}

void ViewBall::render() {
    shader->bind();
    shader->uniform("position", position);
    shader->uniform("scale", scale);
    shader->uniform("color", color);
    shader->uniform("opacity", opacity);
    gl::draw(mesh);
    shader->unbind();
}