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
#include <unordered_map> 
#include <fstream>
#include <vector>
#include "statistics.h"
#include "graph.h"

using namespace std; 

typedef unordered_map<string, int> innerMap;

vector<string> lectureLigne(const string input);
unordered_map<string, innerMap> createGraphMap(string input, string hitLink);

  
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
            string time = input.substr(input.find(':')+1, 2);
            int hour=stoi(time);
            if(hour<= endTime && hour >=startTime) {
                if(includeImages || !(input.find("jpg") || input.find("png") || 
                input.find("gif") || input.find("ico") || input.find("css") || 
                input.find("js"))) {
                    int linkLength = input.find(" HTTP")- input.find("GET")-4;
                    string hitLink = input.substr(input.find("GET ")+4, linkLength);
                    if(hitLink.back()=='/') {
                        hitLink = hitLink.substr(0, hitLink.size()-1);
                    }
                    if (stats.count(hitLink)>0) {
                        stats.at(hitLink)++;
                    }
                    else {
                        stats.insert(pair<string, int>(hitLink, 1));
                    }
                    if(graphFileName != "") {
                        graphInput = createGraphMap(input, hitLink);
                    }
                }
            }
        }
    }
    statistics *statsMap=new statistics(stats);
    statsMap->printTopX(5);
    graph *graphMap=new graph(graphInput);
    graphMap->writeGraph("hi.dot");
    return 0;
} 

unordered_map<string, innerMap> createGraphMap(string input, string hitLink) {
    unordered_map<string, innerMap> newGraph;

    int searchIndex = input.find("HTTP/1.1")+2;
    searchIndex = input.find('\"', searchIndex);
    searchIndex = input.find('\"', searchIndex+1);
    int ending = input.find('\"', searchIndex+1);
    int linkLength = ending-(searchIndex+1);
    string referrerLink = input.substr(searchIndex+1, linkLength);
    if(referrerLink.back()=='/') {
        referrerLink = referrerLink.substr(0, referrerLink.size()-1);
    }

    if (newGraph.count(hitLink)>0) {
        if (newGraph.at(hitLink).count(referrerLink)>0) {
            newGraph.at(hitLink).at(referrerLink)++;
        }
        else {
            newGraph.at(hitLink).insert(pair<string, int>(referrerLink, 1));
        }
    }
    else {
        innerMap referrerMap;
        referrerMap.insert(pair<string, int>(referrerLink, 1));
        newGraph.insert(pair<string, innerMap>(hitLink, referrerMap));
    }

    return newGraph;
}

vector<string> lectureLigne(const string input)
{
  vector<string> output(13,"");

  int start = 0;
  int end = input.find(' ');
  string ipAdress = input.substr(start, end);
  output[0]=ipAdress;

  start = end;
  end = input.find(' ',start+1);
  string userLogname = input.substr(start,end-start);
  output[1]=userLogname;

  start = end;
  end = input.find(' ',start+1);
  string authenticatedUser = input.substr(start,end-start);
  output[2]=authenticatedUser;

  start = input.find('[');
  end = input.find(':',start+1);
  string date = input.substr(start+1,end-start-1);
  output[3]=date;

  start = end;
  end = input.find(' ',start+1);
  string heure = input.substr(start,end-start);
  output[4]=heure;

  start = end;
  end = input.find(']',start+1);
  string gmt = input.substr(start,end-start);
  output[5]=gmt;

  start = input.find('"');
  end = input.find(' ',start+1);
  string action = input.substr(start+1,end-start-1);
  output[6]=action;

  start = end;
  end = input.find(' ',start+1);
  string url = input.substr(start,end-start);
  output[7]=url;

  start = end;
  end = input.find('"',start+1);
  string http = input.substr(start,end-start);
  output[8]=http;

  start = end+1;
  end = input.find(' ',start+1);
  string status = input.substr(start+1,end-start);
  output[9]=status;

  start = end;
  end = input.find(' ',start+1);
  string qData = input.substr(start+1,end-start);
  output[10]=qData;

  start = input.find('"',end);
  end = input.find('"',start+1);
  string referer = input.substr(start+1,end-start-1);
  output[11]=referer;

  start = input.find('"',end+1);
  end = input.find('"',start+1);
  string navId = input.substr(start+1,end-start-1);
  output[12]=navId;

  return output;
}
                        