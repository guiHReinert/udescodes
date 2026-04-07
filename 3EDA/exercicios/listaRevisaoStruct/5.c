#include <stdio.h>
#include <stdlib.h>

int main(){
    struct teste{
        struct teste *esq;
        struct teste *dir;
    }*p;
    // 1
    // p.esq->dir->esq = p->esq;
    // p.esq->dir->dir = p;
    // p->esq = p->esq->dir;

    return 0;
}