#include "cinder/app/AppBasic.h"
#include "cinder/ImageIO.h"
#include "cinder/gl/Texture.h"

#include "SolarSystem.h"

using namespace ci;
using namespace ci::app;

class SolarSystemApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
	void	mouseDown( MouseEvent event );
	void	mouseDrag( MouseEvent event );
    void    mouseUp( MouseEvent event );
	
	gl::Texture mImage;
    
    Vec2i   mPlanetPosition;
    Vec2i   mPlanetDirection;
	
	SolarSystem mSolarSystem;
};

void SolarSystemApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 1920, 1080 );
	settings->setFrameRate( 60.0f );
}

void SolarSystemApp::setup()
{
	mSolarSystem.addPlanets( 30 );
}

void SolarSystemApp::update()
{
	mSolarSystem.update();
}

void SolarSystemApp::draw()
{
	gl::clear( Color( .5, .5, .5 ), true );
	
	glDisable( GL_TEXTURE_2D );
	glColor3f( 1, 1, 1 );
	mSolarSystem.draw();
}

void SolarSystemApp::mouseDown( MouseEvent event )
{
	console() << "Mouse down: " << event.isRight() << " & " << event.isControlDown() << std::endl;
    mPlanetPosition = event.getPos();
}

void SolarSystemApp::mouseDrag( MouseEvent event )
{
	console() << "Mouse drag: " << std::endl;
    mPlanetDirection = event.getPos() - mPlanetPosition;
    glColor3f( 1, 1, 1 );
    ci::gl::drawLine(  mPlanetPosition, event.getPos() );
}

void SolarSystemApp::mouseUp( MouseEvent event )
{
    mSolarSystem.addPlanet( mPlanetPosition, mPlanetDirection / 20.0f );
    mPlanetDirection = Vec2i(0,0);
}

CINDER_APP_BASIC( SolarSystemApp, RendererGl )