//
//  ViewCopy.cpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#include "ViewCopy.hpp"
#include "Geom.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

ViewCopy::ViewCopy() : View("shaders/bigTriangle.vert", "shaders/copy.frag") {
    _init();
}

ViewCopy::ViewCopy(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewCopy::_init() {
    mesh = bongiovi::Geom::bigTriangle();
}

void ViewCopy::render(gl::TextureRef texture) {
    render(*texture);
}

void ViewCopy::render(gl::Texture texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture.bind();
    gl::draw(mesh);
    texture.unbind();
    shader->unbind();
}