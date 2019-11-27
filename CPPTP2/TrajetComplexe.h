/*************************************************************************
                           TrajetComplexe  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <TrajetComplexe> (fichier TrajetComplexe.h) ----------------
#if ! defined ( TRAJETCOMPLEXE_H )
#define TRAJETCOMPLEXE_H

#include "Trajet.h"
#include "TrajetSimple.h"
#include "Catalogue.h"

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
    const char **TRANSPORT;
    TrajetSimple **elements;
    int nombreDeTrajets;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
     TrajetComplexe & operator = ( const TrajetComplexe & unTrajetComplexe );
    // Mode d'emploi :
    //
    // Contrat :
    //


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

   // virtual ~TrajetComplexe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <TrajetComplexe>

#endif // TRAJETCOMPLEXE_H


