//
//  ViewSim.cpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#include "ViewSim.hpp"
#include "bongiovi/Geom.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

ViewSim::ViewSim() : View("shaders/bigTriangle.vert", "shaders/sim.frag") {
    _init();
}

ViewSim::ViewSim(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewSim::_init() {
    mesh = bongiovi::Geom::bigTriangle();
}

void ViewSim::render(gl::Texture texturePos, gl::Texture textureVel, gl::Texture textureExtra) {
    _time += 0.005;
    
    shader->bind();
    shader->uniform("texturePos", 0);
    texturePos.bind(0);
    shader->uniform("textureVel", 1);
    textureVel.bind(1);
    shader->uniform("textureExtra", 2);
    textureExtra.bind(2);
    shader->uniform("time", _time);
    gl::draw(mesh);
    texturePos.unbind();
    textureVel.unbind();
    textureExtra.unbind();
    shader->unbind();
}