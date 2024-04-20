#include<stdio.h>
#include<stdlib.h>
#ifndef EX1_H
#define EX1_H

typedef struct arbre_bin{
    struct arbre_bin* fd;
    struct arbre_bin*fg;
    int val;
}arbrebin;

arbrebin* arbre(arbrebin*a,int niveaux);
arbrebin*recherche(arbrebin*a,int v);
#endif /* EX1_H */


