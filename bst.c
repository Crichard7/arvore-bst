#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

no* inserir(no *raiz, int valor){
    //Caso base
    if(raiz == NULL){
        no *novo;
        //Alocação de memória
        novo = (no*)malloc(sizeof(no));
        //Inicialização de valores
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        //Retorno do ponteiro para o nó criado
        return novo;
    } else {
        //Verificação para inserção de valores à esquerda (se <) ou à direita (se >)
        if(valor > raiz->valor){
            raiz->dir = inserir(raiz->dir, valor);
        } else {
            raiz->esq = inserir(raiz->esq, valor);
        }
        return raiz;
    }
}

void preOrder(no *raiz){
    if(raiz != NULL){
        printf("[%d]", raiz->valor);
        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

void inOrder(no *raiz){
    if(raiz != NULL){
        inOrder(raiz->esq);
        printf("[%d]", raiz->valor);
        inOrder(raiz->dir);
    }
}

void posOrder(no *raiz){
    if(raiz != NULL){
        posOrder(raiz->esq);
        posOrder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

no* buscar(no *raiz, int valor){
    if(raiz != NULL){
        if(valor == raiz->valor){
            return raiz;
        }
        else if(valor < raiz->valor){
            return buscar(raiz->esq, valor);
        }
        else{
            return buscar(raiz->dir, valor);
        }
    }
    else{
        return NULL;
    }
}

int altura(no *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int altura_esq = altura(raiz->esq);
        int altura_dir = altura(raiz->dir);
        if(altura_esq > altura_dir)
            return altura_esq + 1;
        else
            return altura_dir + 1;
    }
}

int qtd_nos(no *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);
}

int qtd_folhas(no *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    else
        return qtd_folhas(raiz->esq) + qtd_folhas(raiz->dir);
}

// Função para remover nós da árvore bst
no* remover(no *raiz, int valor){
    if(raiz == NULL){
        printf("Elemento não encontrado!\n");
        return NULL;
    }
    //Procura o nó a ser removido
    else{
        if(raiz->valor == valor){
            //remove nós folhas
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                printf("Elemento removido: %d!\n", valor);
                return NULL;
            }
            else{
                //remove nós que possuem 2 filhos
                if(raiz->esq != NULL && raiz->dir != NULL){

                }
                //remove nós que possuem apenas 1 filho
                else{
                    no *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d!\n", valor);
                    return aux;
                }
            }
        }
        else{
            if(valor < raiz->valor)
                raiz->esq = remover(raiz->esq, valor);
            else
                raiz->dir = remover(raiz->dir, valor);
            return raiz;
        }
    }
}
