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
    bool exit = false;
    int choice;
    while(!exit) {
        printf("Enter 1 to add to Catalogue, 2 to display catalogue, 3 to search in catalogue, or 4 to exit\n");
        if(cin >> choice) {
            switch(choice) {
                case 1: {
                    char complexity;
                    printf("Enter 's' for simple or 'c' for complex trajet type:\n");
                    cin >> complexity;
                    if(complexity=='s') {
                        char depart[30];
                        char arrive[30];
                        char transport[20];
                        printf("Enter city of departure:\n");
                        cin >> depart;
                        printf("Enter city of arrival:\n");
                        cin >> arrive;
                        printf("Enter mode of transport:\n");
                        cin >> transport;
                        TrajetSimple* curr = new TrajetSimple(depart, arrive, transport);
                        cat.Ajouter(curr);
                    }
                    else if(complexity=='c') {
                        int nombre;
                        printf("Enter the no. of Trajets in this Complex Trajet:\n");
                        cin >> nombre;
                        char depart[30];
                        char arrive[30];
                        char transport[20];
                        TrajetSimple** components = new TrajetSimple*[nombre];
                        for(int i=0; i < nombre; i++) {
                            printf("Receiving info for trajet %d:\n", i);
                            printf("Enter city of departure:\n");
                            cin >> depart;
                            printf("Enter city of arrival:\n");
                            cin >> arrive;
                            printf("Enter mode of transport:\n");
                            cin >> transport;
                            TrajetSimple* curr = new TrajetSimple(depart, arrive, transport);
                            components[i] = curr;
                        }
                        TrajetComplexe* complexCurr = new TrajetComplexe(components, nombre);
                        cat.Ajouter(complexCurr);
                    }
                    else {
                        printf("Invalid complexity type\n");
                    }
                    break;
                }
                case 2: {
                    cat.Afficher();
                    break;
                }
                case 3: {
                    char depart[30];
                    char arrive[30];
                    printf("Enter city of departure:\n");
                    cin >> depart;
                    printf("Enter city of arrival\n");
                    cin >> arrive;
                    cat.Rechercher(depart, arrive);
                    break;
                }
                case 4: {
                    exit = true;
                    break;
                }
                default: {
                    printf("Invalid input\n");
                    break;
                }
            }
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(80,'\n');
        }
    }
    return 0;
}