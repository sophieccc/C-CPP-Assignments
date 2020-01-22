/******************************************************************************
                           Statistics  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

//---------- Réalisation de la classe <Statistics> (fichier statistics.cpp) ------------

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
statistics::statistics(const statistics &DesStats)
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
    hits=DesStats.hits;
}
//----- Fin de Trajet (constructeur de copie)

statistics::statistics(unordered_map<string,int> inputMap)
{
// Algorithme :
//
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
//----- Fin de Trajet
    hits=inputMap;
}

statistics::statistics()
{
}
    //----- Fin de Trajet
    
//----- Fin de ~Trajet
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
