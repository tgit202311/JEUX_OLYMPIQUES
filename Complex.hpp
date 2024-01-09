//
//  Complex.hpp
//  Troupe
//
//  Created by Mebarka Kouchida on 02/02/2020.
//  Copyright © 2020 yacque. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include "Vec.hpp"
#include "Integrale.hpp"
class Complex:public Vec
{
public:
    float Re(); 
    float Im();
    Complex conjugue() const;
    Complex();
    Complex(float a, float b);// A faire
    Complex (const Complex &z);// A faire
    Complex (const Vec &v);// A faire
    static Complex exp(float alpha);
    
    Complex & operator+=(const Complex & z);
    Complex & operator-=(const Complex & z);
    Complex & operator*=(const Complex & z);
    Complex & operator/=(const Complex & z);
    
    Complex  operator+(const Complex & z);
    Complex  operator-(const Complex & z);
    Complex  operator*(const Complex & z);
    Complex  operator/(const Complex & z);

    
    Complex & operator+=(float f);
    Complex & operator-=(float f);
    Complex & operator*=(float f);
    Complex & operator/=(float f);
    
    Complex  operator+(float f);
    Complex  operator-(float f);
    Complex  operator*(float f);
    Complex  operator/(float f);


    Vec toVec();
    friend std::ostream& operator<<(std::ostream &flux, const Complex &le)// A faire
    {
        
        if (le.y!=0 && le.x ==0)
        flux<<le.y<<"i";
        
            flux<<le.x;
            char operateur = le.y > 0 ? '+' : '-';
            flux<<" "<<operateur<<" "<<abs(le.y)<<"i";
        
       
        return flux;
    }
    Complex & operator=(const Complex &z);// A faire
    Complex & operator=(const Vec &v);// A faire



};

Complex operator/(float f,const  Complex &c);
Complex operator*(float f,const  Complex &c);

// Integrale d'une fonction de R dans C
Complex Integrale(float a, float b, Complex (*fonction)(float),float N =100);
Complex Indice(Complex z, Complex (*chemin)(float),float N=100);
Complex derivee(Complex (*fonction)(float),float x, float h=0.1);
Complex composition(Complex (*f)(Complex), Complex(*g)(float),float t);

Complex isobarycentre(Complex (*courbe)(float), float N=100);
bool collision_lacet(Complex z, Complex(*lacet)(float),float N=100);
float param_proche(Complex z, Complex(*lacet)(float),float N);
#endif /* Complex_hpp */
