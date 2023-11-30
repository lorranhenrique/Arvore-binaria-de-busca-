#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Arvore {
    int info;
    struct Arvore *esquerda;
    struct Arvore *direita;
} Arvore;

Arvore *inicializa() {
    return NULL;
}

int estaVazia(Arvore *a) {
    return a == NULL;
}

Arvore *criaNo(int n, Arvore *esquerda, Arvore *direita) {
    Arvore *p = (Arvore *)malloc(sizeof(Arvore));
    p->info = n;
    p->esquerda = esquerda;
    p->direita = direita;
    return p;
}

Arvore *libera(Arvore *a) {
    if (!estaVazia(a)) {
        libera(a->esquerda);
        libera(a->direita);
        free(a);
    }
    return NULL;
}

int busca(Arvore *a, int n) {
    if (estaVazia(a)) {
        return 0;
    } else {
        if (a->info == n) {
            return 1;
        } else {
            if (busca(a->esquerda, n)) {
                return 1;
            } else {
                return busca(a->direita, n);
            }
        }
    }
}

void imprimePre(Arvore *a) {
    if (!estaVazia(a)) {
        printf("%d ", a->info);
        imprimePre(a->esquerda);
        imprimePre(a->direita);
    }
}

void imprimeIn(Arvore *a) {
    if (!estaVazia(a)) {
        imprimeIn(a->esquerda);
        printf("%d ", a->info);
        imprimeIn(a->direita);
    }
}

void imprimePos(Arvore *a) {
    if (!estaVazia(a)) {
        imprimePos(a->esquerda);
        imprimePos(a->direita);
        printf("%d ", a->info);
    }
}

int main() {
    setlocale(LC_ALL,"portuguese");

    Arvore *D = criaNo(3, inicializa(), inicializa());
    Arvore *E = criaNo(5, inicializa(), inicializa());
    Arvore *F = criaNo(4, inicializa(), inicializa());
    Arvore *G = criaNo(6, inicializa(), inicializa());
    Arvore *B = criaNo(1, D, E);
    Arvore *C = criaNo(2, F, G);
    Arvore *A = criaNo(0, B, C);

    printf("Impressão pré-ordem: ");
    imprimePre(A);
    printf("\n");

    printf("Impressão em ordem: ");
    imprimeIn(A);
    printf("\n");

    printf("Impressão pós-ordem: ");
    imprimePos(A);
    printf("\n");

    if (!busca(A, 111)) {
        printf("INFORMAÇÃO INEXISTENTE\n");
    } else {
        printf("INFORMAÇÃO ENCONTRADA\n");
    }

    A = libera(A);

    printf("Após liberar a árvore:\n");

    printf("Impressão pré-ordem: ");
    imprimePre(A);
    printf("\n");

    printf("Impressão em ordem: ");
    imprimeIn(A);
    printf("\n");

    printf("Impressão pós-ordem: ");
    imprimePos(A);
    printf("\n");

    return 0;
}
