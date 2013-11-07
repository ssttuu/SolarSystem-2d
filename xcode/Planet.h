//
//  Planet.h
//  SolarSystem
//
//  Created by Stu Schwartz on 11/6/13.
//
//

#pragma once

#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Font.h"
#include "cinder/Path2d.h"
#include "cinder/Color.h"

#include <vector>

class Planet {
public:
	Planet();
	Planet( ci::Vec2f loc);
    Planet( ci::Vec2f loc, ci::Vec2f dir );

	void update();
	void draw();
    ci::Vec2f getVelocity();
    void setVelocity( ci::Vec2f newVelocity );
    float getMass();
    void setMass( float newMass );
    ci::Vec2f getPosition();
    void setPosition( ci::Vec2f newPosition );
    void setDirection(ci::Vec2f newDirection);
    void addForce( float magnitude, ci::Vec2f direction );
    void archive();

	ci::Vec2f	mLoc;
	ci::Vec2f	mVel;
    ci::Vec2f   mDir;
    std::vector<ci::Vec2f>  mHistory;

	float		mRadius;
    float       mMass;

    ci::Path2d  mPath;
    ci::Color   mColor;
};