/******************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, 
                                            Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $zihao.hua@insa-lyon.fr$
*******************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const {
    cout << "Departing City:" << depart << "\n";
    cout << "Arrival City:" << arrive << "\n";
    cout << "Type of Trajet :" << "Simple" << "\n";
    cout << "Transportation :" << transport << "\n";
    cout << "\n";
}

const char TrajetSimple::GetType() const {
    return 'S';
}
const string  TrajetSimple::GetTransport() const {
    return transport;
}
//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple (string departInput, string arriveInput, string transportInput) 
: Trajet(departInput, arriveInput)
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <TrajetSimple>" << endl;
#endif

    transport=transportInput;
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

