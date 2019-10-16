#include <stdio.h>

int main() {
    int i;
    int arr[10];
    for(i=0;i<10;i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int max = arr[0];
    int somme = arr[0];
    for(i=1;i<10;i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        somme=somme + arr[i];
    }
    printf("min: %d, max: %d, moy: %d\r\n", min, max, somme/10);
    return 0;
}