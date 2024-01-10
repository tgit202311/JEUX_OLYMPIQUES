#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <fstream>
#include "Vec.hpp"
#include "Texte.hpp"
#include "Classement.hpp"
#include "Systeme.hpp"
#include "Polaire.hpp"
using namespace std;
using namespace sf;

void drawPhryges(RenderWindow & fenetre, Sprite * phryges, const int NB_PHRYGES){
	for(int i = 0; i < NB_PHRYGES;i++){
		fenetre.draw(phryges[i]);
	}
}
void freePhryges(Sprite *phryges, Texture *texturePhryges){
	delete [] phryges;
	phryges = NULL;
	delete [] texturePhryges;
	texturePhryges = NULL;
}
int main(int argc, char ** argv){
	
	int LARGEUR_FENETRE = 640;
	int HAUTEUR_FENETRE = 480;
	const int NB_PHRYGES =  4;
	Texture * texturePhryges = new Texture [NB_PHRYGES];
	Sprite * phryges = new Sprite [NB_PHRYGES];
	for(int i = 0; i< NB_PHRYGES;i++){
		 string chemin = "ressources/phryge"+to_string(i+1)+".png";
		cout<<chemin<<endl;
		if(!texturePhryges[i].loadFromFile(chemin)){
			cout<<"Erreur dans le chargement de la phryge : "<<chemin<<endl;
		}
		else{
			cout<<"Ouverture de la phryge effectuee avec succes: !"<<chemin<<endl;
		}
		phryges[i].setTexture(texturePhryges[i]);
		phryges[i].setScale(Vector2f(0.3,0.3));
	}
	Polaire X(100, -PI/2.0);
	Vec position(1,2);
	init_dimensions(LARGEUR_FENETRE,HAUTEUR_FENETRE);

	const string chemin_texture = "ressources/logo.png";
	Texture texture_logo;
	if(!texture_logo.loadFromFile(chemin_texture)){
		cout<<"Erreur dans le chargement de la texture : "<<chemin_texture<<endl;
		
	}
	Sprite logo(texture_logo);
	RenderWindow fenetre(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE), "Jeux Olympiques");
	Event evenement;

	Font police;
	if(!police.loadFromFile("ressources/police/police.ttf")){
		cout<<"Erreur dans le chargement de la police !"<<endl;


	}
	string cheminPolice = "ressources/police/police.ttf";
	string valeurTitre ="Rankings";
	Texte titre(valeurTitre,24, cheminPolice,Vec(LARGEUR_FENETRE/2,10));
	Texte secondaire(titre);
	secondaire+=Vec(0,10);
	string cheminClassement = "ressources/classement.txt";
	

	
	float facteur=0.0;
	Classement classement("ressources/classement.txt");
	Clock horloge;
	
	logo.setPosition(Vector2f(LARGEUR_FENETRE/19,HAUTEUR_FENETRE/2));

	logo.setScale(Vector2f(0.2,0.2));
	logo.setOrigin(logo.getTexture()->getSize().x*logo.getScale().x/2,logo.getTexture()->getSize().y/2);

	horloge.restart();
	titre.setCouleur(Color(0,0,199));
	titre.setPosition(Vec(LARGEUR_FENETRE/2-100,10));
	while(fenetre.isOpen()){
		while(fenetre.pollEvent(evenement)){
			if(evenement.type == Event::Closed){
				fenetre.close();

			}
			if(Keyboard::isKeyPressed(Keyboard::Escape)){
				fenetre.close();
			}
		}

		facteur = abs(cos(horloge.getElapsedTime().asSeconds()));
		
		fenetre.clear(Color(255,255,255));

		for(int i = 0; i< NB_PHRYGES;i++){
				Polaire P(LARGEUR_FENETRE/8,horloge.getElapsedTime().asSeconds()*0.1+(float)3*i/(2*PI));
			phryges[i].setPosition((P.toVec()+Vec(LARGEUR_FENETRE/8,HAUTEUR_FENETRE/2)).toSFML());
		}
				fenetre.draw(logo);	
		drawPhryges(fenetre, phryges, NB_PHRYGES);
		titre.afficher(fenetre);

		classement.afficher(fenetre);
		fenetre.display();
	}
	
	freePhryges(phryges, texturePhryges);
	
	cout<<"PROJET JEUX OLYMPIQUES"<<endl;
	return 0;
}

