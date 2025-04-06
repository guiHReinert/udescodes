#include <stdio.h>
#include <stdlib.h>

// 3
typedef struct nodados{
    int tamInfo;
    struct nodados *pt;
} NoDados;

int main(){
    // 3A
    {
        NoDados *p, *q, a31, a32;
        p = &a31;
        q = &a32;
        p->pt = NULL;
        q->pt = NULL;
    }
    // 3B
    {
        NoDados *p, *q, b31, b32;
        p = &b31;
        q = &b32;
        p->pt = &b32;
        q->pt = NULL;
    }
    // 3C
    {
        NoDados *p, *q, c31, c32;
        p = &c31;
        q = &c32;
        p->pt = &c32;
        q->pt = q;
    }
    return 0;
}