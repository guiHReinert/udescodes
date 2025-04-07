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
    struct nodo *sniffer;
    if(p && p->tamanho != 0){
        sniffer = p->inicio;
        while(sniffer != NULL){
            sniffer = sniffer->link;
            free(p->inicio);
            p->inicio = sniffer;
        }
        p->tamanho = 0;
        return 1;
    }
    return 0;
};

// Assumindo posicao com intervalo de 0 a p->tamanho-1
int insere(struct descritor *p, struct nodo *nd, int pos){
    struct nodo *holder, *walker;
    if(p && nd){
    //     p->tamanho = 1;
    //     sniffer = p->inicio;
    //     while(sniffer != NULL){
    //         p->tamanho++;
    //         sniffer = sniffer->link;
    //     }
        if(p->inicio == NULL || pos < 0 || pos >= p->tamanho){
            return 0;
        }
        else{
            if(pos == 0){
                nd->link = p->inicio;
                p->inicio = nd;esc
            }
            else{
                walker = p->inicio;
                for(int c=1; c < p->tamanho; c++){
                    if(c == pos){
                        // Armazenar a cadeia dependente do nodo anterior a pos
                        holder = (struct nodo*)realloc(walker, sizeof(walker)*(p->tamanho-pos));
                        // Insere o nodo nd
                        walker = nd;
                        // Retorno da cadeia contida em holder para a cadeia original
                        walker->link = holder;
                        free(holder);
                    }
                    else{
                        walker = walker->link;
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

int main(){

    return 0;
}