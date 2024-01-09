#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <fstream>
#include "Vec.hpp"
#include "Texte.hpp"
#include "Classement.hpp"
#include "Systeme.hpp"


using namespace std;
using namespace sf;



int main(int argc, char ** argv){
	
	int LARGEUR_FENETRE = 640;
	int HAUTEUR_FENETRE = 480;
	Vec position(1,2);
	init_dimensions(LARGEUR_FENETRE,HAUTEUR_FENETRE);

	const string chemin_texture = "ressources/logo.png";
	Texture texture_logo;
	if(!texture_logo.loadFromFile(chemin_texture)){
		cout<<"Erreur dans le chargement de la texture : "<<chemin_texture<<endl;
		exit(EXIT_FAILURE);
	}

	RenderWindow fenetre(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE), "Jeux Olympiques");
	Event evenement;

	Font police;
	if(!police.loadFromFile("ressources/police/police.ttf")){
		cout<<"Erreur dans le chargement de la police !"<<endl;
		exit(EXIT_FAILURE);

	}
	string cheminPolice = "ressources/police/police.ttf";
	string valeurTitre ="Classement";
	Texte titre(valeurTitre,24, cheminPolice,Vec(LARGEUR_FENETRE/2,10));
	Texte secondaire(titre);
	secondaire+=Vec(0,10);
	string cheminClassement = "ressources/classement.txt";
	

	
	float facteur=0.0;
	Classement classement("ressources/classement.txt");
	Clock horloge;
	horloge.restart();
	while(fenetre.isOpen()){
		while(fenetre.pollEvent(evenement)){
			if(evenement.type == Event::Closed){
				fenetre.close();

			}
		}

		facteur = abs(cos(horloge.getElapsedTime().asSeconds()));
		if(horloge.getElapsedTime().asSeconds()<3.14+1.552)
		fenetre.clear(Color(25+facteur*100,180,111));
		else
		fenetre.clear(Color(25,180,111));
		//fenetre.draw(titre);
		
		secondaire.afficher(fenetre);
		classement.afficher(fenetre);
		fenetre.display();
	}

	cout<<"PROJET JEUX OLYMPIQUES"<<endl;
	return 0;
}

