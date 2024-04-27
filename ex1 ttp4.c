#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ex1.h"
#define MAXLENGTH 100
void remplir_fichier(FILE* fp,int n){
    char ch[MAXLENGTH];
    int t;
    fp=fopen("user_trace","w");
    if(fp==NULL){
        printf("erreur");
        exit(-1);
    }
    for(int i=0;i<n;i++){
        printf("User Name:");
        scanf("%s",ch);
    printf("\nTime spent:");
        scanf("%d",&t);
        fprintf(fp,"%s %d\n",ch,t);
    }

    fclose(fp);
}

void afficher_fichier(FILE* fp){
    char ch[MAXLENGTH];
    fp=fopen("recap","r");
    if(fp==NULL){
        printf("erreur");
        exit(-1);
    }
    while(fgets(ch,sizeof(ch),fp)!=NULL){
        printf("%s",ch);
    }
    fclose(fp);
}
//charger fp dans une liste chainée
void charger(FILE*fp,liste**l){
    char ch[MAXLENGTH];
    int t;
    fp=fopen("user_trace","r");
    if(fp==NULL){
        printf("erreur");
        exit(-1);
    }
    *l=(liste*)malloc(sizeof(liste));
    if(*l==NULL){
        printf("erreur");
        exit(-1);
    }
    (*l)->next=NULL;
    liste*p=*l;
    while(fscanf(fp,"%s %d\n",ch,&t)==2){
        strcpy(p->val.name,ch);
        p->val.time=t;
        p->next=(liste*)malloc(sizeof(liste));
        if(p->next==NULL){
            printf("erreur");
            exit(-1);
        }
        p=p->next;
    }
    fclose(fp);
}
//Afficher la list
void afficher_list(liste*l){
    while(l->next!=NULL){
        printf("%s  %d\n",l->val.name,l->val.time);
        l=l->next;
    }
}

//Traitement
void modify(liste*l,FILE*fp){
    char name[MAXLENGTH];
    int time;
    liste*k;
    fp=fopen("recap","w");
    if(fp==NULL){
        printf("erreur");
        exit(-1);
    }
    liste*p=l;
    while(p!=NULL){
     time=0;
     strcpy(name,p->val.name);
     k=l;
     while(k!=NULL){
        if(strcmp(name,k->val.name)==0){
            time=time+k->val.time;
        }
        k=k->next;
        }
        fprintf(fp, "%s %d\n", name, time);

        p=p->next;
     }
    fclose(fp);
}
int main(){
     FILE*fp;
     FILE*fp1;
     int n=4;
     liste*l;
     remplir_fichier(fp,n);
     charger(fp,&l);
     afficher_list(l);
     modify(l,fp1);
     printf("Affichage apres modification\n");
     afficher_fichier(fp1);
     return 0;

}
