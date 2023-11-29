#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
    int info;
    struct Arvore *esquerda;
    struct Arvore *direita;
}Arvore;

int estaVazia(Arvore* a){
 return a == NULL;
}

Arvore* inicializa(){
 return NULL;
}

int busca(Arvore *a,int c){
    if(estaVazia(a)){
        return 0;
    }else{
        if(c < a->info){
            return busca(a->esquerda,c);
        }else{
            if(c>a->info){
                return busca(a->direita,c);
            }
        }
    }
}

Arvore *inserir(Arvore *a,int c){
    if(estaVazia(a)){
        return criaNo(c,inicializa(),inicializa())
    }else{
        if(c < a->info){
            return inserir(a->esquerda,c);
        }
        if(c > a->info){
            return inserir(a->direita,c);
        }
        return a;
    }
}


int main()
{


}
