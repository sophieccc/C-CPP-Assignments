/******************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, 
                                            Riad Eddahabi$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $zihao.hua@insa-lyon.fr
*******************************************************************************/

//---------- Réalisation de la classe <Statistiques> (fichier statistics.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "statistics.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void statistics::printTopX(int x)
{
    for(auto iter=orderedHits.begin(); iter!=next(orderedHits.begin(),x);iter++)
    {
        cout << "/" << iter->second << " " << "(" << iter->first << "hits)";
    }
}

void statistics::copyIntoMulti()
{
    for(auto iter=hits.begin(); iter!=hits.end(); iter++)
    {
        orderedHits.insert(pair<int,string>(iter->second, iter->first));
    }
}
//-------------------------------------------- Constructeurs - destructeur

#ifdef MAP
   cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
//----- Fin de Trajet (constructeur de copie)
statistics::statistics(unordered_map<string,int>)
{

}
// Algorithme :
//
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
//----- Fin de Trajet


#ifdef MAP
    cout << "Appel au constructeur 2 de <Trajet>" << endl;
#endif
    //----- Fin de Trajet


#ifdef MAP
   cout << "Appel au destructeur de <Trajet>" << endl;
#endif
	
    //----- Fin de ~Trajet



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

