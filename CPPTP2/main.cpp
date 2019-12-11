/*************************************************************************
                           main  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

int main() {
    Catalogue *cat=new Catalogue;
    bool exit = false;
    int choice;
    while(!exit) {
        printf("Enter 1 to add to Catalogue, 2 to display catalogue, 3 to search in catalogue, 4 to make an advanced search, 5 to delete a trajet, or 6 to exit\n");
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
                        printf("Enter city of departure (replace spaces with '_'):\n");
                        cin >> depart;
                        printf("Enter city of arrival (replace spaces with '_'):\n");
                        cin >> arrive;
                        printf("Enter mode of transport:\n");
                        cin >> transport;
                        TrajetSimple* curr = new TrajetSimple(depart, arrive, transport);
                        cat->Ajouter(curr);
                        //delete curr;
                    }
                    else if(complexity=='c') {
                        int nombre;
                        printf("Enter the no. of Trajets in this Complex Trajet:\n");
                        cin >> nombre;
                        char depart[30];
                        char arrive[30];
                        char transport[20];
                        TrajetSimple** components = new TrajetSimple*[nombre];
                        char stopover[30];
                        for(int i=0; i < nombre; i++) {
                            printf("Receiving info for trajet %d:\n", i+1);
                            printf("Enter city of departure (replace spaces with '_'):\n");
                            cin >> depart;
                            if (i>0){
                                while(strcmp(depart,stopover)!=0){
                                    printf("Incoherent stopover city. Please enter valid departure:\n");
                                    cin >> depart;
                                }
                            } // checking that trajet i+1 starts where trajet i ended
                            printf("Enter city of arrival (replace spaces with '_'):\n");
                            cin >> arrive;
                            strcpy(stopover,arrive);
                            printf("Enter mode of transport:\n");
                            cin >> transport;
                            TrajetSimple* curr = new TrajetSimple(depart, arrive, transport);
                            components[i] = curr;
                        }
                        TrajetComplexe* complexCurr = new TrajetComplexe(components, nombre);
                        cat->Ajouter(complexCurr);
                        //delete[] components;
                    }
                    else {
                        printf("Invalid complexity type\n");
                    }
                    break;
                }
                case 2: {
                    cat->Afficher();
                    break;
                }
                case 3: {
                    char depart[30];
                    char arrive[30];
                    printf("Enter city of departure (replace spaces with '_'):\n");
                    cin >> depart;
                    printf("Enter city of arrival (replace spaces with '_')\n");
                    cin >> arrive;
                    cat->Rechercher(depart, arrive);
                    break;
                }
                case 4: {
                    char depart [30];
                    char arrive [30];
                    printf("Enter city of departure (replace spaces with '_':\n");
                    cin >> depart;
                    printf("Enter city of arrival (replace spaces with '_')\n");
                    cin >> arrive;
                    cat->RechercheAvance(depart, arrive);
                    break;
                }
                case 5: {
                    int num;
                    printf("Enter index of trajet you want to delete:\n");
                    cin >> num;
                    cat->Retirer(num);
                    break;
                }
                case 6: {
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
    delete cat;
    return 0;
}