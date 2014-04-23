//
//  Planet.cpp
//  SolarSystem
//
//  Created by Stu Schwartz on 11/6/13.
//
//

#include "Planet.h"

#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Text.h"
#include "cinder/Font.h"
#include "cinder/Path2d.h"

#include <vector>

using namespace ci;

Planet::Planet()
{
}

Planet::Planet( Vec2f loc )
{
	mLoc	= loc;
	mVel	= Rand::randVec2f() * 0.0f;
    mMass   = Rand::randFloat(9.0f) + 1;
    float cr = (Rand::randFloat() * .5) + .5;
    float cg = (Rand::randFloat() * .5) + .5;
    float cb = (Rand::randFloat() * .5) + .5;
    mColor  = ci::Color( cr, cg, cb );
}

Planet::Planet( Vec2f loc, Vec2f dir )
{
	mLoc	= loc;
	mVel	= dir;
    mMass   = Rand::randFloat(9.0f) + 1;
    float cr = (Rand::randFloat() * .5) + .5;
    float cg = (Rand::randFloat() * .5) + .5;
    float cb = (Rand::randFloat() * .5) + .5;
    mColor  = ci::Color( cr, cg, cb );
}


void Planet::update()
{
	mLoc += mVel;
    
    //if (mHistory.size() >= 200) {
    //    mHistory.erase(mHistory.begin());    }
    
    mPath.clear();
    
    int i = 0;
    for( std::vector<Vec2f>::iterator pt = mHistory.begin(); pt != mHistory.end(); ++pt ){
        if(i==0) mPath.moveTo(*pt);
        mPath.lineTo(*pt);
        i++;
    }
}

void Planet::draw()
{
    glColor3f( mColor );
    gl::draw( mPath );
	gl::drawSolidCircle( mLoc, mMass);
    
}

Vec2f Planet::getVelocity() {
    return mVel;
}

void Planet::setVelocity( Vec2f newVelocity ) {
    mVel = newVelocity;
}

float Planet::getMass() {
    return mMass;
}

void Planet::setMass(float newMass) {
    mMass = newMass;
}

Vec2f Planet::getPosition() {
    return mLoc;
}

void Planet::setDirection(Vec2f newDirection) {
    mDir = newDirection;
}

void Planet::setPosition( Vec2f newPosition) {
    mLoc = newPosition;
}

void Planet::addForce(float magnitude, ci::Vec2f direction) {
    mVel = Vec2f(mVel[0] + (direction[0] * magnitude), mVel[1] + (direction[1] * magnitude));
    //std::cout << mVel << std::endl;
}

void Planet::archive() {
    mHistory.push_back( Vec2f(mLoc) );
}