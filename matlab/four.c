#include <stdio.h>
#include <stdlib.h>

int main() {
    int taille;
    scanf("%d", &taille);
    int* arr = (int*) malloc(sizeof(int) * taille);
    int* arr2;
    int resized = 0;
    int filled = 0;
    while(1)
    {
        int number;
        int nbtokens = scanf("%d", &number);
        if(nbtokens != 1 || feof(stdin)) {
            break;
        }

        if(filled<taille) {
            arr[filled] = number;
            filled++;
        }
        else {
            resized = 1;
            arr2 = realloc(arr, sizeof(arr) + sizeof(int));
            arr2[taille] = number;
            taille++;
            filled++;
        }
    }
    if(resized) {
        free(arr);
        arr = arr2;
    }
    int min = arr[0];
    int max = arr[0];
    int somme = arr[0];
    int i;
    for(i=1;i<taille;i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        somme=somme + arr[i];
    }
    
    int moyenne = somme/taille;
    int x;
    for(x=0; x<6;x++) {
        printf("%d\n", arr[x]);
    }
    printf("N: %d min: %d, max: %d, moy: %d\r\n", taille, min, max, moyenne);
    return 0;
}
