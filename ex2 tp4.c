#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ex2.h"
int appartient(int x, LISTE_INT *first)
{
    LISTE_INT *p=first;
    while(p!=NULL&&p->val!=x){
        p=p->next;
        }
    if(p!=NULL){
        return 1;
    }else{
    return 0;
    }
}

int insere(int x, LISTE_INT **first )
{
    if(appartient(x,*first)){
        return -1;
    }
    else{
        LISTE_INT*p=*first;
        while(p!=NULL){
            p=p->next;
        }
        p->next->val=x;
        return 1;
    }
}
void insere_liste(LISTE_INT *first1, LISTE_INT **first2)
{
    LISTE_INT*p=first1;
    if(p==NULL){
        return;
    }
    else if(p!=NULL&&appartient(p->val,*first2)!=0){
        insere(p->val,first2);
    }else{
        insere_liste(p->next,first2);
    }
}

int Commun(LISTE_INT *first1, LISTE_INT *first2)
{
    LISTE_INT*p1=first1;
    LISTE_INT*p2=first2;
    if(p1==NULL||p2==NULL){
        return 0;
    }
    else if(appartient(p1->val,first2)){
        return 1;
    }else{
        return Commun(p1->next,p2);
    }
}
void main(){
    int x;
    LISTE_INT*first1;
    LISTE_INT*first2;
    printf("Donner x");
    scanf("%d",&x);
    appartient(x,first1);
    insere(x, &first1 );
    insere_liste(first1, &first2);
}
