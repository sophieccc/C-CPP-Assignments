#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _file
{
    int arr[100];
    int debut;
    int fin;
} file;

file* current = NULL;

void initialiser();
int queue(int newValue);
void dequeue();

int main(void)
{
    initialiser();
    int input;
    char direction[10];
    while(1) {
        scanf( " %s", direction);
        if(strcmp(direction, "queue")==0) {
            scanf( " %d", &input);
            queue(input);
        }
        else if(strcmp(direction, "dequeue")==0) {
            dequeue();
        }
        else if(strcmp(direction, "bye")==0) {
            break;
        }
    }
/*
   queue(1);
   queue(2);
   queue(3);
   dequeue();
   dequeue();
   dequeue(); */
    return 0;
}

void initialiser() {
    current = malloc(sizeof(file));
    current->debut = 0;
    current->fin = 0;
}


int queue(int newValue) {
    if(((current->fin%100)+1) == (current->debut%100)) {
        return -1;
    }
    else if(current->fin<100) {
        current->arr[current->fin] = newValue;
        current->fin +=1;
    }
    else if(current->fin==100) {
        current->arr[0] = newValue;
        current->fin = 0;
    }
    return 0;
}

void dequeue() {
    if(current->debut==current->fin) {
        return;
    }
    else if(current->debut>100) {
        if(current->fin==0) {
            return;
        }
        printf("%d\r\n", current->arr[0]) ;
        current->debut = 1;
    }
    int deleted = current->arr[current->debut];
    current->debut +=1;
    printf("%d\r\n", deleted) ;
}