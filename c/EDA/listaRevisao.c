#include <stdio.h>
#include <stdlib.h>



// 6A
struct nodo{
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p){
    struct nodo *aux;
    int count=0;
    if(p){
        count = 1;
        aux = p->link; 
        while(aux-> link != NULL){
            count++;
            aux = aux->link;
        }
    }
    else{return count;}
}

int main(){
    struct nodo s3;
    struct nodo s2 = {&s3};
    struct nodo s1 = {&s2};
    return 0;

    printf("QUANTOS NODO??? (%d)", contaNodo(&s1));

}

// 6B


// 6D
struct descritor{
    unsigned int posicao;
    struct nodo *primeiro, *ultimo, *link;
};
