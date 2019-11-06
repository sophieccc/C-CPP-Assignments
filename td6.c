#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char * Key;

typedef struct {
    char state;
    Key key;
    char *value;
} Cell;

typedef struct {
    int size; // E = empty, S = set, R = removed
    Cell *tab;
} Hash;

Hash* Initialiser(int size);
void Inserer(Hash* current, char* key, char* value);
void Supprimer(Hash* current,char* key);
char* Query(Hash* current,char* key);
void Afficher(Hash* current);
void Liberer(Hash* current);
void error(void);

int main(void) 
{
   int size;
   char lecture[100];
   char * key;
   char * val;
   Hash *current;

   if (fscanf(stdin,"%99s",lecture)!=1)
      error();
   while (strcmp(lecture,"bye")!=0)
   {
      if (strcmp(lecture,"init")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         size = atoi(lecture);
         current = Initialiser(size);
      }
      else if (strcmp(lecture,"insert")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         val = strdup(lecture);
         Inserer(current, key, val);
      }
      else if (strcmp(lecture,"delete")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         Supprimer(current, key);
      }
      else if (strcmp(lecture,"query")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         char* result = Query(current, key);
         printf("%s\r\n", result);
      }
      else if (strcmp(lecture,"destroy")==0)
      {
         Liberer(current);
      }
      else if (strcmp(lecture,"stats")==0)
      {
         Afficher(current);
      }

      if (fscanf(stdin,"%99s",lecture)!=1)
         error();
   }
   return 0;
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
  n = n%(sizeof(unsigned int)*8);
  return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
   unsigned int i;
   unsigned int val = 0;
   unsigned int power = 0;
   for (i=0;i<strlen(key);i++)
   {
     val += shift_rotate(key[i],power*7);
     power++;
   }
   return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
   return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
   return hash(Encode(key),size);
}

Hash* Initialiser(int size) {
    Hash *current;
    current = (Hash *) malloc(sizeof(Hash));
    current->tab = (Cell*) malloc(sizeof(Cell)*size);
    current->size = size;
    int i;
    Cell* currentCell;
    for(i=0; i < size; i++) {
        currentCell = &current->tab[i];
        currentCell->state = 'E';
    }
    return current;
}

void Inserer(Hash* current, char* key, char* value) {
    unsigned int pos = HashFunction(key, current->size);
    unsigned int currentPos = pos;
    int finished = 0;
    int repeat = 0;
    Cell* currentCell;
    while(finished==0) {
        currentCell = &current->tab[currentPos];
        if(currentPos==current->size) {
            currentPos = 0;
        }
        if(currentCell->state!='S') {
            currentCell->key = key;
            currentCell->value = value;
            currentCell->state = 'S';
            finished = 1;
        }
        else if(currentCell->state=='S' && currentCell->key==key) {
            currentCell->value = value;
            finished = 1;
        }
        else if(repeat==1 && currentPos==pos) {
            finished = 1; // no space left for insertion
        }
        else {
            repeat = 1;
            currentPos++;
        }
    }
}
void Supprimer(Hash* current,char* key) {

}
char* Query(Hash* current,char* key) {
    return "a";
}
void Afficher(Hash* current) {
    int empty = 0;
    int deleted = 0;
    int used = 0;
    int i;
    Cell* currentCell = current->tab;
    for(i=0; i < current->size;i++) {
        if(currentCell->state=='E') {
            empty++;
        }
        else if(currentCell->state=='R') {
            deleted++;
        }
        else if(currentCell->state=='S') {
            used++;
        }
        currentCell++;
    }
    printf("size    : %d\r\nempty   : %d\r\ndeleted : %d\r\nused    : %d\r\n", 
    current->size, empty, deleted, used);
}
void Liberer(Hash* current) {
    free(current->tab);
    free(current);
}

void error(void)
{
   printf("input error\r\n");
   exit(0);
}
