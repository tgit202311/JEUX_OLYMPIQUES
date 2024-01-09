#include "Matrice.hpp"

		
	float Matrice::determinant(){
		return a*d - b*c;
		
	}
	float Matrice::trace(){
		return a+d;
	}
	Matrice::Matrice(){
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}
	
	Matrice::Matrice(float A,float B,float C,float D){
		a=A;
		b=B;
		c=C;
		d=D;
		
	}
	Matrice::~Matrice(){
		a=0;
		b=0;
		c=0;
		d=0;
	}
	Matrice::Matrice(const Matrice &M){
		a=M.a;
		b=M.b;
		c=M.c;
		d=M.d;
	}
	
	Vec Matrice::operator*(const Vec &v){
		return Vec(a*v.x + b*v.y, c*v.x + d*v.y);
	}

