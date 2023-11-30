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

Arvore *inserir(int n,Arvore *a){
    if(estaVazia(a)){
        return criaNo(n,inicializa(),inicializa());
    }else{
        if(n < a->info){
            a->esquerda=inserir(n,a->esquerda);
        }
        if(n > a->info){
            a->direita=inserir(n,a->direita);
        }
        return a;
    }
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

Arvore *menorNo(Arvore* no) {
    Arvore* atual = no;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

Arvore* remover(Arvore* a, int n) {
    if (a == NULL) {
        return a;
    } else {
        if (n < a->info) {
            a->esquerda = remover(a->esquerda, n);
        } else if (n > a->info) {
            a->direita = remover(a->direita, n);
        } else {
            if (a->esquerda == NULL) {
                Arvore* temp = a->direita;
                free(a);
                return temp;
            } else if (a->direita == NULL) {
                Arvore* temp = a->esquerda;
                free(a);
                return temp;
            }

            Arvore* temp = menorNo(a->direita);
            a->info = temp->info;
            a->direita = remover(a->direita, temp->info);
        }
        return a;
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

    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\ARVORE BINÁRIA DE BUSCA\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf(" \n\nO que deseja ? \n\n[1]INSERIR\n[2]REMOVER\n[3]BUSCAR\n[4]IMPRESSÃO PRE-ORDEM\n[5]IMPRESSÃO EM-ORDEM\n[6]IMPRESSÃO PÓS-ORDEM\n");

    int op,valor;
    Arvore *p=NULL;

    do{
            scanf("%d",&op);
        switch(op){
            case 1:
                printf("Informe o valor do No: ");
                scanf("%d",&valor);
                p=inserir(valor,p);
                break;
            case 2:
                printf("Informe o valor do No que deseja remover: ");
                scanf("%d",&valor);
                p=remover(p,valor);
                break;
            case 3:
                printf("Informe o valor do No que deseja buscar: ");
                scanf("%d",&valor);
                if (!busca(p,valor)){
                    printf("\nInformacao INEXISTENTE!\n");
                }else{
                    printf("\nInformacao ENCONTRADA COM SUCESSO!\n");
                }
                break;
            case 4:
                if(p==NULL){
                    printf("Arvore vazia!");
                }else{
                    imprimePre(p);
                    printf("\n");
                }
                break;
            case 5:
                if(p==NULL){
                    printf("Arvore vazia!");
                }else{
                    imprimeIn(p);
                    printf("\n");
                }
                break;
            case 6:
                if(p==NULL){
                    printf("Arvore vazia!");
                }else{
                    imprimePos(p);
                    printf("\n");
                }
                break;
            case 0:
                printf("FINALIZANDOOOOOOOOOOOOOOOOOOOO");
                break;
            default:
                printf("Opcao invalida");
        }
    }while(op!=0);

     return 0;
}


