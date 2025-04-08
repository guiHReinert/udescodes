#include <stdio.h>
#include <stdlib.h>

// 7
struct descritor{
    int tamanho;
    struct nodo *inicio;
};

struct nodo{
    struct data *dt;
    struct nodo *link;
};

struct data{
    char nome[99];
    int idade;
};

int contarDescritor(struct descritor *p){
    p->tamanho = 0;
    if(p){
        struct nodo *walker = p->inicio;
        while(walker != NULL){
            p->tamanho++;
            if(walker->link == walker){
                break;
            }
            walker = walker->link;
            if(walker == p->inicio){
                break;
            }
        }
    }
    return p->tamanho;
};

int reinicia(struct descritor *p){
    struct nodo *sniffer;
    if(p && p->tamanho > 0){
        sniffer = p->inicio;
        while(sniffer != NULL){
            if(sniffer->link = sniffer){
                break;
            }
            struct nodo *old = sniffer;
            sniffer = sniffer->link;
            free(old);
            if(sniffer = p->inicio){
                break;
            }
        }
        p->tamanho = 0;
        return 1;
    }
    return 0;
};

// Assumindo posicao com intervalo de 0 a p->tamanho-1
int insere(struct descritor *p, struct nodo *nd, int pos){
    struct nodo *holder;
    if(p && nd){
        if(p->inicio == NULL || pos < 0 || pos >= p->tamanho){
            return 0;
        }
        else{
            if(pos == 0){
                nd->link = p->inicio;
                p->inicio = nd;
            }
            else{
                holder = p->inicio;
                for(int c=1; c < pos; c++){
                    holder = holder->link;
                }
                nd->link = holder;
                holder = nd;
                p->tamanho++;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    struct data dt4 = {"Guilherme", 20},
    dt3 = {"Amanda", 30},
    dt2 = {"Lucas", 25},
    dt1 = {"Ana", 22};
    
    struct nodo nd4 = {&dt4, NULL},
    nd3 = {&dt3, &nd4},
    nd2 = {&dt2, &nd3},
    nd1 = {&dt1, &nd2};
    
    struct descritor desc = {0, NULL};
    struct descritor *p = &desc;
    p->inicio = &nd1;
    { // Teste com last->link == NULL
        p->tamanho = contarDescritor(p);
        printf("Tamanho do descritor de teste 1: %d\n", p->tamanho);
        reinicia(p);
        printf("descritor reiniciado: %d\n", p->tamanho);
        insere(p, &nd1, 0);
        p->tamanho = contarDescritor(p);
        printf("Tamanho do descritor com insercao: %d\n\n", p->tamanho);
    }
    { // Teste com last->link == teste->inicio
        nd4.link = &nd4;
        p->tamanho = contarDescritor(p);
        printf("Tamanho do descritor de teste 2: %d\n", p->tamanho);
        reinicia(p);
        printf("descritor reiniciado: %d\n", p->tamanho);
        insere(p, &nd1, 0);
        insere(p, &nd2, 1);
        p->tamanho = contarDescritor(p);
        printf("Tamanho do descritor com 2 insercoes: %d\n\n", p->tamanho);

    }
    { // Teste com last->link == last
        nd4.link = &nd1;
        p->tamanho = contarDescritor(p);
        printf("Tamanho do descritor de teste 3: %d\n", p->tamanho);
        reinicia(p);
        printf("descritor reiniciado: %d\n", p->tamanho);
        insere(p, &nd1, 0);
        insere(p, &nd2, 1);
        insere(p, &nd3, 2);
        p->tamanho = contarDescritor(p);
        printf("Tamanho do descritor com 3 insercoes: %d\n\n", p->tamanho);

    }
    return 0;
}