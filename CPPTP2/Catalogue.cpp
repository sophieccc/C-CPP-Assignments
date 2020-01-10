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
#include <fstream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

//------------------------------------------------------------- Constantes
const int DEFAULT_SPACE = 20;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// Cette méthode ajoute un trajet au catalogue.
void Catalogue::Ajouter(Trajet* newTrajet) {
    if(nombreDeTrajets==space){
        Expand();
    }
    trajets[nombreDeTrajets]=newTrajet;
    nombreDeTrajets++;
}
void Catalogue::Expand()
{
    space+=DEFAULT_SPACE;
    Trajet** temp=new Trajet*[space];
    for (int i=0; i<nombreDeTrajets ; i++){
        temp[i]=trajets[i];
    }
    delete[] trajets;
    trajets=temp;
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
void Catalogue::Rechercher(string depart, string arrive) const {
    if(nombreDeTrajets==0)
	cout << "Pas de trajet enregistre" << endl;
    int count = 1;
    for(int i=0; i < nombreDeTrajets;i++) {
        if(trajets[i]->GetDepart().compare(depart)==0
        && trajets[i]->GetArrive().compare(arrive)==0) {
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
void Catalogue::RechercheAvance(const string depart, const string arrive) {
    cout << endl;
    Catalogue* used = new Catalogue();
    int nbPropositions = composition(depart, arrive, used);
    cout << "-- A total of: " << nbPropositions << " option(s) for you to choose from " << endl;
    delete used;
}

int Catalogue::composition(const string depart, const string arrive, Catalogue* used){
    int composable=0;
    if (depart.compare(arrive)==0){ // arrêt en arrivant à destination
        cout << "Composition(s) of trajets that you might want to consider:" << endl;    
        used->Afficher(); // affiche la composition de trajets prises
        return 1;
    }

    for (int i=0; i<nombreDeTrajets; i++){
        Trajet* t=trajets[i]; // pris comme départ s’il part de l’arrivée du précédent
        if (t->GetDepart().compare(depart)==0){ //départ identique
            int valid=1;
            // détection de cycles (il ne faut pas arriver dans un départ déjà pris
            for (int j=0; j<used->nombreDeTrajets; j++){
                Trajet* tUsed=used->trajets[j];
                if (t->GetArrive().compare(tUsed->GetDepart())==0){
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
void Catalogue::EnregistrementSimple(string filename)
{
    ofstream file(filename.c_str());
    if(file.good())
    {
        for(int i=0; i < nombreDeTrajets;i++) {
            Trajet* curr = trajets[i];
            if(trajets[i]->GetType()=='S'){
                TrajetSimple* current = (TrajetSimple*) curr;
                file << "TS|" << current->GetDepart() << "|" << current->GetArrive() << "|" << current->GetTransport() << ";" <<endl;
            }
            else if(trajets[i]->GetType()=='C'){
                TrajetComplexe* current = (TrajetComplexe*) curr;
                int number = current->GetNumber();
                file << "TC|" << number<< "|" << current->GetDepart() << "|" << current->GetArrive() << ";" << endl;
                TrajetSimple** elements=current->GetElements();
                for (int j=0; j<number ; j++){ 
                    file << "TS|" << elements[j]->GetDepart() << "|" << elements[j]->GetArrive() << "|" << elements[j]->GetTransport() << ";" <<endl;
                }
                file << "---------------------------------- End of elementary itineraries;" << endl;
            }
        }
    }
}

void Catalogue::RestitutionSimple(string filename)
{
    ifstream file(filename.c_str());
    if (file.good())
    {
        cout << "Made it past good" << endl;
        string input;
        while(getline(file,input))
        {
            cout << "Made it past getline" << endl;
            int start=0;
            int end=input.find('|');
            string type = input.substr(start, end);
            if (type.compare("TS")==0){
                cout << "Made it past typecompare" << endl;
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                cout << start;
                cout << end;
                cout << depart;
                start=end+1;
                end=input.find('|',start);
                string arrive=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string transport=input.substr(start, end-start);
                TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                Ajouter(curr);
            }
            else if (type.compare("TC")==0){ 
                start=end+1;
                end=input.find('|',start);
                int nombre=stoi(input.substr(start, end-start));
                TrajetSimple** elements = new TrajetSimple*[nombre];
                for (int i=0; i<nombre; i++){
                    getline(file, input);
                    start=input.find('|')+1;
                    end=input.find('|',start);
                    string depart=input.substr(start, end-start);
                    start=end+1;
                    end=input.find('|',start);
                    string arrive=input.substr(start, end-start);
                    start=end+1;
                    end=input.find(';',start);
                    string transport=input.substr(start, end-start);
                    TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                    elements[i]=curr;
                }
                TrajetComplexe* complexCurr = new TrajetComplexe(elements, nombre);
                delete[] elements;
                Ajouter(complexCurr);
            }
        }
    }
}
void Catalogue::EnregistrementTypeTrajet(string filename, int typeTrajet)
{
  ofstream file(filename.c_str());
  if(typeTrajet==1){
    cout << "Enregistrement Trajet Simple" << endl;
    for(int i=0; i < nombreDeTrajets;i++) {
        Trajet* curr = trajets[i];
        if(trajets[i]->GetType()=='S'){
            TrajetSimple* current = (TrajetSimple*) curr;
            file << "TS|" << current->GetDepart() << "|" << current->GetArrive() << "|" << current->GetTransport() << ";" <<endl;
        }
    }
  }
  else if(typeTrajet==2){
    cout << "Enregistrement Trajet Compose" << endl;
    for(int i=0; i < nombreDeTrajets;i++) {
      Trajet* curr = trajets[i];
      if(trajets[i]->GetType()=='C'){
          TrajetComplexe* current = (TrajetComplexe*) curr;
          int number = current->GetNumber();
          file << "TC|" << number<< "|" << current->GetDepart() << "|" << current->GetArrive() << ";" << endl;
          TrajetSimple** elements=current->GetElements();
          for (int j=0; j<number ; j++){
              file << "TS|" << elements[j]->GetDepart() << "|" << elements[j]->GetArrive() << "|" << elements[j]->GetTransport() << ";" <<endl;
          }
          file << "---------------------------------- End of elementary itineraries;" << endl;
      }
    }
  }
}

void Catalogue::RestitutionTypeTrajet(string filename, int typeTrajet)
{
  ifstream file(filename.c_str());
  if (file.good())
  {
      cout << "Made it past good" << endl;
      string input;
      while(getline(file,input))
      {
          cout << "Made it past getline" << endl;
          int start=0;
          int end=input.find('|');
          string type = input.substr(start, end);

          if(typeTrajet==1){ // Si on ne veut restaurer que les trajets simples
            if (type.compare("TS")==0){
                cout << "Made it past typecompare" << endl;
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                cout << start;
                cout << end;
                cout << depart;
                start=end+1;
                end=input.find('|',start);
                string arrive=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string transport=input.substr(start, end-start);
                TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                Ajouter(curr);
            }
            if(type.compare("TC")==0){
              start=end+1;
              end=input.find('|',start);
              int nombre=stoi(input.substr(start, end-start));
              for(int i=0;i<nombre;i++){
                getline(file, input);
              }
            }
          }
          if(typeTrajet==2){ // Si on ne veut restaurer que les trajets composés
            if (type.compare("TC")==0){
                cout << "Made it past compare TC" << endl;
                start=end+1;
                end=input.find('|',start);
                int nombre=stoi(input.substr(start, end-start));
                TrajetSimple** elements = new TrajetSimple*[nombre];
                for (int i=0; i<nombre; i++){
                    getline(file, input);
                    start=input.find('|')+1;
                    end=input.find('|',start);
                    string depart=input.substr(start, end-start);
                    start=end+1;
                    end=input.find('|',start);
                    string arrive=input.substr(start, end-start);
                    start=end+1;
                    end=input.find(';',start);
                    string transport=input.substr(start, end-start);
                    TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                    elements[i]=curr;
                }
                TrajetComplexe* complexCurr = new TrajetComplexe(elements, nombre);
                Ajouter(complexCurr);
                delete[] elements;
            }
          }
    }
  }
}

void Catalogue::EnregistrementBoth(string filename, string depart, string arrive)
{
    ofstream file(filename.c_str());
    if (file.good())
    {
        for (int i=0; i<nombreDeTrajets; i++)
        {
            Trajet* curr=trajets[i];
            if(trajets[i]->GetType()=='S'){
                TrajetSimple* current = (TrajetSimple*) curr;
                if (depart.compare(current->GetDepart())==0 && arrive.compare(current->GetArrive())==0){
                    file << "TS|" << current->GetDepart() << "|" << current->GetArrive() << "|" << current->GetTransport() << ";" <<endl;
                }
            }
            else if(trajets[i]->GetType()=='C'){
                TrajetComplexe* current = (TrajetComplexe*) curr;
                int number = current->GetNumber();
                if (depart.compare(current->GetDepart())==0 && arrive.compare(current->GetArrive())==0){
                    file << "TC|" << number<< "|" << current->GetDepart() << "|" << current->GetArrive() << ";" << endl;
                    TrajetSimple** elements=current->GetElements();
                    for (int j=0; j<number ; j++){ 
                        file << "TS|" << elements[j]->GetDepart() << "|" << elements[j]->GetArrive() << "|" << elements[j]->GetTransport() << ";" <<endl;
                    }
                    file << "---------------------------------- End of elementary itineraries;" << endl;            
                }
            }
        }
    }
}
void Catalogue::RestitutionBoth(string filename, string mondepart, string monarrive)
{
    ifstream file(filename.c_str());
    if (file.good())
    {
        string input;
        while(getline(file,input))
        {
            cout << "Made it past getline" << endl;
            int start=0;
            int end=input.find('|');
            string type = input.substr(start, end);
            if (type.compare("TS")==0){
                cout << "Made it past typecompare" << endl;
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                cout << start;
                cout << end;
                cout << depart;
                start=end+1;
                end=input.find('|',start);
                string arrive=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string transport=input.substr(start, end-start);
                if (depart.compare(mondepart)==0 && arrive.compare(monarrive)==0){
                    TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);

                    Ajouter(curr);
                }   
            }
            else if (type.compare("TC")==0){ 
                start=end+1;
                end=input.find('|',start);
                int nombre=stoi(input.substr(start, end-start));
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string arrive=input.substr(start, end-start);
                if (depart.compare(mondepart)==0 && arrive.compare(monarrive)==0){
                    TrajetSimple** elements = new TrajetSimple*[nombre];
                    for (int i=0; i<nombre; i++){
                        getline(file, input);
                        start=input.find('|')+1;
                        end=input.find('|',start);
                        string depart=input.substr(start, end-start);
                        start=end+1;
                        end=input.find('|',start);
                        string arrive=input.substr(start, end-start);
                        start=end+1;
                        end=input.find(';',start);
                        string transport=input.substr(start, end-start);
                        TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                        elements[i]=curr;
                    }
                    TrajetComplexe* complexCurr = new TrajetComplexe(elements, nombre);
                    delete[] elements;
                    Ajouter(complexCurr);
                }else{
                    for(int i=0;i<nombre;i++){
                        getline(file, input);
                    }
                }
            }
        }
    }
}
void Catalogue::EnregistrementDepart(string filename, string depart)
{
    ofstream file(filename.c_str());
    if (file.good())
    {
        for (int i=0; i<nombreDeTrajets; i++)
        {
            Trajet* curr=trajets[i];
            if(trajets[i]->GetType()=='S'){
                TrajetSimple* current = (TrajetSimple*) curr;
                if (depart.compare(current->GetDepart())==0){
                    file << "TS|" << current->GetDepart() << "|" << current->GetArrive() << "|" << current->GetTransport() << ";" <<endl;
                }
            }
            else if(trajets[i]->GetType()=='C'){
                TrajetComplexe* current = (TrajetComplexe*) curr;
                int number = current->GetNumber();
                if (depart.compare(current->GetDepart())==0 ){
                    file << "TC|" << number<< "|" << current->GetDepart() << "|" << current->GetArrive() << ";" << endl;
                    TrajetSimple** elements=current->GetElements();
                    for (int j=0; j<number ; j++){ 
                        file << "TS|" << elements[j]->GetDepart() << "|" << elements[j]->GetArrive() << "|" << elements[j]->GetTransport() << ";" <<endl;
                    }
                    file << "---------------------------------- End of elementary itineraries;" << endl;            
                }
            }
        }
    }
}
void Catalogue::RestitutionDepart(string filename, string mondepart)
{
    ifstream file(filename.c_str());
    if (file.good())
    {
        string input;
        while(getline(file,input))
        {
            cout << "Made it past getline" << endl;
            int start=0;
            int end=input.find('|');
            string type = input.substr(start, end);
            if (type.compare("TS")==0){
                cout << "Made it past typecompare" << endl;
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                cout << start;
                cout << end;
                cout << depart;
                start=end+1;
                end=input.find('|',start);
                string arrive=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string transport=input.substr(start, end-start);
                if (depart.compare(mondepart)==0){
                    TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);

                    Ajouter(curr);
                }   
            }
            else if (type.compare("TC")==0){ 
                start=end+1;
                end=input.find('|',start);
                int nombre=stoi(input.substr(start, end-start));
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string arrive=input.substr(start, end-start);
                if (depart.compare(mondepart)==0){
                    TrajetSimple** elements = new TrajetSimple*[nombre];
                    for (int i=0; i<nombre; i++){
                        getline(file, input);
                        start=input.find('|')+1;
                        end=input.find('|',start);
                        string depart=input.substr(start, end-start);
                        start=end+1;
                        end=input.find('|',start);
                        string arrive=input.substr(start, end-start);
                        start=end+1;
                        end=input.find(';',start);
                        string transport=input.substr(start, end-start);
                        TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                        elements[i]=curr;
                    }
                    TrajetComplexe* complexCurr = new TrajetComplexe(elements, nombre);
                    delete [] elements;
                    Ajouter(complexCurr);
                }else{
                    for(int i=0;i<nombre;i++){
                        getline(file, input);
                    }
                }
            }
        }
    }
}
void Catalogue::EnregistrementArrive(string filename, string arrive)
{
    ofstream file(filename.c_str());
    if (file.good())
    {
        for (int i=0; i<nombreDeTrajets; i++)
        {
            Trajet* curr=trajets[i];
            if(trajets[i]->GetType()=='S'){
                TrajetSimple* current = (TrajetSimple*) curr;
                if (arrive.compare(current->GetArrive())==0){
                    file << "TS|" << current->GetDepart() << "|" << current->GetArrive() << "|" << current->GetTransport() << ";" <<endl;
                }
            }
            else if(trajets[i]->GetType()=='C'){
                TrajetComplexe* current = (TrajetComplexe*) curr;
                int number = current->GetNumber();
                if (arrive.compare(current->GetArrive())==0 ){
                    file << "TC|" << number<< "|" << current->GetDepart() << "|" << current->GetArrive() << ";" << endl;
                    TrajetSimple** elements=current->GetElements();
                    for (int j=0; j<number ; j++){ 
                        file << "TS|" << elements[j]->GetDepart() << "|" << elements[j]->GetArrive() << "|" << elements[j]->GetTransport() << ";" <<endl;
                    }
                    file << "---------------------------------- End of elementary itineraries;" << endl;            
                }
            }
        }
    }
}
void Catalogue::RestitutionArrive(string filename, string monarrive)
{
    ifstream file(filename.c_str());
    if (file.good())
    {
        string input;
        while(getline(file,input))
        {
            cout << "Made it past getline" << endl;
            int start=0;
            int end=input.find('|');
            string type = input.substr(start, end);
            if (type.compare("TS")==0){
                cout << "Made it past typecompare" << endl;
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                cout << start;
                cout << end;
                cout << depart;
                start=end+1;
                end=input.find('|',start);
                string arrive=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string transport=input.substr(start, end-start);
                if (arrive.compare(monarrive)==0){
                    TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);

                    Ajouter(curr);
                }   
            }
            else if (type.compare("TC")==0){ 
                start=end+1;
                end=input.find('|',start);
                int nombre=stoi(input.substr(start, end-start));
                start=end+1;
                end=input.find('|',start);
                string depart=input.substr(start, end-start);
                start=end+1;
                end=input.find(';',start);
                string arrive=input.substr(start, end-start);
                if (arrive.compare(monarrive)==0){
                    TrajetSimple** elements = new TrajetSimple*[nombre];
                    for (int i=0; i<nombre; i++){
                        getline(file, input);
                        start=input.find('|')+1;
                        end=input.find('|',start);
                        string depart=input.substr(start, end-start);
                        start=end+1;
                        end=input.find('|',start);
                        string arrive=input.substr(start, end-start);
                        start=end+1;
                        end=input.find(';',start);
                        string transport=input.substr(start, end-start);
                        TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                        elements[i]=curr;
                    }
                    TrajetComplexe* complexCurr = new TrajetComplexe(elements, nombre);
                    delete[] elements;
                    Ajouter(complexCurr);
                }else{
                    for(int i=0;i<nombre;i++){
                        getline(file, input);
                    }
                }
            }
        }
    }
}
void Catalogue::EnregistrementIntervalle(string filename, int n, int m)
{
    ofstream file(filename.c_str());
    if(file.good())
    {
        for(int i=n-1; i < m;i++) {
            Trajet* curr = trajets[i];
            if(trajets[i]->GetType()=='S'){
                TrajetSimple* current = (TrajetSimple*) curr;
                file << "TS|" << current->GetDepart() << "|" << current->GetArrive() << "|" << current->GetTransport() << ";" <<endl;
            }
            else if(trajets[i]->GetType()=='C'){
                TrajetComplexe* current = (TrajetComplexe*) curr;
                int number = current->GetNumber();
                file << "TC|" << number<< "|" << current->GetDepart() << "|" << current->GetArrive() << ";" << endl;
                TrajetSimple** elements=current->GetElements();
                for (int j=0; j<number ; j++){ 
                    file << "TS|" << elements[j]->GetDepart() << "|" << elements[j]->GetArrive() << "|" << elements[j]->GetTransport() << ";" <<endl;
                }
                file << "---------------------------------- End of elementary itineraries;" << endl;
            }
        }
    }
}
void Catalogue::RestitutionIntervalle(string filename, int n, int m)
{
    ifstream file(filename.c_str());
    if (file.good())
    {
        int beginning = n-1;
        int ending = m-1;
        int k=0;
        cout << "Made it past good" << endl;
        string input;
        while(getline(file,input) && k <=ending)
        {
            cout << "Made it past getline" << endl;
            int start=0;
            int end=input.find('|');
            string type = input.substr(start, end);
            if (type.compare("TS")==0){
                cout << "Made it past typecompare TS" << endl;
                if(k>=beginning) {
                    start=end+1;
                    end=input.find('|',start);
                    string depart=input.substr(start, end-start);
                    cout << start;
                    cout << end;
                    cout << depart;
                    start=end+1;
                    end=input.find('|',start);
                    string arrive=input.substr(start, end-start);
                    start=end+1;
                    end=input.find(';',start);
                    string transport=input.substr(start, end-start);
                    TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                    Ajouter(curr);
                }
            }
            else if (type.compare("TC")==0){ 
                start=end+1;
                end=input.find('|',start);
                int nombre=stoi(input.substr(start, end-start));
                cout << "Made it past typecompare TC" << endl;
                if(k<beginning) {
                    int temp = k;
                    while(temp<=beginning+1) {
                        getline(file, input);
                        temp++;
                    }
                }
                else {
                TrajetSimple** elements = new TrajetSimple*[nombre];
                for (int i=0; i<nombre; i++){
                    getline(file, input);
                    start=input.find('|')+1;
                    end=input.find('|',start);
                    string depart=input.substr(start, end-start);
                    start=end+1;
                    end=input.find('|',start);
                    string arrive=input.substr(start, end-start);
                    start=end+1;
                    end=input.find(';',start);
                    string transport=input.substr(start, end-start);
                    TrajetSimple* curr = new TrajetSimple(depart,arrive,transport);
                    elements[i]=curr;
                }
                TrajetComplexe* complexCurr = new TrajetComplexe(elements, nombre);
                delete[] elements;
                Ajouter(complexCurr);
                    getline(file, input);
                }
            }
            k++;
        }
    }
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
