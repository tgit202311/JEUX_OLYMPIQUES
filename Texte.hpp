#ifndef TEXTE_H_INCLUDED
#define TEXTE_H_INCLUDED


#include <SFML/Graphics.hpp>
#include "Vec.hpp"

using namespace std;
using namespace sf;

class Texte{
protected:
	unsigned short int taillePolice;
	Vec position;
	Font police;
	Text valeur;
	Clock horloge;
	public:
	
	Texte();
	Texte(string Valeur, const Vec &Position);
	
	
	Texte(string Valeur,unsigned short int taille, string fontPath, const Vec &Position);
	Texte(const Texte &T);
	~Texte();

	unsigned short int getTaillePolice();
	const Vec & getPosition();
	const sf::Font & getFont();
	const sf::Text & getValeur();
	const Clock & getHorloge();

	void setTaillePolice(unsigned short int tp);
	void setPosition(const Vec &P);
	void setPolice(const Font &p);
	void setValeur(Text v);
	void setValeur(string v);
	void setHorloge(const Clock &H);
	
	void setCouleur(const Color &couleur);

	void afficher(RenderWindow &fenetre);

	void operator+=(const Vec &v);
	 Texte & operator=(const Texte &T);




};

#endif
