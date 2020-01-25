/******************************************************************************
                           Lecture  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

#if ! defined ( LECTURE_H )
#define LECTURE_H

#include <string> 
using namespace std;

int getHour(string input);
string getDestinationLink(string input);
string getReferrerLink(string input);
bool isImageType(string input);
string getIpAddress(string input);
string getUserLogname(string input);
string getAuthenticatedUser(string input);
string getDate(string input);
string getTimezone(string input);
string getRequestType(string input);
int getStatus(string input);
int getQData(string input);
string getNavId(string input);

#endif // LECTURE_H