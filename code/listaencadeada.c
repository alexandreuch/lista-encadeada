#include "listaencadeada.h"

void iniciaLista(list **topo, int idInicial){
    (*topo) = (list *)malloc(sizeof(list));
    (*topo) -> id = idInicial;
    (*topo) -> prox = NULL;
}

void printaLista(list *topo){
    printf("************************************************************************************************************************\n");
    while(topo !=  NULL){
        printf("%d\t",topo->id);
        topo = topo -> prox;
    }
    printf("\n************************************************************************************************************************\n");
}

void insereFinal(list *topo, int num){
    list *p;
    p = (list *)malloc(sizeof(list));
    p->id = num;
    p->prox = NULL;
    
    while(topo->prox !=  NULL){
        topo = topo -> prox;
    }
    topo -> prox = p;
}

int tamanhodaLista(list *topo){
    int tamanho = 0;

    while(topo != NULL){
        tamanho++;
        topo = topo->prox;
    }
    return tamanho;
}

void insereporIndicie(list *topo, int index, int num){
    int cont = 0;
    list *p,*q;
    p = (list *)malloc(sizeof(list));
    p->id = num;
    p->prox = NULL;

    if(index > tamanhodaLista(topo)){
        printf("Index ainda nao alocado");
        return;
    }

    else{
        for(cont; cont < (index-1); cont++){
            topo = topo -> prox;
        }

        if(topo-> prox == NULL){
            topo -> prox = p;
        }
        else{
            q = topo->prox;
            topo -> prox = p;
            p->prox = q;
        }
    }
}

void insereIndicie0(list **topo, int num){
    list *p,*q;
    p = (list *)malloc(sizeof(list));
    p->id = num;
    p->prox = NULL;

    q = (*topo);
    (*topo) = p;
    (*topo) -> prox = q;
}

int removerfinaldaLista(list *topo){
    list *p;
    if (tamanhodaLista(topo) == 1){
        return 1;
    }
    else{
        while(topo -> prox != NULL){
            p = topo;
            topo = topo->prox;
        }
        free(topo);
        p -> prox = NULL;
        return 0;
    }
}

void removeporIncidie(list *topo, int index){
    list *p,*q;
    int cont = 0;
    if(index > (tamanhodaLista(topo)-1)){
        printf("Index ainda nao alocado");
        return;
    }
    else if(index == (tamanhodaLista(topo)-1)){
        while(topo -> prox != NULL){
            p = topo;
            topo = topo -> prox;
        }
        p->prox = NULL;
        free(topo);
    }
    else{
        for(cont; cont < index; cont ++){
            p = topo;
            topo = topo -> prox;
        }
        q = topo->prox;
        p -> prox = q;
        free(topo);
    }
}

void removerIncidie0(list **topo){
    list *p;
    p = (*topo);
    (*topo) = (*topo)->prox; 
    free(p);
}
