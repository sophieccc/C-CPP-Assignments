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
#include <typeinfo>

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
    trajets = content;
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

void Catalogue::Afficher() {
    Trajet *current = trajets[0];
    for(int i=0; i < nombreDeTrajets;i++) {
        cout << "Departing City:" << *current->DEPART << "\n";
        cout << "Arrival City:" << *current->ARRIVE << "\n";
        cout << "Type of Trajet :" << typeid(*current).name() << "\n";
    }
}

void Catalogue::Rechercher(char* depart, char* arrive) {
    Trajet *current = trajets[0];
    for(int i=0; i < nombreDeTrajets;i++) {
        if(current->DEPART==depart && current->ARRIVE == arrive)
        cout << i << "\n";
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