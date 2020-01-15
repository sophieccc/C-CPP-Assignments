/******************************************************************************
                           main  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

#include <iostream> 
#include <string> 
#include <cstdlib>

using namespace std; 
  
int main(int argc, char** argv) 
{ 
    string fileName = argv[(argc-1)];
    if(argc==1) 
        printf("\nNo log file name was passed"); 
    else {
        string graphFileName = "";
        bool includeImages = true;
        int time = -1;
        for (int i = 0; i < argc-1; ++i) {
            if (string(argv[i]) == "-g") { 
                if((i+1)< argc-1 && string(argv[i+1]).at(0)!='-') {
                    graphFileName =  string(argv[++i]);
                }
                else {
                    printf("No graph file name was passed, graph will not be made");
                }  
            }
            else if (string(argv[i]) == "-e") { 
                includeImages = false;     
            }        
            else if (string(argv[i]) == "-t") {
                if((i+1)< argc-1 && atoi(argv[i+1])>=0 && atoi(argv[i+1])<24 
                && string(argv[i+1]).at(0)!='-') {
                    time = atoi(argv[++i]);
                }
                else {
                    printf("No hour was given, time will not be accounted for");
                }    
            }
        } 
    }
} 
                        