#include "Systeme.hpp"

using namespace std;


void init_dimensions(int &w, int &h){
	const char * chemin = "./settings.txt";
	ifstream fichier(chemin);
	if (!fichier.is_open())
		cout<<"Erreur dans le chargement de "<<chemin<<endl;
	else{
		fichier>>w;
		fichier>>h;
	}
	cout<<w<<endl;
	cout<<h<<endl;


}

