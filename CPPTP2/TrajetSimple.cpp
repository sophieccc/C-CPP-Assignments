/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple (char* departInput, char* arriveInput, char* transportInput) 
: Trajet(departInput, arriveInput)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <TrajetSimple>" << endl;
#endif
    transport = new char[strlen(arriveInput)];
    strcpy(transport, transportInput);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete[] transport;
} //----- Fin de ~TrajetSimple

void TrajetSimple::Afficher() const {
    cout << "Departing City:" << depart << "\n";
    cout << "Arrival City:" << arrive << "\n";
    cout << "Type of Trajet :" << "Simple" << "\n";
    cout << "Transportation :" << transport << "\n";
    cout << "\n";
}

const char* TrajetSimple::GetTransport() const {
    return transport;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

