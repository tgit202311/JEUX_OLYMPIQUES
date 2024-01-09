
//
//  Complex.cpp
//  Troupe
//
//  Created by Mebarka Kouchida on 02/02/2020.
//  Copyright © 2020 yacque. All rights reserved.
//

#include "Complex.hpp"

Complex::Complex()
{
    x=y=0;
}

float Complex::Re(){
    return x;
}
float Complex::Im(){
    return y;
}

Complex::Complex(float a, float b)
{
    x=a;
    y=b;
    
}


Complex & Complex::operator=(const Complex &z)
{
    x=z.x;
    y=z.y;
    return *this;
    
}
Complex & Complex::operator=(const Vec &v)
{
    x=v.x;
    y=v.y;
    return *this;
    
}
Complex & Complex::operator+=(const Complex & z){
    x+=z.x;
    y+=z.y;
    return *this;
}
Complex & Complex::operator-=(const Complex & z){
    x-=z.x;
    y-=z.y;
    return *this;
}
Complex Complex::conjugue() const{
    return Complex(x,-y);
}
Complex & Complex::operator*=(const Complex & z){
    float a = x;
    float b = y;
    float c = z.x;
    float d = z.y;
    x = a*c-b*d;
    y = a*d + b*c;
    return *this;
}
Complex &Complex::operator/=(const Complex & z){
    float a = x;
    float b = y;
    float c = z.x;
    float d = z.y;
    x = a*c+b*d;
    y = b*c-a*d;
    x/=z.norme_carre();
    y/=z.norme_carre();
    return *this;
}

Complex::Complex(const Complex &z)
{
    *this=z;
}
Complex::Complex(const Vec& v){
    x = v.x;
    y = v.y;
}
Complex Complex::operator*(const Complex &z)
{
    Complex resultat = *this;
    resultat*=z;
    return resultat;
}
Complex Complex::operator+(const Complex &z)
{
    Complex w(z.x+x,y+z.y);
    return w;
}

Complex Complex::operator-(const Complex &z){
    Complex w(x-z.x,y-z.y);
    return w;
}


Complex Complex::operator/(const Complex &z)
{
    Complex resultat = *this;
    resultat/=z;
    return resultat;
}

Complex Complex::operator+(float f)
{
    Complex resultat(x+f,y);
    return resultat;
}

Complex Complex::operator-(float f)
{
    Complex resultat(x-f,y);
    return resultat;
}
Complex Complex::operator*(float f)
{
    Complex resultat(x*f,y*f);
    return resultat;
}
Complex Complex::operator/(float f)
{
    Complex resultat(x/f,y/f);
    return resultat;
}
Vec Complex::toVec(){
    return Vec(x,y);
}



Complex Integrale(float a, float b, Complex (*fonction)(float),float N ){
        
        Complex resultat =Complex(0,0);
        /*
         
         On intègre la partie réelle d'abord
         
         */
 
    if(a<b)
    {
        /// La methode des rectangles
        for(int k = 1; k<=N; k++){
            resultat+=fonction(a + (float)k*(b-a)/N)*(b-a)/N;
            
        }
        return resultat;
    }
    else
        return Integrale(b, a, fonction);
    
    
    
    
}
Complex operator/(float f,const  Complex &c){
    Complex resultat(c);
    resultat = Complex(f*c.x,-f*c.y)/(c.norme_carre());
    return Complex(0,0);
}
Complex derivee(Complex (*fonction)(float),float x, float h){
    
    return (fonction(x+h)-fonction(x-h))/(2*h);
}

Complex Indice(Complex z, Complex (*lacet)(float),float N){
    Complex resultat =Complex(0,0);
    for(int k = 0; k<=N; k++){
        float x = (float)k/N;
        resultat+=(1.0/N)*derivee(lacet, x,1.0/N)/((lacet(x)-z));
    }
    return resultat/Complex(0,2*M_PI);
}


Complex composition(Complex (*f)(Complex), Complex(*g)(float),float t){
    return f(g(t));
}


Complex isobarycentre(Complex (*courbe)(float t), float N){
    
    Complex resultat;
    /*
     N+1 Iterations
     */
    
    for(float k = 0; k<= N; k++){
        float t = k/N;
        resultat+=courbe(t);
    }
    resultat/=(N+1);
    return resultat;
}

Complex & Complex::operator+=(float f){
    x/=f;
    y/=f;
    return *this;
}
Complex & Complex::operator-=(float f){
    x-=f;
    y-=f;
    return *this;
}
Complex & Complex::operator*=(float f){
    x*=f;
    y*=f;
    return *this;
}
Complex & Complex::operator/=(float f){
    x/=f;
    y/=f;
    return *this;
}
Complex operator*(float f,const  Complex &c){
    return Complex(f*c.x,f*c.y);
    }
bool collision_lacet(Complex z, Complex(*lacet)(float),float N){
    return Indice(z,lacet,N).norme_carre()>=0.5;
}

float param_proche(Complex z, Complex(*lacet)(float),float N){
    float resultat = (z-lacet(0)).norme();
    float t = 0;
    for(int k = 0; k<=N;k++){
        float x = (float)k/N;
        float module = (lacet(x)-z).norme();
        if (module < resultat){
            resultat = module;
            t = x;
        }
            
    }
    return t;
    
}


 Complex Complex::exp(float alpha){
    return Complex(cos(alpha),sin(alpha));
}
