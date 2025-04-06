#include <stdio.h>
#include <stdlib.h>

// 3
typedef struct nodados{
    int tamInfo;
    struct nodados *pt;
} NoDados;

int main(){
    // 3A para 3B
    {
        NoDados *p, *q;
        p->pt = NULL;
        q->pt = NULL;

        p->pt = q;
    }
    // 3A para 3C
    {
        NoDados *p, *q;
        p->pt = NULL;
        q->pt = NULL;

        p->pt = q;
        q->pt = q;
    }
    return 0;
}