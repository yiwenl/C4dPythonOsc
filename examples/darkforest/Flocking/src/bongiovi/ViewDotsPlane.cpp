//
//  ViewDotsPlane.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#include "ViewDotsPlane.hpp"


ViewDotsPlane::ViewDotsPlane() : View("shaders/basic.vert", "shaders/simpleColor.frag") {
    _init();
}

void ViewDotsPlane::_init() {
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticPositions();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Color> colors;
    
    int numDots = 100;
    int count = 0;
    float gap = 1.0f;
    float sx = -numDots/2.0f * gap;
    
    for(int j=0; j<numDots; j++) {
        for(int i=0; i<numDots; i++) {
            Vec3f p0(sx + i*gap, 0, sx + j*gap);
            Vec3f p1(sx + i*gap, sx + j*gap, 0);
            
            positions.push_back(p0);
            positions.push_back(p1);
            
            indices.push_back(count);
            indices.push_back(count+1);
            
            count += 2;
        }
    }
    
    
    mesh = gl::VboMesh(positions.size(), indices.size(), layout, GL_POINTS);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
}

void ViewDotsPlane::render() {
    shader->bind();
    shader->uniform("color", color);
    shader->uniform("opacity", opacity);
    gl::draw(mesh);
    shader->unbind();
}