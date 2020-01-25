/******************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

#include "Lecture.h"
#include <iostream> 

using namespace std;

int getHour(string input) {
  int start = input.find(':')+1;
  int end = start+2;
  string time = input.substr(start, end-start);
  int hour=stoi(time);
  return hour;
}
string getDestinationLink(string input) {
  string destinationLink;
  int linkLength = input.find(" HTTP")- input.find("GET")-4;
  destinationLink = input.substr(input.find("GET ")+4, linkLength);
  if(destinationLink.back()=='/') {
      destinationLink = destinationLink.substr(0, destinationLink.size()-1);
  }
  return destinationLink;
}

string getReferrerLink(string input) {
  int start = input.find("http://intranet-if.insa-lyon.fr/") + 31;
  int ending = input.find('\"', start);
  int linkLength = ending-(start);
  string referrerLink = input.substr(start, linkLength);

  if(referrerLink.back()=='/') {
    referrerLink = referrerLink.substr(0, referrerLink.size()-1);
  }
  return referrerLink;
}

bool isImageType(string input) {
  bool isImageType = false;
  if(input.find("jpg") || input.find("png") || input.find("gif") || 
  input.find("ico") || input.find("css") || input.find("js")) {
    isImageType = true;
  }
  return isImageType;
}

string getIpAddress(string input) {
  int start = 0;
  int end = input.find(' ');
  string ipAddress = input.substr(start, end);
  return ipAddress;
}

string getUserLogname(string input) {
  int start = input.find(' ');
  int end = input.find(' ',start+1);
  string userLogname = input.substr(start+1,end-start);
  return userLogname;
}

string getAuthenticatedUser(string input) {
  int currentIndex = input.find(' ');
  int start = input.find(' ',currentIndex+1);
  int end = input.find(' ',start+1);
  string authenticatedUser = input.substr(start+1,end-start);
  return authenticatedUser;
}

string getDate(string input) {
  int start = input.find('[');
  int end = input.find(':',start);
  string date = input.substr(start+1,end-start-1);
  return date;

}

string getTimezone(string input) {
  int end = input.find(']');
  int start = end-5;
  string timezone = input.substr(start,end-start);
  return timezone;
}

string getRequestType(string input) {
  int start = input.find('"');
  int end = input.find(' ',start+1);
  string action = input.substr(start+1,end-start-1);
  return action;
}

int getStatus(string input) {
  int start = input.find("\" ");
  int end = input.find(' ',start+2);
  string statusInput = input.substr(start+2,end-start-1);
  int status = stoi(statusInput);
  return status;
}

int getQData(string input) {
  int start = input.find("\" ")+6;
  int end = input.find(' ',start+1);
  string dataInput = input.substr(start,end-start);
  int data = stoi(dataInput);
  return data;
}

string getNavId(string input) {
  int start = input.find("\" \"")+3;
  int end = input.find('"',start);
  string navId = input.substr(start,end-start);
  return navId;
}