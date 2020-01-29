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
#include <string>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graph.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Graph::writeGraph(string fileName)
{
    cout << "Dot-file " << fileName << " generated" << endl;
    ofstream file(fileName.c_str());
    if(file.good())
    {
        file << "digraph {" << endl;
        for (auto iter=links.begin(); iter!=links.end(); iter++)
        {
            if(nodes.count(iter->first)>0)
            {
                file <<  "node" << nodes.at(iter->first) << " [label=\"" << iter->first << "\"];" << endl;
            }
        }

        for (auto iter=links.begin(); iter!=links.end(); iter++)
        {
            for (auto iter2=iter->second.begin(); iter2!=iter->second.end(); iter2++)
            {  
                if(nodes.count(iter->first)>0)
                { 
                file <<  "node" << nodes.at(iter2->first) << " [label=\"" << iter2->first << "\"];" << endl;
                }
            }
        }

        for (auto iter=links.begin(); iter!=links.end(); iter++)
        {
            for (auto iter2=iter->second.begin(); iter2!=iter->second.end(); iter2++)
            {
                if(nodes.count(iter2->first)>=0)
                {
                    file << "node" << nodes.at(iter2->first) << " -> " << "node" << nodes.at(iter->first) << " [label=\"" << iter2->second;file << "\"];" << endl;
                }
            }
        }
        file << "}" << endl;
    }
}

void Graph::fillNodes()
{   
    int i=0;
    for (auto iter=links.begin(); iter!=links.end(); iter++)
    {
        if(nodes.count(iter->first)==0)
        {
            nodes.insert(pair<string,int>(iter->first,i));
            i++;
        }
    }
    for (auto iter=links.begin(); iter!=links.end(); iter++)
    {
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
Graph::Graph(const Graph &unGraphe)
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
    links=unGraphe.links;
}
//----- Fin de Graph (constructeur de copie)

Graph::Graph(unordered_map<string,unordered_map<string, int> > inputLinks)
{
// Algorithme :
//
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
    links=inputLinks;
    fillNodes();
}
//----- Fin de Graph

Graph::Graph()
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <Graph>" << endl;
#endif
}
//----- Fin de Graph

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées