//
//  SolarSystem.cpp
//  SolarSystem
//
//  Created by Stu Schwartz on 11/6/13.
//
//

#include "SolarSystem.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"

#include <math.h>

using namespace ci;
using std::list;


SolarSystem::SolarSystem() {}

void SolarSystem::update()
{
    int i = 0;
    for( list<Planet>::iterator p = mPlanets.begin(); p != mPlanets.end(); ++p ){
        //Vec2f tmpVelocity = p->getVelocity();
        Vec3f tmpValues;
        float newForce;
        
        int j = 0;
        for( list<Planet>::iterator n = mPlanets.begin(); n != mPlanets.end(); ++n ){
            if (i == j) {
                j++;
                continue;
            }
            
            tmpValues = SolarSystem::calculateDirection( &*p, &*n);
            newForce = SolarSystem::gravity * ((p->getMass() * n->getMass()) / tmpValues[0]);
            p->addForce( newForce, Vec2f(tmpValues[1], tmpValues[2]) );
            
            j++;
        }
        
        p->update();
        
        if (ci::app::getElapsedFrames() % 2 == 0) {
            p->archive();
        }
        
        i++;
    }
}

void SolarSystem::draw()
{
	for( list<Planet>::iterator p = mPlanets.begin(); p != mPlanets.end(); ++p ){
		p->draw();
	}
}

void SolarSystem::addPlanet( Vec2i pos ) {
    mPlanets.push_back(Planet(pos));
}

void SolarSystem::addPlanet( Vec2i pos, Vec2i dir ) {
    mPlanets.push_back(Planet(pos, dir));
}

void SolarSystem::addPlanets( int amt )
{
	for( int i=0; i<amt; i++ )
	{
		float x = Rand::randFloat( app::getWindowWidth() );
		float y = Rand::randFloat( app::getWindowHeight() );
		mPlanets.push_back( Planet( Vec2f( x, y ) ) );
	}
}

void SolarSystem::removePlanets( int amt )
{
	for( int i=0; i<amt; i++ )
	{
		mPlanets.pop_back();
	}
}

Vec3f SolarSystem::calculateDirection( Planet* p1, Planet* p2 ) {
    Vec2f direction = Vec2f( p2->getPosition()[0] - p1->getPosition()[0], p2->getPosition()[1] - p1->getPosition()[1]);
    //std::cout << p2->getPosition() << std::endl;
    //std::cout << p1->getPosition() << std::endl;
    //std::cout << direction << std::endl;
    
    float distance = sqrt( pow(direction[0], 2.0f)+pow(direction[1], 2.0f) );
    return Vec3f(distance,direction[0],direction[1]);
}