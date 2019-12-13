/******************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, 
                                            Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $zihao.hua@insa-lyon.fr$
*******************************************************************************/


//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring> //for more cross-platform compatibility
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes
const int DEFAULT_SPACE = 5;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// Cette méthode ajoute un trajet au catalogue.
void Catalogue::Ajouter(Trajet* newTrajet) {
    if(nombreDeTrajets==space){
        space+=DEFAULT_SPACE;
        Trajet** temp=new Trajet*[space];
        for (int i=0; i<nombreDeTrajets ; i++){
            temp[i]=trajets[i];
        }
        for (int i=0; i<nombreDeTrajets; i++){
            delete trajets[i];
        }
        delete[] trajets;
        trajets=temp;
    }
    trajets[nombreDeTrajets]=newTrajet;
    nombreDeTrajets++;
}

/* Cette méthode permet d'afficher, à tout moment, le contenu du 
catalogue courant */
void Catalogue::Afficher() const {
    if(nombreDeTrajets==0)
    cout << "Pas de trajet enregistre" << endl;
    for(int i=0; i < nombreDeTrajets;i++) {
        Trajet* curr = trajets[i];
        curr->Afficher();
    }
} //----- Fin de Méthode

// Cette méthode permet de rechercher un trajet dans le catalogue.
void Catalogue::Rechercher(char* depart, char* arrive) const {
    if(nombreDeTrajets==0)
	cout << "Pas de trajet enregistre" << endl;
    int count = 1;
    for(int i=0; i < nombreDeTrajets;i++) {
        if(strcmp(trajets[i]->GetDepart(),depart)==0 
        && strcmp(trajets[i]->GetArrive(),arrive)==0) {
            cout << "Found Trajet " << count << "--\n";
            trajets[i]->Afficher();
            count++;
        }
    }
} //----- Fin de Méthode
bool Catalogue::Retirer(const int index) {
    if (index < 0 || index >= nombreDeTrajets){
	cout << "Pas de trajet enregistre, retrait impossible" << endl;        
	return false;
    }
    for (int i=index; i<nombreDeTrajets-1; i++){
        trajets[i]=trajets[i+1];
    }
    nombreDeTrajets--;
    return true;
    
}
void Catalogue::RechercheAvance(const char* depart, const char* arrive) {
    cout << endl;
    Catalogue* used = new Catalogue();
    int nbPropositions = composition(depart, arrive, used);
    cout << "-- A total of: " << nbPropositions << " option(s) for you to choose from " << endl;
    delete used;
}

int Catalogue::composition(const char* depart, const char* arrive, Catalogue* used){
    int composable=0;
    if (strcmp(depart, arrive)==0){ // arrêt en arrivant à destination
        cout << "Composition(s) of trajets that you might want to consider:" << endl;    
        used->Afficher(); // affiche la composition de trajets prises
        return 1;
    }

    for (int i=0; i<nombreDeTrajets; i++){
        Trajet* t=trajets[i]; // pris comme départ s’il part de l’arrivée du précédent
        if (strcmp(t->GetDepart(),depart)==0){ //départ identique
            int valid=1;
            // détection de cycles (il ne faut pas arriver dans un départ déjà pris
            for (int j=0; j<used->nombreDeTrajets; j++){
                Trajet* tUsed=used->trajets[j];
                if (strcmp(t->GetArrive(),tUsed->GetDepart())==0){
                    valid=0; // arrêt
                }
            }
            if(valid){  // si aucune condition d’arrêt détectée, parcours récursif
                used->Ajouter(t);
                composable += composition(t->GetArrive(), arrive, used);
                used->Retirer(used->nombreDeTrajets-1);
            }
        }
    }
    return composable;
}


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( const Catalogue & unCatalogue )
{
#ifdef MAP
   cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    nombreDeTrajets = 0;
    space = DEFAULT_SPACE;
    trajets = new Trajet*[space];
} //----- Fin de Catalogue (Constructeur 1)

Catalogue::Catalogue(Trajet** content, int nombre) {
    space = nombre;
    nombreDeTrajets = nombre;
    trajets= new Trajet*[nombreDeTrajets];
    for(int i=0; i < nombreDeTrajets; i++) {
        trajets[i] = content[i];
    }
} //----- Fin de Catalogue (Constructeur 2)

Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    for (int i=0; i<nombreDeTrajets;i++){
        delete trajets[i];
    }
    delete[] trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
