//
//  ViewAddVel.cpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#include "ViewAddVel.hpp"
#include "bongiovi/Geom.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

ViewAddVel::ViewAddVel() : View("shaders/bigTriangle.vert", "shaders/addvel.frag") {
    _init();
}

ViewAddVel::ViewAddVel(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewAddVel::_init() {
    mesh = bongiovi::Geom::bigTriangle();
}


void ViewAddVel::render(gl::Texture texturePos, gl::Texture textureVel) {
    shader->bind();
    shader->uniform("texturePos", 0);
    texturePos.bind(0);
    shader->uniform("textureVel", 1);
    textureVel.bind(1);
    gl::draw(mesh);
    texturePos.unbind();
    textureVel.unbind();
    shader->unbind();
}