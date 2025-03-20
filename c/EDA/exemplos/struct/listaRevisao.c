#include <stdio.h>
#include <stdlib.h>

// 4
/*
void main(){
    struct yyy{
        struct yyy *a;
        struct yyy *b;
    }*pt1, *pt2;
}
*/

// 6

struct descritor{
    unsigned int posicao;
    struct nodo *primeiro, *ultimo, *link;
};


