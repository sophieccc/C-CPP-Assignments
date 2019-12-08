/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes
    const int DEFAULT_SPACE = 5;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
    nombreDeTrajets = 0;
    space = DEFAULT_SPACE;
    trajets = new Trajet*[space];
#endif
} //----- Fin de Catalogue

Catalogue::Catalogue(Trajet** content, int nombre) {
    nombreDeTrajets = nombre;
    trajets= new Trajet*[nombreDeTrajets];
    for(int i=0; i < nombreDeTrajets; i++) {
        trajets[i] = content[i];
    }
}

void Catalogue::Ajouter(Trajet* newTrajet) {
    if(nombreDeTrajets==space) {
        Trajet** temp = trajets;
        space = nombreDeTrajets+DEFAULT_SPACE;
        trajets = new Trajet*[space];
        for(int i=0; i < nombreDeTrajets;i++) {
            trajets[i] = temp[i];
        }
    }
    trajets[nombreDeTrajets] = newTrajet;
    nombreDeTrajets++;
}

void Catalogue::Afficher() const {
    for(int i=0; i < nombreDeTrajets;i++) {
        Trajet *curr = trajets[i];
        curr->Afficher();
    }
}

void Catalogue::Rechercher(char* depart, char* arrive) const {
    int count = 1;
    for(int i=0; i < nombreDeTrajets;i++) {
        if(strcmp(trajets[i]->GetDepart(),depart)==0 
        && strcmp(trajets[i]->GetArrive(),arrive)==0) {
            cout << "Found Trajet " << count << "--\n";
            trajets[i]->Afficher();
            count++;
        }
    }
}


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete[] trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
