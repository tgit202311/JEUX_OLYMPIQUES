all : jeux

jeux: main.o Vec.o Texte.o Sportif.o Systeme.o Classement.o Matrice.o Polaire.o
	g++ main.o Vec.o Texte.o Sportif.o Classement.o Systeme.o Matrice.o Polaire.o -o jeux -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	g++ -c main.cpp -o main.o

Classement.o:
	g++ -c Classement.cpp -o Classement.o
Sportif.o:
	g++ -c Sportif.cpp -o Sportif.o

Texte.o: 
	g++ -c Texte.cpp -o Texte.o

Vec.o:
	g++ -c Vec.cpp -o Vec.o

Systeme.o:
	g++ -c Systeme.cpp -o Systeme.o

Matrice.o:
	g++ -c Matrice.cpp -o Matrice.o

Polaire.o:
	g++ -c Polaire.cpp -o Polaire.o

clean:
	rm *.o

