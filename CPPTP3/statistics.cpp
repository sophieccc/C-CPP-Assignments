/******************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

//---------- Réalisation de la classe <Statistiques> (fichier statistics.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
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

void statistics::writeGraph(string fileName)
{
    cout << "Dot-file " << fileName << ".dot generated" << endl;
    ofstream file(fileName.c_str());
    if(file.good())
    {
        file << "diagraph {" << endl;
        for (auto iter=graph.begin(); iter!=graph.end(); iter++)
        {
            file << iter->first << ";" << endl;
        }
        for (auto iter=graph.begin(); iter!=graph.end(); iter++)
        {
            for (auto iter2=iter->second.begin(); iter2!=iter->second.end(); iter2++)
            {
                file << iter2->first << " -> " << iter->first << "[label=\"" << iter2->second << "\"];" << endl;
            }
        }
        file << "}" << endl;
    }
}
//-------------------------------------------- Constructeurs - destructeur

#ifdef MAP
   cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
//----- Fin de Trajet (constructeur de copie)
statistics::statistics(unordered_map<string,int> inputMap)
{
    hits=inputMap;
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

statistics::~statistics()
{
#ifdef MAP
   cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    /*for(auto iter=hits.begin(); iter!=hits.end(); iter++)
    {
        hits.erase(iter);
    }
    for(auto iter=orderedHits.begin(); iter!=orderedHits.end(); iter++)
    {
        orderedHits.erase(iter);
    }
    for(auto iter=graph.begin(); iter!=graph.end(); iter++)
    {
        graph.erase(iter);
    }*/
    //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

