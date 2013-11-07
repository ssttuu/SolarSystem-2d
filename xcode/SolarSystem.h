//
//  SolarSystem.h
//  SolarSystem
//
//  Created by Stu Schwartz on 11/6/13.
//
//

#pragma once

#include "cinder/Vector.h"
#include <list>

#include "Planet.h"

class SolarSystem {
public:
    float gravity = 0.0001;
	SolarSystem();

	void update();
	void draw();

    void addPlanet( ci::Vec2i pos );
    void addPlanet( ci::Vec2i pos, ci::Vec2i dir );
	void addPlanets( int amt );
	void removePlanets( int amt );

    ci::Vec3f calculateDirection( Planet *p1, Planet *p2);

	std::list<Planet>	mPlanets;
};
