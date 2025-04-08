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
    if(p && p->tamanho > 0){
        struct nodo *sniffer;
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
    if(p && nd){
        struct nodo *holder;
        if(pos < 0 || pos > p->tamanho){
            return 0;
        }
        else if(pos == 0){
            nd->link = p->inicio;
            p->inicio = nd;
        }
        else{
            holder = p->inicio;
            for(int c=1; c < pos; c++){
                holder = holder->link;
            }
            nd->link = holder->link;
            holder->link = nd;
        }
        p->tamanho++;
        return 1;
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
    p->tamanho = contarDescritor(p);

    printf("Tamanho do descritor de teste 1: %d\n", p->tamanho);

    reinicia(p);
    printf("Descritor reiniciado: %d\n", p->tamanho);

    insere(p, &nd1, 0);
    p->tamanho = contarDescritor(p);
    printf("Tamanho do descritor com 1 insercao: %d\n\n", p->tamanho);

    insere(p, &nd2, 1);
    insere(p, &nd3, 2);
    insere(p, &nd4, 3);
    printf("Tamanho do descritor com 3 insercoes: %d\n\n", p->tamanho);

    return 0;
}