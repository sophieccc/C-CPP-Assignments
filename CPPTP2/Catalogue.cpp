/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley$
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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
} //----- Fin de operator =


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
#endif
} //----- Fin de Catalogue

Catalogue::Catalogue(Trajet** content, int nombre) {
    nombreDeTrajets = nombre;
    trajets= new Trajet*[nombreDeTrajets];
    for(int i=0; i < nombreDeTrajets; i++) {
        trajets[i] = (TrajetSimple*) content[i];
    }
}

void Catalogue::Ajouter(Trajet* newTrajet) {
    Trajet** temp = trajets;
    trajets = new Trajet*[nombreDeTrajets+1];
    for(int i=0; i < nombreDeTrajets;i++) {
        trajets[i] = temp[i];
    }
    trajets[nombreDeTrajets] = newTrajet;
    nombreDeTrajets++;
}

void Catalogue::Afficher(int start, int end) {
    for(int i=start; i < end;i++) {
        int strLength = strlen(trajets[i]->GetDepart());
        char depart[strLength];
        strLength = strlen(trajets[i]->GetArrive());
        char arrive[strLength];
        strcpy(depart,trajets[i]->GetDepart());
        strcpy(arrive,trajets[i]->GetArrive());
        Trajet *curr = trajets[i];
        curr->Afficher();
    }
}

void Catalogue::Rechercher(char* depart, char* arrive) {
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


//Catalogue::~Catalogue ( )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au destructeur de <Catalogue>" << endl;
//#endif
//} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées