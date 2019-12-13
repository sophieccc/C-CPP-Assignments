/******************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, 
                                            Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $zihao.hua@insa-lyon.fr
*******************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Cette classe déclare un trajet de base (la classe mère).
//------------------------------------------------------------------------

class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    char* GetDepart() const;
    // Mode d'emploi :
    // Cette méthode renvoie la ville de départ du trajet.

    char* GetArrive() const;
    // Mode d'emploi :
    // Cette méthode renvoie la ville d'arrivée du trajet.

    virtual void Afficher() const {} ;
    // Mode d'emploi :
    // Cette méthode affiche les caractéristiques du trajet.

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :

    Trajet ( );
     // Mode d'emploi (constructeur 1) :   
    Trajet (char* depart, char* arrive);
    // Mode d'emploi : (constructeur 2)

    virtual ~Trajet ( );
    // Mode d'emploi : (destructeur)

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char *depart;
    char *arrive;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

