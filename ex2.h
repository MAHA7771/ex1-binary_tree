#ifndef EX2//EX2
#define EX2

struct liste_int
{
int val ;
struct liste_int *next ;
};
typedef struct liste_int LISTE_INT ;

int appartient(int x, LISTE_INT *first);
int insere(int x, LISTE_INT **first );
void insere_liste(LISTE_INT *first1, LISTE_INT **first2);
int Commun(LISTE_INT *first1, LISTE_INT *first2);
#endif
