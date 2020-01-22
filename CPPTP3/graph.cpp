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
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "graph.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void graph::writeGraph(string fileName)
{
    cout << "Dot-file " << fileName << ".dot generated" << endl;
    ofstream file(fileName.c_str());
    if(file.good())
    {
        file << "digraph {" << endl;
        for (auto iter=links.begin(); iter!=links.end(); iter++)
        {
            file <<  "node" << nodes.at(iter->first) << "[label=\"" << iter->first << "\"];" << endl;
        }
        for (auto iter=links.begin(); iter!=links.end(); iter++)
        {
            for (auto iter2=iter->second.begin(); iter2!=iter->second.end(); iter2++)
            {
                file << "node" << nodes.at(iter2->first) << " -> " << "node" << nodes.at(iter->first) << "[label=\"" << iter2->second << "\"];" << endl;
            }
        }
        file << "}" << endl;
    }
}
void graph::fillNodes()
{   
    int i=0;
    for (auto iter=links.begin(); iter!=links.end(); iter++)
    {
        if(nodes.count(iter->first)==0)
        {
            nodes.insert(pair<string,int>(iter->first,i));
            i++;
        }
        for(auto iter2=iter->second.begin(); iter2!=iter->second.end(); iter2++)
        {
            if(nodes.count(iter2->first)==0)
            {
                nodes.insert(pair<string,int>(iter2->first,i));
                i++;
            }
        }
    }
}
//-------------------------------------------- Constructeurs - destructeur
graph::graph(const graph &unGraphe)
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
    links=unGraphe.links;
}
//----- Fin de Trajet (constructeur de copie)

graph::graph(unordered_map<string,unordered_map<string, int>> inputLinks)
{
// Algorithme :
//
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
//----- Fin de Trajet
    links=inputLinks;
}

#ifdef MAP
    cout << "Appel au constructeur 2 de <Trajet>" << endl;
#endif
    //----- Fin de Trajet

graph::~graph()
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
}
//----- Fin de ~Trajet
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
