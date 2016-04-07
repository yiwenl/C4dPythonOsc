#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneApp.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class FlockingApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
private:
    SceneApp* _scene;
};

void FlockingApp::setup()
{
    
    gl::enable(GL_DEPTH_TEST);
    gl::enable(GL_CULL_FACE);
    gl::enable(GL_VERTEX_PROGRAM_POINT_SIZE);
    gl::enable(GL_SMOOTH);
    
    _scene = new SceneApp();
}

void FlockingApp::mouseDown( MouseEvent event )
{
}

void FlockingApp::update()
{
}

void FlockingApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    _scene->render();
}

CINDER_APP_NATIVE( FlockingApp, RendererGl )
