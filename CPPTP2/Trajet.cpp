/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char* Trajet::GetDepart() const {
    return depart;
}

char* Trajet::GetArrive() const {
    return arrive;
}
//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet

Trajet::Trajet (char* departInput, char* arriveInput)
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <Trajet>" << endl;
#endif
    arrive = new char[strlen(arriveInput)];
    strcpy(arrive, arriveInput);
    depart = new char[strlen(departInput)];
    strcpy(depart, departInput);
} //----- Fin de Trajet

Trajet::~Trajet ( )
{
#ifdef MAP
   cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete[] depart;
    delete[] arrive;
} //----- Fin de ~Trajet



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

