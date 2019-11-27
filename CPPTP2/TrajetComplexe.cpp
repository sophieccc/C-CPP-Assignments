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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetComplexe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
TrajetComplexe & TrajetComplexe::operator = ( const TrajetComplexe & unTrajetComplexe )
// Algorithme :
//
{
} //----- Fin de operator


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

TrajetComplexe::TrajetComplexe (TrajetSimple **elementInput, int nombre, bool complex)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <TrajetComplexe>" << endl;
#endif
    isComplex = complex;
    nombreDeTrajets = nombre;
    elements= new TrajetSimple*[nombreDeTrajets];
    elements = elementInput;
    depart = elements[0]->depart;
    arrive = elements[nombreDeTrajets-1]->arrive;

    TRANSPORT = new const char*[nombreDeTrajets];
    for(int i=0; i < nombreDeTrajets; i++) {
        TRANSPORT[i] = elementInput[i]->TRANSPORT;
    }
} //----- Fin de TrajetComplexe


/*TrajetComplexe::~TrajetComplexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComplexe>" << endl;
#endif
} //----- Fin de ~TrajetComplexe
*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
