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
