#include <stdio.h>
#include <stdlib.h>

// 7
struct descritor{
    int tamanho;
    struct nodo *inicio;
};

struct nodo{
    struct data dt;
    struct nodo *link;
};

struct data{
    char nome[99];
    int idade;
};

int reinicia(struct descritor *p){
    struct nodo *sniffer, *old;
    if(p){
        sniffer = p->inicio;
        while(sniffer != NULL){
            old = sniffer;
            sniffer = sniffer->link;
            old = NULL;
        }
        sniffer = NULL;
        return 1;
    }
    return 0;
};

int insere(struct descritor *p, struct nodo *nd, int pos){
    struct nodo *sniffer;
    if(p){
        p->tamanho = 1;
        sniffer = p->inicio;
        while(sniffer != NULL){
            p->tamanho++;
            sniffer = sniffer->link;
        }
        if(pos > p->tamanho){
            return 0;
        }
        else{
            for(int c=0; c < p->tamanho; c++){
                
            }
        }
        return 1;
    }
    return 0;
}

int main(){

    return 0;
}