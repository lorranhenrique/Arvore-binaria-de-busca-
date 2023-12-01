#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Arvore {
    int info;
    struct Arvore *esquerda;
    struct Arvore *direita;
} Arvore;

Arvore *inicializa();
int estaVazia(Arvore *a);
int getNos(Arvore* a);
Arvore *criaNo(int n, Arvore *esquerda, Arvore *direita);
Arvore *libera(Arvore *a);
Arvore *inserir(int n,Arvore *a);
int busca(Arvore *a, int n);
Arvore *menorNo(Arvore* no);
Arvore* remover(Arvore* a, int n);
void imprimePre(Arvore *a);
void imprimeIn(Arvore *a);
void imprimePos(Arvore *a);
void ImprimeAscendenteOrdem(Arvore *a);
void ImprimeDescendenteOrdem(Arvore *a);
int buscaMaior(Arvore *a);
int buscaMenor(Arvore *a);
int getFolhas(Arvore* a);
int getSomatorio(Arvore* a);

int main() {
    setlocale(LC_ALL,"portuguese");

    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\ARVORE BINÁRIA DE BUSCA\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf(" \n\nO que deseja? \n\n[1]INSERIR\n[2]REMOVER\n[3]BUSCAR\n[4]IMPRESSÃO PRE-ORDEM\n[5]IMPRESSÃO EM-ORDEM\n[6]IMPRESSÃO PÓS-ORDEM\n[7]O MAIOR DA ARVORE\n[8]O MENOR DA ARVORE\n[9]CONTADOR DE NÓS\n[10]SOMATORIO\n[11]FOLHAS\n[12]ASCENDENTE\n[13]DESCENDENTE\n");

    int op,valor,maior,menor,nos,soma,folhas;
    Arvore *p=NULL;

    do{
            printf("\n");
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
                    printf("\nINFORMAÇÃO INEXISTENTE!\n");
                }else{
                    printf("\nINFORMAÇÃO ENCONTRADA COM SUCESSO!\n");
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
            case 7:
                maior=buscaMaior(p);
                printf("O maior da arvore é %d",maior);
                break;
            case 8:
                menor=buscaMenor(p);
                printf("O menor da arvore é %d",menor);
                break;
            case 9:
                nos=getNos(p);
                printf("O número de nós da arvore é %d",nos);
                break;
            case 10:
                soma=getSomatorio(p);
                printf("O somatório dos valores e %d",soma);
                break;
            case 11:
                folhas=getFolhas(p);
                printf("O número de folhas da arvore é %d",folhas);
                break;
            case 12:
                ImprimeAscendenteOrdem(p);
                break;
            case 13:
                ImprimeDescendenteOrdem(p);
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

Arvore *inicializa() {
    return NULL;
}

int estaVazia(Arvore *a) {
    return a == NULL;
}

int getNos(Arvore* a){
    if(estaVazia(a)){
        return 0;
    }else{
        int n = 1;
        n += getNos(a->esquerda);
        n += getNos(a->direita);
        return n;
        }
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
            if (n< a->info) {
                return busca(a->esquerda,n);
            } else {
                if(n>a->info){
                    return busca(a->direita, n);
                }

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

void ImprimeAscendenteOrdem(Arvore *a){
    if (!estaVazia(a)) {
        ImprimeAscendenteOrdem(a->esquerda);
        printf("%d ", a->info);
        ImprimeAscendenteOrdem(a->direita);
    }
}

void ImprimeDescendenteOrdem(Arvore *a){
    if (!estaVazia(a)) {
        ImprimeDescendenteOrdem(a->direita);
        printf("%d ", a->info);
        ImprimeDescendenteOrdem(a->esquerda);
    }
}

int buscaMaior(Arvore *a){
    if(estaVazia(a)){
        return 0;
    }else{
        if (a->direita == NULL) {
        return a->info;
    }else{
        return buscaMaior(a->direita);
    }
    }
}

int buscaMenor(Arvore *a){
    if(estaVazia(a)){
        return 0;
    }else{
        if (a->esquerda == NULL) {
        return a->info;
    }else{
        return buscaMenor(a->esquerda);

    }
    }
}

int getFolhas(Arvore* a) {
    if (estaVazia(a)) {
        return 0;
    } else if (a->esquerda == NULL && a->direita == NULL) {
        return 1;
    } else {
        int folhas = 0;
        folhas += getFolhas(a->esquerda);
        folhas += getFolhas(a->direita);
        return folhas;
    }
}

int getSomatorio(Arvore* a){
    if (estaVazia(a)) {
        return 0;
    } else {
        int somatorio = a->info;
        somatorio += getSomatorio(a->esquerda);
        somatorio += getSomatorio(a->direita);
        return somatorio;
    }
}


