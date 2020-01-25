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
#include <cstdlib>
#include <unordered_map> 
#include <fstream>
#include "statistics.h"
#include "graph.h"
#include "Lecture.h"

using namespace std; 

typedef unordered_map<string, int> innerMap;

unordered_map<string, innerMap> updateGraphMap(
    string input, string hitLink, unordered_map<string, innerMap> graphInput);
  
int main(int argc, char** argv) 
{ 
    string fileName = argv[(argc-1)];
    if(argc==1) {
        printf("\nNo log file name was passed");
        return 0; 
    }
    string graphFileName = "";
    bool includeImages = true;
    int startTime = 0;
    int endTime = 24;
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
                startTime = atoi(argv[++i]);
                endTime = startTime+1;
            }
            else {
                printf("No hour was given, time will not be accounted for");
            }    
        }
    } 
    innerMap stats;
    unordered_map<string, innerMap> graphInput;
    ifstream logFile(fileName);
    if(logFile.good()) {
        string input;
        while(getline(logFile,input))
        {
            int hour = getHour(input);
            if(hour<= endTime && hour >=startTime) {
                if(includeImages || !isImageType(input)) {

                    string hitLink = getDestinationLink(input);
                    if (stats.count(hitLink)>0) {
                        stats.at(hitLink)++;
                    }
                    else {
                        stats.insert(pair<string, int>(hitLink, 1));
                    }
                    if(graphFileName != "") {
                        graphInput = updateGraphMap(input, hitLink, graphInput);
                    }
                }
            }
        }
    }
    //statistics *statsMap=new statistics(stats);
    //statsMap->printTopX(5);
    graph *graphMap=new graph(graphInput);
    graphMap->writeGraph("hggi.dot");
    return 0;
} 

unordered_map<string, innerMap> updateGraphMap(
    string input, string hitLink, unordered_map<string, innerMap> graphInput) 
{
    string referrerLink = getReferrerLink(input);
    if (graphInput.count(hitLink)>0) {
        if (graphInput.at(hitLink).count(referrerLink)>0) {
            graphInput.at(hitLink).at(referrerLink)++;
        }
        else {
            graphInput.at(hitLink).insert(pair<string, int>(referrerLink, 1));
        }
    }
    else {
        innerMap referrerMap;
        referrerMap.insert(pair<string, int>(referrerLink, 1));
        graphInput.insert(pair<string, innerMap>(hitLink, referrerMap));
    }

    return graphInput;
}
                        