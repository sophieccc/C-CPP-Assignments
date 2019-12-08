/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <TrajetComplexe> (fichier TrajetComplexe.h) ----------------
#if ! defined ( TRAJETCOMPLEXE_H )
#define TRAJETCOMPLEXE_H

#include "Trajet.h"
#include "TrajetSimple.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetComplexe>
// Cette classe déclare un trajet composé de plusieurs trajets simples
// allant chacun d'une ville de départ à une ville d'arrivée avec un moyen
// de transport défini.
//------------------------------------------------------------------------

class TrajetComplexe : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Cette méthode affiche les caractéristique du trajet
    
//-------------------------------------------- Constructeurs - destructeur
    TrajetComplexe ( const TrajetComplexe & unTrajetComplexe );
    // Mode d'emploi (constructeur de copie) :

    TrajetComplexe ( );
    // Mode d'emploi (constructeur 1) :

    TrajetComplexe (TrajetSimple** elements, int nombre);
    // Mode d'emploi (constructeur 2) :

    virtual ~TrajetComplexe ( );
    // Mode d'emploi (destructeur) :

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TrajetSimple **elements;
    int nombreDeTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetComplexe>

#endif // TRAJETCOMPLEXE_H


