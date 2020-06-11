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
    int typeTrajet;
    while(!exit) {
        cout << "       Welcome to Trip Scanner" << endl << "What would you like to do?" << endl;
        cout << "================= MENU =================" << endl;
        cout << "1: Enter 1 to add an itinerary." << endl;
        cout << "2: Enter 2 to display current catalogue. " << endl;
        cout << "3: Enter 3 to look for an itinerary." << endl;
        cout << "4: Enter 4 to make an advanced search." << endl;
        cout << "5: Enter 5 to upload from a file." << endl;
        cout << "6: Enter 6 to save." << endl;
        cout << "7: Enter 7 to exit." << endl; 
        if(cin >> choice) {
            switch(choice) {
                case 1: {
                    char complexity;
                    printf("Enter 's' for simple or 'c' for complex trajet type:\n");
                    cin >> complexity;
                    if(complexity=='s') {
                        cin.ignore();
                        string depart;
                        string arrive;
                        string transport;
                        printf("Enter city of departure (replace spaces with '_'):\n");
                        getline(cin, depart);
                        printf("Enter city of arrival (replace spaces with '_'):\n");
                        getline(cin, arrive);
                        printf("Enter mode of transport:\n");
                        getline(cin, transport);
                        TrajetSimple* curr = new TrajetSimple(depart, arrive, transport);
                        cat->Ajouter(curr);
                        //delete curr;
                    }
                    else if(complexity=='c') {
                        int nombre;
                        printf("Enter the no. of Trajets in this Complex Trajet:\n");
                        if(cin >> nombre) {
                            cin.ignore();
                            string depart;
                            string arrive;
                            string transport;
                            TrajetSimple** components = new TrajetSimple*[nombre];
                            string stopover;
                            for(int i=0; i < nombre; i++) {
                                printf("Receiving info for trajet %d:\n", i+1);
                                printf("Enter city of departure (replace spaces with '_'):\n");
                                getline(cin, depart);
                                if (i>0){
                                    while(depart.compare(stopover)!=0){
                                        printf("Incoherent stopover city. Please enter valid departure:\n");
                                        getline(cin, depart);
                                    }
                                } // checking that trajet i+1 starts where trajet i ended
                                printf("Enter city of arrival (replace spaces with '_'):\n");
                                getline(cin, arrive);
                                stopover=arrive;
                                printf("Enter mode of transport:\n");
                                getline(cin, transport);
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
                    cin.ignore();
		            string depart;
                    string arrive;
                    printf("Enter city of departure (replace spaces with '_'):\n");
                    getline(cin, depart);
                    printf("Enter city of arrival (replace spaces with '_')\n");
                    getline(cin, arrive);
                    cat->Rechercher(depart, arrive);
                    break;
                }
                case 4: {
                    cin.ignore();
                    string depart;
                    string arrive;
                    printf("Enter city of departure (replace spaces with '_':\n");
                    getline(cin, depart);
                    printf("Enter city of arrival (replace spaces with '_')\n");
                    getline(cin, arrive);
                    cat->RechercheAvance(depart, arrive);
                    break;
                }
                case 5: { // chargement
                    cin.ignore();
                    cout << "Where are we getting the data from?" << endl;
                    string fileName;
                    getline(cin,fileName);
                    fileName+=".txt";
                    int typeRestitution;
                    cout << "Do you want to restore all types of 'Trajets' (1), a specific type (2), specific cities (3) or a range (4)?" << endl;
                    if(cin >> typeRestitution){
                      switch(typeRestitution){
                        case 1:{
                          cat->RestitutionSimple(fileName);
                          break;
                        }
                        case 2:{
                          cout << "What type of 'Trajet' would you like to restore ? TS (1) or TC (2)." << endl;
                          cin >> typeTrajet;
                          cat->RestitutionTypeTrajet(fileName,typeTrajet);
                          break;
                        }
                        case 3:{
                            int cities;
                            string depart;
                            string arrive;
                            cout << "Would you like to restore by departure (1), arrival (2), or both (3)?" << endl;
                            if (cin >> cities){
                                switch (cities){
                                    case 1: {
                                        cin.ignore();
                                        cout << "Enter departure city:" << endl; 
                                        getline(cin,depart);
                                        cat->RestitutionDepart(fileName,depart);
                                        break;
                                    }
                                    case 2: {
                                        cin.ignore();
                                        cout << "Enter arrival city:" << endl;
                                        getline(cin,arrive);
                                        cat->RestitutionArrive(fileName,arrive);
                                        break;
                                    }
                                    case 3: {
                                        cin.ignore();
                                        cout << "Enter departure city:" << endl; 
                                        getline(cin,depart);
                                        cout << "Enter arrival city:" << endl;
                                        getline(cin,arrive);
                                        cat->RestitutionBoth(fileName,depart,arrive);
                                        break;
                                    }
                                }
                            }
                            break;   
                        }
                        case 4:{
                            int n,m;
                            cout << "Enter the first itinerary you want to restore:" << endl;;
                            cin >> n;
                            cout << "Enter the last itinerary you want to restore:" << endl;;
                            cin >> m;
                            cat->RestitutionIntervalle(fileName, n,m);
                        }
                      }
                    }

                    break;
                }
                case 6: { // sauvegarder
                    cin.ignore();
                    cout << "Where are saving the data?" << endl;
                    string fileName;
                    getline(cin, fileName);
                    fileName+=".txt";
                    int typeEnregistrement;
                    cout << "Do you want to save all the data (1), a specific type of 'Trajet' (2), specific cities (3) or a specific range (4) ? " << endl;
                    if (cin >> typeEnregistrement){
                      switch(typeEnregistrement){
                        case 1:{
                          cat->EnregistrementSimple(fileName);
                          break;
                        }
                        case 2:{
                          cout << "Do you want to save TS (1) or TC (2) ?" << endl;
                          cin >> typeTrajet;
                          cat->EnregistrementTypeTrajet(fileName, typeTrajet);
                          break;
                        }
                        case 3:{
                            int cities;
                            string depart;
                            string arrive;
                            cout << "Would you like to save by departure (1), arrival (2), or both (3)?" << endl;
                            if (cin >> cities){
                                switch (cities){
                                    case 1: {
                                        cin.ignore();
                                        cout << "Enter departure city:" << endl; 
                                        getline(cin, depart);
                                        cat->EnregistrementDepart(fileName,depart);
                                        break;
                                    }
                                    case 2: {
                                        cin.ignore();
                                        cout << "Enter arrival city:" << endl;
                                        getline(cin, arrive);
                                        cat->EnregistrementArrive(fileName,arrive);
                                        break;
                                    }
                                    case 3: {
                                        cin.ignore();
                                        cout << "Enter departure city:" << endl; 
                                        getline(cin, depart);
                                        cout << "Enter arrival city:" << endl;
                                        getline(cin, arrive);
                                        cat->EnregistrementBoth(fileName,depart,arrive);
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 4:{
                            int n,m;
                            cout << "Enter the first itinerary you want to save: " << endl;
                            cin >> n;
                            cout << "Enter the last itnerary you want to save: " << endl;
                            cin >> m;
                            cat->EnregistrementIntervalle(fileName, n,m);
                        }
                      }
                    }
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
