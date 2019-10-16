#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Personne {
    char *name;
    char number[11];
};

typedef struct Personne Personne;

int main() {
    Personne arr[10];

    int i;
    for(i=0; i < 10;i++) {
        char currentName[50];
        char nbtokens = scanf("%s",currentName);
        if(nbtokens!=1 || feof(stdin)) {
            break;
        }
        arr[i].name = malloc(strlen(currentName)+1);
        int j;
        for(j=0; j < strlen(currentName)+1;j++) {
            arr[i].name[j] = currentName[j];
        }
        scanf("%s", arr[i].number);
    }

    for(i=0; i < 10;i++) {
        printf("%s: %s\r\n", arr[i].name, arr[i].number);
    }
    return 0;
}