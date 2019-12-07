/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
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
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <Trajet>" << endl;
#endif
    arrive = new char[strlen(arriveInput)];
    strcpy(arrive, arriveInput);
    depart = new char[strlen(departInput)];
    strcpy(depart, departInput);
} //----- Fin de Trajet

//Trajet::~Trajet ( )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au destructeur de <Trajet>" << endl;
//#endif
//} //----- Fin de ~Trajet

    char* Trajet::GetDepart() {
        return depart;
    }

    char* Trajet::GetArrive() {
        return arrive;
    }

    const char* Trajet::GetTransport() {
        return TRANSPORT;
    }


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

