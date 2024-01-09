#ifndef SPORTIF_H_INCLUDED
#define SPORTIF_H_INCLUDED
#include <string>
#include <iostream>


using namespace std;

class Sportif{
protected:
	string nom;
	string prenom;
	float score;
	

public:

	Sportif();
	Sportif(string N, string P, float S);
	Sportif(const Sportif &S);
	
	string getNom();
	string getPrenom();
	float getScore();
	
	void setNom(string N);
	void setPrenom(string P);
	void setScore(float S);
		    
	friend ostream& operator<<(ostream &os, const Sportif &S);
	
	~Sportif();
};

#endif
