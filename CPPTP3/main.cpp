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

using namespace std; 
  
int main(int argc, char** argv) 
{ 
    string fileName = argv[(argc-1)];
    if(argc==1) 
        printf("\nNo log file name was passed"); 
    else if(argc==2) 
    {
        printf("\nBasic functionality, no options/specifications, 
        just give top 10");
    }
    else {
        for (int i = 0; i < argc-1; ++i) {
            cout << argv[i] << "\n";       
        }
    }
    return 0; 
} 
                        