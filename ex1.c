#include<stdlib.h>

#include"ex1.h"


//recherche
//supression
arbrebin* creer_arbre(arbrebin*a,int niveaux){
    //Cas de base
     if (niveaux == 0) {
        return NULL;
    }
     a=(arbrebin*)malloc(sizeof(arbrebin));
      if(a==NULL){
            printf("erreur");
            exit(-1);
        }
    printf("Entrez la valeur pour le noeud actuel : ");
    scanf("%d", &a->val);
     a->fd=NULL;
     a->fg=NULL;
    creer_arbre(a->fd, niveaux - 1);
    creer_arbre(a->fg, niveaux - 1);
    return a;
}
arbrebin* recherche(arbrebin*a,int v){
    if(a==NULL||(a->val==v)){
        return a;

  }else{
        return recherche(a->fd,v);
        return recherche(a->fd,v);
    }
}

int main(){
    arbrebin* a;
    int v;
    int niveaux=3;
    a=creer_arbre(a,niveaux);
    printf("Donner l'element a rechercher:");
    scanf("%d",&v);
    if(recherche(a,v)==NULL){
        printf("Introuvable!!");
    }else{
        printf("%d se trouve",v);
    }
    return 0;
}
