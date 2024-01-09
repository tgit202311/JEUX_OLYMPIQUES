#ifndef POLAIRE_H_INCLUDED
#define POLAIRE_H_INCLUDED

#include "Vec.hpp"

class Polaire{
private:
	float r;
	float theta;
	public:
	
	Polaire (const Vec &v);
	Vec toVec();
};

#endif
