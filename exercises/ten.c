#include <stdio.h>
#include <stdlib.h>

typedef struct _elem
{
    int value;
    struct _elem* next;
} elem;

elem* list = NULL;

void afficher();
void ajouter_en_tete();

int main(void)
{
    while(1)
    {
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t0: quitter\n");
        int choix;
        scanf("%d", &choix);
        switch(choix)
        {
            case 0:
            goto fin;
            case 1:
            ajouter_en_tete();
            break;
            case 2:
            afficher();
            break;
            default:
            printf("choix incorrect\n");
            continue ; // revenir au menu
        }
    }
    fin:
    printf("au revoir\n");
    return 0;
}

void afficher() {
    elem *current = list;
    printf("affichage de la liste:\n");
    if(current==NULL) {
        printf("fin de la liste\n");
        return;
    }
    do {
        printf("%d", current->value);
        current = current->next;
    } while(current->next!=NULL);
    printf("fin de la liste");
}
void ajouter_en_tete() {
    elem *current = list;
    printf("tapez un nombre:\n");
    int val;
    scanf("%d", &val);
    if(current==NULL) {
        //current->value = val;
    }
}