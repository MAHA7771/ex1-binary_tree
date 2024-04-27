#include<stdio.h>
#include<string.h>
#ifndef EX1//EX1
#define EX1
typedef struct valeur{
    char name[100];
    int time;
}valeur;
typedef struct liste{
    valeur val;
    int time;
    struct liste*next;
}liste;
void remplir_fichier(FILE* fp,int n);
void afficher_fichier(FILE* fp);
void charger(FILE*fp,liste**l);
void afficher_list(liste*l);
#endif
