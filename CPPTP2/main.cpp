#include <iostream>
using namespace std;

#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

int main() {
    TrajetSimple one = TrajetSimple((char *)"Dublin", (char *)"Lyon", (char *)"avion", false);
    TrajetSimple two = TrajetSimple((char *)"Lyon", (char *)"Dublin", (char *)"avion", false);
    TrajetSimple three = TrajetSimple((char *)"Dublin", (char *)"Paris", (char *)"bateau", false);
    TrajetSimple four = TrajetSimple((char *)"Berlin", (char *)"Munich", (char *)"voiture", false);
    TrajetSimple five = TrajetSimple((char *)"Barcelona", (char *)"Munich", (char *)"train", false);

    TrajetSimple** once = new TrajetSimple*[2];
    once[0] = &one;
    once[1] = &two;
    TrajetComplexe complexOne = TrajetComplexe(once, 2, true);

    Trajet** twice = new Trajet*[2];
    twice[0] = &three;
    twice[1] = &four;

    Catalogue current = Catalogue(twice, 2);
    current.Afficher(0, current.nombreDeTrajets);
    cout << "adding five" << "\n";
    current.Ajouter(&five);
    cout << "added five" << "\n";
    current.Afficher(0, current.nombreDeTrajets); 
    current.Rechercher((char *)"Berlin", (char *)"Munich");
    current.Rechercher((char *)"Dublin", (char *)"Paris");
    current.Ajouter(&complexOne);
    current.Afficher(0, current.nombreDeTrajets); 
    current.Rechercher((char *)"Dublin", (char *)"Dublin");
    return 0;

}