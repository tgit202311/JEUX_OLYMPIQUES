#ifndef POLAIRE_H_INCLUDED
#define POLAIRE_H_INCLUDED

#include "Vec.hpp"
#include <math.h>

#define PI M_PI

class Polaire{
public:
	float r;
	float theta;
	public:
	
	Polaire (const Vec &v);
	Polaire();
	~Polaire();
	Polaire(float R, float Theta);
	
	Vec toVec();
};

#endif
