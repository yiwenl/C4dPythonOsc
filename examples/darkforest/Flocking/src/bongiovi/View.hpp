//
//  View.hpp
//  BasicTemplate
//
//  Created by Yi-Wen Lin on 2016/4/1.
//
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Vbo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace bongiovi {
    class View {
        public:
        
        View() {
            _vsPath = "shaders/basic.vert";
            _fsPath = "shaders/basic.frag";
            
            _initShader();
        };
        
        View(string vsPath, string fsPath) : _vsPath(vsPath), _fsPath(fsPath) {
            _initShader();
        };
        
        gl::GlslProg*   shader;
        gl::VboMesh     mesh;
        string          _vsPath;
        string          _fsPath;
        
        private:
        
        void    _initShader() {
            
            try {
                shader = new ci::gl::GlslProg( loadResource(_vsPath), loadResource(_fsPath) );
            }
            catch( gl::GlslProgCompileExc &exc ) {
                console() << "Cannot compile shader: " << exc.what() << std::endl;
                exit(1);
            }
            catch( Exception &exc ){
                console() << "Cannot load shader: " << exc.what() << std::endl;
                exit(1);
            }
            cout << "Creating shader program : " << _vsPath << ", " << _fsPath << endl;

        }
    };
}

#endif /* View_hpp */
