//
//  ViewSave.cpp
//  ParticleTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "ViewSave.hpp"
#include "GlobalSettings.hpp"
#include "bongiovi/Geom.hpp"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

ViewSave::ViewSave() : View("shaders/save.vert", "shaders/save.frag") {
    _init();
}

ViewSave::ViewSave(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewSave::_init() {
    
    vector<Vec3f> positions;
    vector<Vec3f> extras;
    vector<Vec2f> coords;
    vector<uint> indices;
    
    int count = 0;
    int numParticles = GlobalSettings::getInstance().numParticles;
    
    for( int j=0; j<numParticles; j++) {
        for( int i=0; i<numParticles; i++) {
            Vec3f v = Rand::randVec3f() * Rand::randFloat(3);
            Vec3f r = Rand::randVec3f() * .5 + Vec3f(.5, .5, .5);
            
            float ux = float(i)/float(numParticles)*2.0 - 1.0 + 0.5/float(numParticles);
            float uy = float(j)/float(numParticles)*2.0 - 1.0 + 0.5/float(numParticles);
            
            positions.push_back(v);
            extras.push_back(r);
            coords.push_back(Vec2f(ux, uy));
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
    mesh.bufferTexCoords2d(0, coords);
    
    meshExtra = gl::VboMesh(positions.size(), indices.size(), layout, GL_POINTS);
    meshExtra.bufferPositions(extras);
    meshExtra.bufferIndices(indices);
    meshExtra.bufferTexCoords2d(0, coords);
    
}

void ViewSave::render() {
    shader->bind();
    gl::draw(mesh);
    shader->unbind();
}



void ViewSave::renderExtra() {
    shader->bind();
    gl::draw(meshExtra);
    shader->unbind();
}
