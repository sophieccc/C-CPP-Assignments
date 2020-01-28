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
#include <unordered_map> 
#include <fstream>

#include "Statistics.h"
#include "Graph.h"
#include "Lecture.h"

using namespace std; 

typedef unordered_map<string, int> innerMap;

bool processLogfile(string fileName, int startTime, int endTime, bool includeImages, string graphFile);
string updateStatsMap(string input);
void updateGraphMap(string input, string hitLink);

innerMap statsInput;
unordered_map<string, innerMap> graphInput;
  
int main(int argc, char** argv) 
{ 
    string fileName = argv[(argc-1)];
    if(argc==1) {
        cerr << "No log file name was passed" << endl;
        return 0; 
    }
    string graphFile = "";
    bool includeImages = true;
    int startTime = 0;
    int endTime = 24;
    
    for (int i = 0; i < argc-1; ++i) {
        if (string(argv[i]) == "-g") { 
            if((i+1)< argc-1 && string(argv[i+1]).at(0)!='-') {
                graphFile =  string(argv[++i]);
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
    
    bool success = processLogfile(fileName, startTime, endTime, includeImages, graphFile);
    if(success) {
        Statistics *statsMap=new Statistics(statsInput);
        statsMap->printTopX(10);
        Graph *graphMap=new Graph(graphInput);
        graphMap->writeGraph(graphFile);
    }
    return 0;
} 

bool processLogfile(string fileName, int startTime, int endTime, bool includeImages, string graphFile) {
    ifstream logFile(fileName);
    if(logFile.good()) {
        string input;
        while(getline(logFile,input))
        {
            int hour = getHour(input);
            if(hour<= endTime && hour >=startTime) {
                if(includeImages || !isImageType(input)) {
                    string hitLink = updateStatsMap(input);
                    if(graphFile != "") {
                        updateGraphMap(input, hitLink);
                    }
                }
            }
        }
        return true;
    }
    else {
        cerr << "Bad file input, could not process" << endl;
        return false;
    }
}

string updateStatsMap(string input) 
{
    string hitLink = getDestinationLink(input);
    if (statsInput.count(hitLink)>0) {
        statsInput.at(hitLink)++;
    }
    else {
        statsInput.insert(pair<string, int>(hitLink, 1));
    }
    return hitLink;
}

void updateGraphMap(string input, string hitLink) 
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
}        