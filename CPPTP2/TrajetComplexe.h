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
//
//
//------------------------------------------------------------------------

class TrajetComplexe : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    TrajetComplexe ( const TrajetComplexe & unTrajetComplexe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetComplexe ( );

    TrajetComplexe (TrajetSimple** elements, int nombre);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetComplexe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher() const;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TrajetSimple **elements;
    int nombreDeTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetComplexe>

#endif // TRAJETCOMPLEXE_H


