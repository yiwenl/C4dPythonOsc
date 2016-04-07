#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneApp.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class DarkForestApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
private:
    SceneApp*   _scene;
};

void DarkForestApp::setup()
{
    setWindowPos(0, 0);
    setWindowSize(1024, 768);
    setFrameRate(60);
    gl::enableAlphaBlending();
    gl::enable(GL_CULL_FACE);
    gl::enable(GL_DEPTH_TEST);
    gl::enable(GL_VERTEX_PROGRAM_POINT_SIZE);
    
    _scene = new SceneApp();
}

void DarkForestApp::mouseDown( MouseEvent event )
{
}

void DarkForestApp::update()
{
}

void DarkForestApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    _scene->render();
}

CINDER_APP_NATIVE( DarkForestApp, RendererGl )
