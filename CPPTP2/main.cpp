/******************************************************************************
                           main  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, 
                                            Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $zihao.hua@insa-lyon.fr$
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
        cout << "       Welcome to Trip Scanner" << endl << "What would you like to do?" << endl;
        cout << "================= MENU =================" << endl;
        cout << "1: Enter 1 to add an itinerary." << endl;
        cout << "2: Enter 2 to display current catalogue. " << endl;
        cout << "3: Enter 3 to look for an itinerary." << endl;
        cout << "4: Enter 4 to make an advanced search." << endl;
        cout << "3: Enter 5 to upload from a file." << endl;
        cout << "4: Enter 6 to save." << endl;
        cout << "5: Enter 7 to exit." << endl; 
        if(cin >> choice) {
            switch(choice) {
                case 1: {
                    char complexity;
                    printf("Enter 's' for simple or 'c' for complex trajet type:\n");
                    cin >> complexity;
                    if(complexity=='s') {
                        string depart;
                        string arrive;
                        string transport;
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
                        if(cin >> nombre) {
                            string depart;
                            string arrive;
                            string transport;
                            TrajetSimple** components = new TrajetSimple*[nombre];
                            string stopover;
                            for(int i=0; i < nombre; i++) {
                                printf("Receiving info for trajet %d:\n", i+1);
                                printf("Enter city of departure (replace spaces with '_'):\n");
                                cin >> depart;
                                if (i>0){
                                    while(depart.compare(stopover)!=0){
                                        printf("Incoherent stopover city. Please enter valid departure:\n");
                                        cin >> depart;
                                    }
                                } // checking that trajet i+1 starts where trajet i ended
                                printf("Enter city of arrival (replace spaces with '_'):\n");
                                cin >> arrive;
                                stopover=arrive;
                                printf("Enter mode of transport:\n");
                                cin >> transport;
                                TrajetSimple* curr = new TrajetSimple(depart, arrive, transport);
                                components[i] = curr;
                            }
                            TrajetComplexe* complexCurr = new TrajetComplexe(components, nombre);
                            cat->Ajouter(complexCurr);
                            delete[] components;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            cin.clear();
                            cin.ignore(80,'\n');
                        }
                    }
                    else {
                        cin.clear();
                        printf("Invalid complexity type\n");
                    }
                    break;
                }
                case 2: {
                    cat->Afficher();
                    break;
                }
                case 3: {
		            string depart;
                    string arrive;
                    printf("Enter city of departure (replace spaces with '_'):\n");
                    cin >> depart;
                    printf("Enter city of arrival (replace spaces with '_')\n");
                    cin >> arrive;
                    cat->Rechercher(depart, arrive);
                    break;
                }
                case 4: {
                    string depart;
                    string arrive;
                    printf("Enter city of departure (replace spaces with '_':\n");
                    cin >> depart;
                    printf("Enter city of arrival (replace spaces with '_')\n");
                    cin >> arrive;
                    cat->RechercheAvance(depart, arrive);
                    break;
                }
                case 5: { // chargement
                    cin.ignore();
                    cout << "Where are we getting the data from?" << endl;
                    string fileName;
                    getline(cin,fileName);
                    fileName+=".txt";
                    cat->RestitutionSimple(fileName);
                    break;
                }
                case 6: { // sauvegarder
                    cin.ignore();
                    cout << "Where are saving the data?" << endl;
                    string fileName;
                    getline(cin, fileName);
                    fileName+=".txt";
                    cat->EnregistrementSimple(fileName);
                    break;
                }
                case 7: {
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
    int debug;
    cin >> debug; // pour suivre les fuites après sortie de l'application par la commande leaks sur MacOS
    return 0;
}
