/******************************************************************************
                           Statistics  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

//---------- Interface de la classe <Statistics> (fichier Statistics.h) ----------------
#if ! defined ( STATISTICS_H )
#define STATISTICS_H

using namespace std;
#include <unordered_map>
#include <map>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Statistics>
// Cette classe 
//------------------------------------------------------------------------

class Statistics 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    
    // Mode d'emploi :
    // Cette méthode renvoie la ville de départ du trajet.
    void printTopX(int x);
    
//-------------------------------------------- Constructeurs - destructeur
    
    // Mode d'emploi (constructeur de copie) :
    Statistics(const Statistics &desStats);
    
    // Mode d'emploi (constructeur 1) :   
    Statistics();

    // Mode d'emploi : (constructeur 2)
    Statistics(unordered_map<string,int>);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void copyIntoMulti();

//----------------------------------------------------- Attributs protégés
    unordered_map<string, int> hits;
    multimap<int, string> orderedHits;
};

//-------------------------------- Autres définitions dépendantes de <Statistics>

#endif // STATISTICS_H