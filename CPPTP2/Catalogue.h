/******************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, 
                                            Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $zihao.hua@insa-lyon.fr
*******************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Cette classe a pour rôle de contenir  un ensemble de trajets tout en
// offrant la possibilité d'en rajouter d'autres, de chercher un trajet
// souhaité et d'afficher le contenu à tout moment
//
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Ajouter(Trajet* newTrajet);
    // Mode d'emploi : Cette méthode permet d'ajouter un trajet au 
    // catalogue
    void Afficher() const;
    // Mode d'emploi : Permet d'afficher, à tout moment, le contenu du
    // catalogue courant
    void Rechercher(char* depart, char* arrive) const; 
    // Mode d'emploi : Cette méthode permet de chercher un trajet dont 
    // les villes de départ et d'arrivée sont rentrées en paramètres
    // et d'ensuite l'afficher sur la sortie standard de la console.
    bool Retirer(const int index);
    // Mode d'emploi: cette méthode retire un trajet du catalogue dont
    // l'indice est rentré en paramètre. On en a eu besoin pour le
    // parcours récursif de la recherche avancée.
    void RechercheAvance (const char* depart, const char* arrive);
    int composition(const char* depart, const char* arrive, Catalogue* used);
//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :

    Catalogue();
    // Mode d'emploi : (constructeur par défaut)

    virtual ~Catalogue ( );
    // Mode d'emploi : (destructeur de Catalogue)

    Catalogue(Trajet** content, int nombre);
    // Mode d'emploi : (cestructeur de Catalogue)

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    int nombreDeTrajets;
    Trajet **trajets;
    int space;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
