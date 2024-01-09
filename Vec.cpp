#include "Vec.hpp"



Vec::Vec(){
	x = 0;
	y = 0;
}


Vec::Vec(float X,float Y){
	x = X;
	y = Y;
}
Vec::Vec (const Vec &v){
	x = v.x;
	y=v.y;
}
Vec::~Vec(){
	x =0.0;
	y = 0.0;
}

	
	// les accesseurs
float Vec::getX(){
	return x;
}
float Vec::getY(){
return y;
}
// les mutateurs

void Vec::setX(float X){
	x = X;
}
void Vec::setY(float Y){
	y=Y;
}

sf::Vector2f Vec::toSFML() const{
	return sf::Vector2f(x,y);
}

float Vec::operator*(const Vec &v){
	return x*v.x + y*v.y;
}
Vec Vec::operator+(const Vec &v){
	return Vec(x+v.x,y+v.y);

}
Vec Vec::operator-(const Vec &v){
	return Vec(x-v.x,y-v.y);
}
Vec Vec::operator/(const float lambda){
	return Vec(x/lambda,y/lambda);
}




