//
//  ViewRender.cpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/3.
//
//

#include "ViewRender.hpp"
#include "GlobalSettings.hpp"
#include "bongiovi/Geom.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

ViewRender::ViewRender() : View("shaders/render.vert", "shaders/render.frag") {
    _init();
}

ViewRender::ViewRender(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewRender::_init() {
    vector<Vec3f> positions;
    vector<uint> indices;
    
    int count = 0;
    int numParticles = GlobalSettings::getInstance().numParticles;
    
    for( int j=0; j<numParticles; j++) {
        for( int i=0; i<numParticles; i++) {
            
            float ux = float(i)/float(numParticles);
            float uy = float(j)/float(numParticles);
            Vec3f v(ux, uy, 0.0);
            
            positions.push_back(v);
            indices.push_back(count);
            count ++;
        }
    }
    
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    
    mesh = gl::VboMesh(positions.size(), indices.size(), layout, GL_POINTS);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
}


void ViewRender::render(gl::Texture texture, gl::Texture textureExtra) {
    shader->bind();
    shader->uniform("texture", 0);
    texture.bind();
    shader->uniform("textureExtra", 1);
    textureExtra.bind(1);
    gl::draw(mesh);
    texture.unbind();
    textureExtra.unbind();
    shader->unbind();
}