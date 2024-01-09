#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#include "Vec.hpp"

/*
	La classe Matrice
	qui permet de positionner des elements à l'ecran
*/

class Matrice{
	float a;
	float b;
	float c;
	float d;
	
	float determinant();
	float trace();
	virtual void afficher() = 0;
	virtual void enregistrer() =0;
	Matrice();
	Matrice(float A,float B,float C,float D);
	~Matrice();
	Matrice(const Matrice &M);
	
	Vec operator*(const Vec &v);
};

#endif
