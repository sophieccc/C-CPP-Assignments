/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
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

TrajetComplexe::TrajetComplexe (TrajetSimple **elementInput, int nombre)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <TrajetComplexe>" << endl;
#endif
    nombreDeTrajets = nombre;
    elements= new TrajetSimple*[nombreDeTrajets];
    elements = elementInput;
    depart = elements[0]->GetDepart();
    arrive = elements[nombreDeTrajets-1]->GetArrive();

   TRANSPORT = new const char*[nombreDeTrajets];
    for(int i=0; i < nombreDeTrajets; i++) {
        TRANSPORT[i] = elementInput[i]->GetTransport();
    }
} //----- Fin de TrajetComplexe


TrajetComplexe::~TrajetComplexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComplexe>" << endl;
#endif
    delete[] elements;
    delete[] TRANSPORT;
} //----- Fin de ~TrajetComplexe

void TrajetComplexe::Afficher() const {
    cout << "Departing City:" << depart << "\n";
    cout << "Arrival City:" << arrive << "\n";
    cout << "Type of Trajet :" << "Complexe" << "\n";
    cout << "Transportation :";
    for(int i=0; i < nombreDeTrajets; i++) {
        //should we just call simple afficher and output each entire trajet?
        int strLength = strlen(TRANSPORT[i]);
        char* transport = new char[strLength];
        strcpy(transport,TRANSPORT[i]);
        cout << transport;
        if(i!=nombreDeTrajets-1) {
            cout << ", ";
        }
        else {
            cout << "\n";
        }
    }
    cout << "\n";
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
