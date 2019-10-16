#include <stdio.h>

struct Complexe {
    float real;
    float imaginary;
};

typedef struct Complexe Complexe;

void affiche(Complexe z);
Complexe ajoute(Complexe z1,Complexe z2);
Complexe multiplie(Complexe z1,Complexe z2);

int main() {
    float a = 0.0;
    float b = 0.0;
    scanf("%f", &a);
    scanf("%f", &b);
    Complexe x = {a,b};
    affiche(x);
    affiche(ajoute(x,x));
    affiche(multiplie(x,x));
    return 0;
}

void affiche(Complexe z) {
    if(z.imaginary > 0) {
        printf("%f + %fi\n", z.real, z.imaginary);
    }
    else if(z.imaginary < 0) {
        printf("%f %fi\n", z.real, z.imaginary);
    }
}

struct Complexe ajoute( Complexe z1,  Complexe z2) {
     Complexe z = {z1.real+z2.real, z1.imaginary+z2.imaginary};
    return z;

}

 Complexe multiplie( Complexe z1,  Complexe z2) {
    Complexe z = {
        (z1.real*z2.real)-(z1.imaginary-z2.imaginary), 
        (z1.real*z2.imaginary)+(z1.imaginary*z2.real)
        };
    return z;
}