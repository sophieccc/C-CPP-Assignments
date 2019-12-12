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
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetComplexe::Afficher() const {
    cout << "Departing City:" << depart << "\n";
    cout << "Arrival City:" << arrive << "\n";
    cout << "Type of Trajet :" << "Complexe" << "\n";
    cout << "List of Simple Trajets Inside :" << "\n";
    for(int i=0; i < nombreDeTrajets; i++) {
        elements[i]->Afficher();
    }
    cout << "\n";
}

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
    
    for (int i=0; i<nombreDeTrajets; i++){
        elements[i]=elementInput[i];
    }
    cout << "Made it to compose" << endl;
    //elements = elementInput;
    depart = elements[0]->GetDepart();
    arrive = elements[nombreDeTrajets-1]->GetArrive();
} //----- Fin de TrajetComplexe


TrajetComplexe::~TrajetComplexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComplexe>" << endl;
#endif
    //int i=0;
    /*while(elements[i]!=NULL)
    {
        delete elements[i];
        ++i;
    }*/
    /*for(int i=0; i < nombreDeTrajets;i++) {
        delete elements[i];
    }*/
    delete[] elements;
} //----- Fin de ~TrajetComplexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
