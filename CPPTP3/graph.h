/******************************************************************************
                           Statistics  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

//---------- Interface de la classe <Statistics> (fichier statistics.h) ----------------
#if ! defined ( GRAPH_H )
#define GRAPH_H
using namespace std;
#include <unordered_map>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistics>
// Cette classe 
//------------------------------------------------------------------------

class Graph 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    
    // Mode d'emploi :
    // Cette méthode renvoie la ville de départ du trajet.
    void writeGraph(string fileName);
    // Mode d'emploi :
    // Cette méthode renvoie la ville d'arrivée du trajet.

    
    // Mode d'emploi :
    // Cette méthode affiche les caractéristiques du trajet.
    
//-------------------------------------------- Constructeurs - destructeur
    
    // Mode d'emploi (constructeur de copie) :
    Graph(const Graph &unGraphe);
    
    // Mode d'emploi (constructeur 1) :   
    Graph();

    // Mode d'emploi : (constructeur 2)
    Graph(unordered_map<string,unordered_map<string, int>>);
    
    // Mode d'emploi : (destructeur)

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void fillNodes();

//----------------------------------------------------- Attributs protégés
    unordered_map<string,unordered_map<string, int>> links;
    unordered_map<string,int> nodes;
};

//-------------------------------- Autres définitions dépendantes de <Graph>

#endif // GRAPH_H