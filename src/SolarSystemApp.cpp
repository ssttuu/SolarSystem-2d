#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SolarSystemApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void SolarSystemApp::setup()
{
}

void SolarSystemApp::mouseDown( MouseEvent event )
{
}

void SolarSystemApp::update()
{
}

void SolarSystemApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( SolarSystemApp, RendererGl )
