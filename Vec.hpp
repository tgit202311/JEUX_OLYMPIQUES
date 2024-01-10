#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED



#include <iostream>
#include <SFML/Graphics.hpp>
#define VECTEUR_NUL Vec(0,0)


class Vec{

	public:
	float x;
	float y;

	Vec();
	Vec(float X,float Y);
	Vec (const Vec &v);
	~Vec();	

	
	// les accesseurs
	float getX();
	float getY();
	// les mutateurs

	void setX(float X);
	void setY(float Y);

	sf::Vector2f toSFML() const;

	float operator*(const Vec &v);
	Vec operator+(const Vec &v);
	Vec operator-(const Vec &v);
	Vec operator/(const float lambda);


};

#endif
