#include <iostream>
#include "ensemble.h"

Ensemble::Ensemble(unsigned int max) {
    if(max==0) {
        cardMax = 0;
        cardAct = 0;
    }
    else {
        cardMax = max;
        cardAct = 0;
    }
    bag = new int[cardMax];
}
 
Ensemble::Ensemble(int arr[], unsigned int nbElements) {
    cardMax = nbElements;
    bag = new int[cardMax];
    if(nbElements>1) {
        bag[0] = arr[0];
        cardAct = 1;
    }
    bool duplicate = false;
    for(int i=1; i < nbElements; i++) {
        for(int j=0; j < nbElements; j++) {
            if(arr[i]==bag[j]) {
                duplicate = true;
            }
        }
        if(!duplicate) {
            bag[i] = arr[i];
            cardAct++;
        }
    }
}

Ensemble::~Ensemble() {
    /*delete[] bag;
   delete this; */
}

void Ensemble::Afficher() {}

bool Ensemble::EstEgal(const Ensemble & unEnsemble) const {
    if(cardAct!=unEnsemble.cardAct) {
        return false;
    }
    bool isEqual;
    for(int i=0; i < 1; i++) {
        isEqual = false;
        for(int j=0; j< cardAct; j++) {
            if(bag[i]==unEnsemble.bag[j]) {
                isEqual = true;
            }
            if(!isEqual) {
                return false;
            }
        }
    }
    return true;
}
Ensemble::crduEstInclus Ensemble::EstInclus() const {
    return NON_INCLUSION;
}

Ensemble::crduAjouter Ensemble::Ajouter(int aAjouter) {
    return AJOUTE;
}

unsigned int Ensemble::Ajuster(int delta) {
    return 0;
}

bool Ensemble::Retirer(int element) {
    return true;
}

bool Ensemble::Retirer(const Ensemble & unEnsemble) {
    return true;
}

int Ensemble::Reunir(const Ensemble & unEnsemble) {
    return 0;
}

unsigned int Ensemble::Intersection(const Ensemble & unEnsemble) {
    return 0;
}