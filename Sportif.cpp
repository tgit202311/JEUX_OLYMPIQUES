#include "Sportif.hpp"
using namespace std;

	Sportif::Sportif(){
	nom = "XXX";
	prenom = "YYY";
	score = 0.0f;
	}
	Sportif::Sportif(string N, string P, float S)
	{
		nom = N;
		prenom = P;
		score = S;
		
	}
	Sportif::Sportif(const Sportif &S)
	{
		nom = S.nom;
		prenom = S.prenom;
		score = S.score;	
	}
	
	string Sportif::getNom(){
		return nom;
	}
	string Sportif::getPrenom(){
	return prenom;
	}
	float Sportif::getScore(){
		return score;
	}
	
	Sportif::~Sportif(){
		nom= "XXX";
		prenom ="YYY";
		score = 0.0;
	}

ostream & operator<<(ostream &os, const Sportif &S){
	os<<"Nom: "<<S.nom<<endl;
	os<<"Prenom: "<<S.prenom<<endl;
	os<<"Score: "<<S.score<<endl;
	return os;
}
	




