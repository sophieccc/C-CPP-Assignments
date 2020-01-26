/******************************************************************************
                           Statistics  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

//---------- Réalisation de la classe <Statistics> (fichier Statistics.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Statistics.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Statistics::printTopX(int x)
{
    int i=1;
    map<int,string>::reverse_iterator rit;
    for(rit=orderedHits.rbegin(); rit!=orderedHits.rend() && (i <= x);++rit, ++i)
    {
        cout << i << ". " << rit->second << " " << "(" << rit->first << " hits)" << endl;
    }
}

//-------------------------------------------- Constructeurs - destructeur
Statistics::Statistics(const Statistics &desStats)
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Statistics>" << endl;
#endif
    hits=desStats.hits;
}
//----- Fin de Statistics (constructeur de copie)

Statistics::Statistics(unordered_map<string,int> inputMap)
{
// Algorithme :
//
#ifdef MAP
    cout << "Appel au constructeur de <Statistics>" << endl;
#endif
    hits=inputMap;
    copyIntoMulti();
}
//----- Fin de Statistics

Statistics::Statistics()
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <Statistics>" << endl;
#endif
}
 //----- Fin de Statistics

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Statistics::copyIntoMulti()
{
    for(auto iter=hits.begin(); iter!=hits.end(); iter++)
    {
        orderedHits.insert(pair<int,string>(iter->second, iter->first));
    }
}
