/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <TrajetComplexe> (fichier TrajetComplexe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetComplexe.h"
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetComplexe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//TrajetComplexe & TrajetComplexe::operator = ( const TrajetComplexe & unTrajetComplexe )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetComplexe::TrajetComplexe ( const TrajetComplexe & unTrajetComplexe )
// Algorithme :
//
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <TrajetComplexe>" << endl;
#endif
} //----- Fin de TrajetComplexe (constructeur de copie)


TrajetComplexe::TrajetComplexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComplexe>" << endl;
#endif
} //----- Fin de TrajetComplexe

TrajetComplexe::TrajetComplexe (Catalogue elementInput, int nombreDeTrajets)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <TrajetComplexe>" << endl;
#endif
    nombreDeTrajets = nombreDeTrajets;
    elements=elementInput;
    DEPART = elements.trajets[0]->DEPART;
    ARRIVE = elements.trajets[nombreDeTrajets-1]->ARRIVE;

} //----- Fin de TrajetComplexe


//TrajetComplexe::~TrajetComplexe ( )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au destructeur de <TrajetComplexe>" << endl;
//#endif
//} //----- Fin de ~TrajetComplexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
