#include "listaencadeada.h"

int main(){
    list *topo,*p;
    int idInicial,opcao,num,index,emptvet = 0;

    printf("Digitar numero para iniciar a lista\n");
    scanf("%d", &idInicial);   
    iniciaLista(&topo,idInicial);

    do{
        printf("Digite 1 para ver a lista, 2 inserir no final da lista, 3 para inserir por indicie, 4 para remover o final da lista,\n5 para remover por indicie e 9 para sair\n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: 
                printaLista(topo);
                break;
            
            case 2:
                printf("Digite um número: \n");
                scanf("%d", &num);
                insereFinal(topo,num);
                printaLista(topo);
                break;
            
            case 3:
                printf("O tamanho da lista é %d, onde e o que deseja inserir? \n", tamanhodaLista(topo));
                scanf("%d %d", &index,&num);
                if(index == 0){
                    insereIndicie0(&topo, num);
                }else{
                    insereporIndicie(topo, index, num);
                }
                printaLista(topo);
                break;
            
            case 4:
                emptvet = removerfinaldaLista(topo);
                if (emptvet == 1){
                    printf("Lista excluida.\n");
                    break;
                }
                printaLista(topo);
                break;
            
            case 5: 
                printf("O tamanho da lista é %d, onde deseja remover? \n", tamanhodaLista(topo));
                scanf("%d", &index);
                if(index == 0){
                    removerIncidie0(&topo);
                }
                else{
                    removeporIncidie(topo,index); 
                }
                printaLista(topo);
                break;

            default:
                break;
        }
    }while(opcao > 0 && opcao <= 8 && emptvet != 1);

    while(topo->prox != NULL){
        p = topo;
        topo = topo->prox;
        free(p);
    }
    free(topo);

}