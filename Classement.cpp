#include "Classement.hpp"

Classement::Classement(string cheminFichier){
	
	init_dimensions(LARGEUR_FENETRE,HAUTEUR_FENETRE);
	string nom;
	string prenom;
	float score;
	ifstream fichier(cheminFichier);
	
	if(!fichier.is_open()){
		cout<<"Erreur dans l'ouverture du fichier de classement"<<cheminFichier<<endl;
	}
	else{
		cout<<"Fichier de classements : "<<cheminFichier<<" ouvert avec succes"<<endl;
		
	}
	while(!fichier.eof())
	{
		fichier>>nom;
		fichier>>prenom;
		fichier>>score;
		Sportif current_sportif = Sportif(nom,prenom,score);
		cout<<current_sportif<<endl;
		sportifs.push_back(Sportif(nom,prenom,score));
		
	}
	
}
	Classement::~Classement(){
		
	}
	void Classement::afficher(RenderWindow &fenetre){
	Texte nom;
	Texte prenom;
	Texte score;
	float ratio = 150.0/720.0;
	int X_debut = LARGEUR_FENETRE/2-(1.0/6.0)*LARGEUR_FENETRE;
	int Y_debut =  100;
	
	for(int i = 0; i< sportifs.size()-1;i++)
	{
		Sportif courant(sportifs[i]);
		float offset_y = i*100;
		string suffixe = "th";
		if(i+1 == 1)
		suffixe= "st";
		else if (i+1 == 2)
		suffixe= "nd";
		else if (i+1 == 3)
		suffixe= "rd";
		Texte nom (courant.getNom(), Vec(X_debut,Y_debut+offset_y));
		Texte prenom(courant.getPrenom(), Vec(X_debut+(1.0/6.0)*LARGEUR_FENETRE,Y_debut+offset_y));
	  	Texte score(to_string((int)courant.getScore())+suffixe, Vec(X_debut+(2.0/6.0)*LARGEUR_FENETRE,Y_debut+offset_y));
		
		nom.setCouleur(Color(199,0,55));
		nom.afficher(fenetre);
		prenom.setCouleur(Color(0,0,0));
		prenom.afficher(fenetre);
		if(i<3)
		score.setCouleur(Color(0,199,55));
		else 
		score.setCouleur(Color(230,170,20));
		score.afficher(fenetre);

		
	}
		
	}

