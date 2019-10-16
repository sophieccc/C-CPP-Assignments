#include <stdio.h>
#include <stdlib.h>

int main() {
    int taille;
    scanf("%d", &taille);

    int i;
    int* arr = (int*) malloc(sizeof(int) * taille);
    for(i=0;i<taille;i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];
    int somme = arr[0];

    for(i=1;i<taille;i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        somme=somme + arr[i];
    }

    printf("N: %d min: %d, max: %d, moy: %d\r\n", taille, min, max, somme/taille);
    return 0;
}