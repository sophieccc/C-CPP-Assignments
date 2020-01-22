/******************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/


//---------- Interface de la classe <Statistiques> (fichier statistics.h) ----------------
#if ! defined ( STATISTICS_H )
#define STATISTICS_H
using namespace std;
#include <unordered_map>
#include <map>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Cette classe déclare un trajet de base (la classe mère).
//------------------------------------------------------------------------

class statistics 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    
    // Mode d'emploi :
    // Cette méthode renvoie la ville de départ du trajet.
    void copyIntoMulti();
    void printTopX(int x);
    void writeGraph(string fileName);
    // Mode d'emploi :
    // Cette méthode renvoie la ville d'arrivée du trajet.

    
    // Mode d'emploi :
    // Cette méthode affiche les caractéristiques du trajet.
    
//-------------------------------------------- Constructeurs - destructeur
    
    // Mode d'emploi (constructeur de copie) :
    statistics(const statistics &dDesStats);
    
    // Mode d'emploi (constructeur 1) :   
    statistics();

    // Mode d'emploi : (constructeur 2)
    statistics(unordered_map<string,int>,unordered_map<string,unordered_map<string, int>>);
    
    // Mode d'emploi : (destructeur)

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    unordered_map<string, int> hits;
    multimap<int, string> orderedHits;
    unordered_map<string,unordered_map<string, int>> graph;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // STATISTICS_H