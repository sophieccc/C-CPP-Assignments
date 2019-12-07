/*************************************************************************
                           main  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

#include <iostream>
using namespace std;

#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

int main() {
    Catalogue cat;
    int choice;
    bool exit = false;
    while(!exit) {
        printf("Enter 1 to add to Catalogue, 2 to display catalogue, 3 to search in catalogue, or 4 to exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                // check that complex ones are valid, aka depart/arrive stuff
                break;
            }
            case 2: {
                //cat.Afficher();
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                exit = true;
                break;
            }
            default: {
                printf("Invalid input\n");
            }
        }
    }
   /* 
    current.Afficher();
    cout << "adding five" << "\n";
    current.Ajouter(&five);
    cout << "added five" << "\n";
    current.Afficher(); 
    current.Rechercher((char *)"Berlin", (char *)"Munich");
    current.Rechercher((char *)"Dublin", (char *)"Paris");
    current.Rechercher((char *)"Dublin", (char *)"Dublin");
    */
    return 0;

}