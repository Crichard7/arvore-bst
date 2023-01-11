#include<stdio.h>
#include "bst.h"

int main(){
    no *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\nArvore BST\n1- Inserir\n2 - Imprimir em ordem\n3 - Buscar valor\n0 - Sair");
        printf("\nDigite uma opcao: \n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                //Inserir
                printf("\nDigite o valor a ser inserido: \n");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                //Imprimir em Ordem
                inOrder(raiz);
                break;
            case 3:
                //Buscar
                printf("\nDigite o valor que ser procurado: \n");
                scanf("%d", &valor);
                busca = buscar(raiz, valor);
                if(busca != NULL){
                    printf("\nValor encontrado: %d\n", busca->valor);
                }
                else{
                    printf("\nValor nao encontrado\n");
                }
                break;
            default:
                if(opcao != 0);
                printf("\nOpcao Invalida!!!\n");
        }
    }while(opcao != 0);
}
