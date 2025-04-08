#include <stdio.h>
#include <stdlib.h>

struct descritor{
    int tamArr;
    struct nodo **arr;
};

struct nodo{
    int x;
    struct nodo *link;
};

int contaNodo(struct descritor *p){
    struct nodo *walker;
    int count=0;
    if(p->arr){
        // Acessar lista por lista
        for(int c=0; c < p->tamArr; c++){
            // Acessar elemento por elemento
            if(p->arr[c] != NULL){
                walker = p->arr[c];
                while(walker != NULL){
                    walker = walker->link;
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    struct nodo n03 = {3, NULL},
                n02 = {2, &n03},
                n01 = {1, &n02};

    struct nodo n13 = {6, NULL},
                n12 = {5, &n13},
                n11 = {4, &n12};

    struct nodo n23 = {9, NULL},
                n22 = {8, &n23},
                n21 = {7, &n22};

    struct nodo **nodos = malloc(3*sizeof(struct nodo*));
    nodos[0] = &n01;
    nodos[1] = &n11;
    nodos[2] = &n21;
    struct descritor desc = {3, nodos}, *p = &desc;

    printf("\nContagem de nodos do descritor: %d\n", contaNodo(p));

    return 0;
}