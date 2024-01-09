#ifndef CLASSEMENT_H_INCLUDED 
#define CLASSEMENT_H_INCLUDED


#include "Texte.hpp"
#include "Sportif.hpp"
#include "Systeme.hpp"
#include <fstream>

using namespace std;
using namespace sf;
class Classement{
private:

	Texte titre;
	string nomEpreuve;
	int LARGEUR_FENETRE;
	int HAUTEUR_FENETRE;
	vector<Sportif> sportifs;
public:
	Classement(string cheminFichier);
	~Classement();
	void afficher(RenderWindow &fenetre);
};


#endif
