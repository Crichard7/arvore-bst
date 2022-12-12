#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

//opção 1
no* inserir(no *raiz, int valor);

//opção 2
void preOrder(no *raiz);

//opção 3
void inOrder(no *raiz);

//opção 4
void posOrder(no *raiz);


#endif
