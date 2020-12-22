#include "stdio.h"
#include "stdlib.h"

typedef struct lista{
    int id; 
    struct lista *prox;

}list; 

void iniciaLista(list **topo, int idInicial);
void printaLista(list *topo);
void insereFinal(list *topo, int num);
int tamanhodaLista(list *topo);
void insereporIndicie(list *topo, int index, int num);
void insereIndicie0(list **topo, int num);
int removerfinaldaLista(list *topo);
void removeporIncidie(list *topo, int index);
void removerIncidie0(list **topo);
