//
//  Geom.cpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/2.
//
//

#include "Geom.hpp"

using namespace std;
using namespace bongiovi;

gl::VboMesh Geom::bigTriangle() {
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec2f> coords;
    
    positions.push_back(Vec3f(-1, -1, 0));
    positions.push_back(Vec3f(-1,  4, 0));
    positions.push_back(Vec3f( 4, -1, 0));
    
    coords.push_back(Vec2f(0.0, 0.0));
    coords.push_back(Vec2f(0.0, 2.5));
    coords.push_back(Vec2f(2.5, 0.0));
    
    indices.push_back(2);
    indices.push_back(1);
    indices.push_back(0);
    
    gl::VboMesh mesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
    
    return mesh;
}


gl::VboMesh Geom::cube(float size) {
    return Geom::cube(size, size, size);
}

gl::VboMesh Geom::cube(float width, float height, float depth) {
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    layout.setStaticNormals();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec3f> normals;
    vector<Vec2f> coords;
    int index = 0;
    
    float x = width/2;
    float y = height/2;
    float z = depth/2;
    
    //  BACK
    positions.push_back(Vec3f(-x,  y, -z));
    positions.push_back(Vec3f( x,  y, -z));
    positions.push_back(Vec3f( x, -y, -z));
    positions.push_back(Vec3f(-x, -y, -z));
    
    normals.push_back(Vec3f(0, 0, -1));
    normals.push_back(Vec3f(0, 0, -1));
    normals.push_back(Vec3f(0, 0, -1));
    normals.push_back(Vec3f(0, 0, -1));
    
    coords.push_back(Vec2f(0, 0));
    coords.push_back(Vec2f(1, 0));
    coords.push_back(Vec2f(1, 1));
    coords.push_back(Vec2f(0, 1));
    
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 1);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 3);
    
    index ++;
    
    //  RIGHT
    positions.push_back(Vec3f( x,  y, -z));
    positions.push_back(Vec3f( x,  y,  z));
    positions.push_back(Vec3f( x, -y,  z));
    positions.push_back(Vec3f( x, -y, -z));
    
    normals.push_back(Vec3f(1, 0, 0));
    normals.push_back(Vec3f(1, 0, 0));
    normals.push_back(Vec3f(1, 0, 0));
    normals.push_back(Vec3f(1, 0, 0));
    
    coords.push_back(Vec2f(0, 0));
    coords.push_back(Vec2f(1, 0));
    coords.push_back(Vec2f(1, 1));
    coords.push_back(Vec2f(0, 1));
    
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 1);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 3);
    
    index ++;
    
    //  FRONT
    positions.push_back(Vec3f( x,  y,  z));
    positions.push_back(Vec3f(-x,  y,  z));
    positions.push_back(Vec3f(-x, -y,  z));
    positions.push_back(Vec3f( x, -y,  z));
    
    normals.push_back(Vec3f(0, 0, 1));
    normals.push_back(Vec3f(0, 0, 1));
    normals.push_back(Vec3f(0, 0, 1));
    normals.push_back(Vec3f(0, 0, 1));
    
    coords.push_back(Vec2f(0, 0));
    coords.push_back(Vec2f(1, 0));
    coords.push_back(Vec2f(1, 1));
    coords.push_back(Vec2f(0, 1));
    
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 1);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 3);
    
    index ++;
    
    
    //  LEFT
    positions.push_back(Vec3f(-x,  y,  z));
    positions.push_back(Vec3f(-x,  y, -z));
    positions.push_back(Vec3f(-x, -y, -z));
    positions.push_back(Vec3f(-x, -y,  z));
    
    normals.push_back(Vec3f(-1, 0, 0));
    normals.push_back(Vec3f(-1, 0, 0));
    normals.push_back(Vec3f(-1, 0, 0));
    normals.push_back(Vec3f(-1, 0, 0));
    
    coords.push_back(Vec2f(0, 0));
    coords.push_back(Vec2f(1, 0));
    coords.push_back(Vec2f(1, 1));
    coords.push_back(Vec2f(0, 1));
    
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 1);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 3);
    
    index ++;
    
    
    //  TOP
    positions.push_back(Vec3f(-x,  y,  z));
    positions.push_back(Vec3f( x,  y,  z));
    positions.push_back(Vec3f( x,  y, -z));
    positions.push_back(Vec3f(-x,  y, -z));
    
    normals.push_back(Vec3f(0, 1, 0));
    normals.push_back(Vec3f(0, 1, 0));
    normals.push_back(Vec3f(0, 1, 0));
    normals.push_back(Vec3f(0, 1, 0));
    
    coords.push_back(Vec2f(0, 0));
    coords.push_back(Vec2f(1, 0));
    coords.push_back(Vec2f(1, 1));
    coords.push_back(Vec2f(0, 1));
    
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 1);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 3);
    
    index ++;
    
    
    //  BOTTOM
    positions.push_back(Vec3f(-x, -y, -z));
    positions.push_back(Vec3f( x, -y, -z));
    positions.push_back(Vec3f( x, -y,  z));
    positions.push_back(Vec3f(-x, -y,  z));
    
    normals.push_back(Vec3f(0, -1, 0));
    normals.push_back(Vec3f(0, -1, 0));
    normals.push_back(Vec3f(0, -1, 0));
    normals.push_back(Vec3f(0, -1, 0));
    
    coords.push_back(Vec2f(0, 0));
    coords.push_back(Vec2f(1, 0));
    coords.push_back(Vec2f(1, 1));
    coords.push_back(Vec2f(0, 1));
    
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 1);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 0);
    indices.push_back(index*4 + 2);
    indices.push_back(index*4 + 3);
    
    index ++;
    
    

    gl::VboMesh mesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferNormals(normals);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
    
    return mesh;
}


Vec3f Geom::_getSpherePos(int i, int j, int num) {
    Vec3f p;
    
    float rx = float(i) / float(num) * M_PI - M_PI * .5;
    float ry = float(j) / float(num) * M_PI * 2.0;
    float radius = 1;
    
    p.y = sin(rx) * radius;
    float r = cos(rx) * radius;
    p.x = cos(ry) * r;
    p.z = sin(ry) * r;
    
    return p;
}


gl::VboMesh Geom::sphere(float size, int segments) {
    return Geom::sphere(size, segments, false);
}


gl::VboMesh Geom::sphere(float size, int segments, bool isInvert) {
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    layout.setStaticNormals();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec3f> normals;
    vector<Vec2f> coords;
    int index = 0;
    
    float gapUV = 1.0 / float(segments);
    
    
    for(int j=0; j<segments; j++) {
        for(int i=0; i<segments; i++) {
            positions.push_back(Geom::_getSpherePos(i, j, segments)*size);
            positions.push_back(Geom::_getSpherePos(i+1, j, segments)*size);
            positions.push_back(Geom::_getSpherePos(i+1, j+1, segments)*size);
            positions.push_back(Geom::_getSpherePos(i, j+1, segments)*size);
            
            normals.push_back(Geom::_getSpherePos(i, j, segments));
            normals.push_back(Geom::_getSpherePos(i+1, j, segments));
            normals.push_back(Geom::_getSpherePos(i+1, j+1, segments));
            normals.push_back(Geom::_getSpherePos(i, j+1, segments));
            
            float u = float(j) / float(segments);
            float v = float(i) / float(segments);
            
            coords.push_back(Vec2f(1.0-u, v));
            coords.push_back(Vec2f(1.0-u, v+gapUV));
            coords.push_back(Vec2f(1.0-u-gapUV, v+gapUV));
            coords.push_back(Vec2f(1.0-u-gapUV, v));
            
            indices.push_back(index*4 + 0);
            indices.push_back(index*4 + 1);
            indices.push_back(index*4 + 2);
            indices.push_back(index*4 + 0);
            indices.push_back(index*4 + 2);
            indices.push_back(index*4 + 3);
            
            index ++;
        }
    }
    
    
    if(isInvert) {
        reverse(indices.begin(), indices.end());
    }
    
    gl::VboMesh mesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferNormals(normals);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
    
    return mesh;
}


gl::VboMesh Geom::plane(float size, int segments) {
    return Geom::plane(size, size, segments);
}


gl::VboMesh Geom::plane(float width, float height, int segments) {
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticTexCoords2d();
    layout.setStaticPositions();
    layout.setStaticNormals();
    
    vector<uint> indices;
    vector<Vec3f> positions;
    vector<Vec3f> normals;
    vector<Vec2f> coords;
    
    int i, j, count = 0;
    float numSeg = segments;
    float segSizeX = width/(float)numSeg;
    float segSizeY = height/(float)numSeg;
    float uvBase = 1.0/numSeg;
    float startPosX = width / 2.0f;
    float startPosY = height / 2.0f;
    
    for(j=0; j<numSeg; j++) {
        for(i=0; i<numSeg; i++) {
            positions.push_back(Vec3f(-startPosX + i*segSizeX,       startPosY - j*segSizeY,   0));
            positions.push_back(Vec3f(-startPosX + (i+1)*segSizeX,   startPosY - j*segSizeY,   0));
            positions.push_back(Vec3f(-startPosX + (i+1)*segSizeX,   startPosY - (j+1)*segSizeY,   0));
            positions.push_back(Vec3f(-startPosX + i*segSizeX,       startPosY - (j+1)*segSizeY,   0));
            
            coords.push_back(Vec2f(uvBase*i, uvBase*j));
            coords.push_back(Vec2f(uvBase*(i+1), uvBase*j));
            coords.push_back(Vec2f(uvBase*(i+1), uvBase*(j+1)));
            coords.push_back(Vec2f(uvBase*i, uvBase*(j+1)));
            
            normals.push_back(Vec3f(0.0, 1.0, 0.0));
            normals.push_back(Vec3f(0.0, 1.0, 0.0));
            normals.push_back(Vec3f(0.0, 1.0, 0.0));
            normals.push_back(Vec3f(0.0, 1.0, 0.0));
            
            indices.push_back(count*4+0);
            indices.push_back(count*4+1);
            indices.push_back(count*4+2);
            indices.push_back(count*4+0);
            indices.push_back(count*4+2);
            indices.push_back(count*4+3);
            
            count++;
        }
    }
    
    gl::VboMesh mesh(positions.size(), indices.size(), layout, GL_TRIANGLES);
    mesh.bufferPositions(positions);
    mesh.bufferNormals(normals);
    mesh.bufferIndices(indices);
    mesh.bufferTexCoords2d(0, coords);
    
    return mesh;
}