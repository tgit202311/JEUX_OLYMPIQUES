#include "Polaire.hpp"


	Polaire::Polaire (const Vec &v){
		r = sqrt(v.x*v.x + v.y*v.y);
		float x = v.x;
		float y = v.y;
		theta = atan(y/x)*(abs(x) > 0) 
		+ 2*PI*(y<0) 
		+ PI*(x<0)+(PI/2)*(x==0 && y> 0) 
		+ (3*PI/2)*(x==0 + y < 0);
	}
	
	Vec Polaire::toVec(){
		return Vec(r*cos(theta), r*sin(theta));
	}
		
	Polaire::Polaire(){
		r = 1;
		theta = 0.0;
	}
	Polaire::~Polaire(){
		r = 0;
		theta = 0.0;
	}

Polaire::Polaire(float R, float Theta){
	r = R;
	theta = Theta;
}
	
