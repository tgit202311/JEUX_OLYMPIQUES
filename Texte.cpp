#include "Texte.hpp"

using namespace std;
using namespace sf;


Texte::Texte(){

	const int LARGEUR_FENETRE=1280;
	const int HAUTEUR_FENETRE=720;
	
	if(!police.loadFromFile("ressources/police/police.ttf")){
		cout<<"Erreur dans le chargement de la police !"<<endl;
		

	}	
	valeur.setFont(police);
	string valeurTitre ="classement";
	valeur.setString("Classement");
	valeur.setCharacterSize(24);
	valeur.setFillColor(Color::White);
	valeur.setStyle(Text::Bold);
	valeur.setPosition(Vector2f(LARGEUR_FENETRE/2 - valeurTitre.length()*6,10));

}

Texte::~Texte(){
}
Texte::Texte(string Valeur, const Vec &Position):Texte(){
	setPosition(Position);
	valeur.setString(Valeur);
	
}
Texte::Texte(string Valeur, unsigned short int taille, string fontPath,const Vec &Position):Texte(){

	if(!police.loadFromFile(fontPath)){
		cout<<"Erreur dans le chargement de la police !"<<endl;
		

	}	
	valeur.setFont(police);

	setPosition(Position);
	valeur.setString(Valeur);
	valeur.setCharacterSize(taille);


}

Texte::Texte(const Texte &T){
	taillePolice=T.taillePolice;
	setPosition(T.position);
	police=Font(T.police);
	valeur=Text(T.valeur);
	horloge=Clock(T.horloge);
}

unsigned short int Texte::getTaillePolice(){
	return valeur.getScale().x;
}

	const Vec & Texte::getPosition(){
		return position;
	}
	const sf::Font & Texte::getFont(){
		return police;	
	}
	const sf::Text & Texte::getValeur(){
		return valeur;
	}
	const Clock & Texte::getHorloge(){
		return horloge;
	}

	void Texte::setTaillePolice(unsigned short int tp){
		taillePolice=tp;
		valeur.setCharacterSize(tp);
	}
	void Texte::setPosition(const Vec &P){
		position=  P;	
		valeur.setPosition(P.toSFML());
	}
	void Texte::setPolice(const Font &p){
		police = p;
	}

	void Texte::setValeur(Text v){
		valeur = Text(v);
	}
	void Texte::setValeur(string v){
		valeur.setString(v);
	}
	void Texte::setHorloge(const Clock &H){
		horloge = H;
	}

	void Texte::afficher(RenderWindow &fenetre){
		fenetre.draw(valeur);
	}


	void Texte::operator+=(const Vec &v){
		setPosition(position+v);
	}
	
	void Texte::setCouleur(const Color &couleur){
		valeur.setFillColor(couleur);
	}
	
	Texte & Texte::operator=(const Texte &T){
		 taillePolice=T.taillePolice;
	 police = Font(police);
	 valeur= Text(T.valeur);
	 setPosition(T.position);
	horloge = Clock(horloge);

	return *this;
	}
