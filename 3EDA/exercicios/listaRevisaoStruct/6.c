#include <stdio.h>
#include <stdlib.h>

// 6
struct nodo{
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p){
    struct nodo *actual;
    int count=0;
    if(p){
        count = 1;
        actual = p->link; 
        while(actual != NULL && actual != p){
            count++;
            actual = actual->link;
            if(actual != NULL && actual == actual->link){
                count++;
                break;
            }
        }
    }
    return count;
}

struct nodoD{
    int x;
    struct nodoD *esq;
    struct nodoD *dir;
};

struct descritor{
    unsigned int posicao;
    struct nodoD *primeiro, *ultimo, *link;
};

int contaNodoDesc(struct descritor *p){
    int count = 0;
    p->posicao = count;
    if(p->primeiro){
        count = 1;
        p->posicao = count;
        p->link = p->primeiro;
        // while quebra ao apontar para NULL, para o primeiro nodo ou para si mesmo
        while(p->link != NULL &&
            p->link->dir != NULL &&
            p->link->dir != p->primeiro &&
            p->link->dir != p->link){
            count++;
            p->posicao = count;
            p->link = p->link->dir;
        }
    }
    return count;
}

int main(){
    // 6A
    {
        { // 6A.1
            struct nodo *p = NULL;
            printf("\n6A.1) Contagem de nodos: %d", contaNodo(p));
        }
        { // 6A.2
            struct nodo *p = (struct nodo*)malloc(sizeof(struct nodo));
            p->link = NULL;
            printf("\n6A.2) Contagem de nodos: %d", contaNodo(p));
            free(p);
        }
        { // 6A.3 (assumindo n = 7)
            struct nodo *p = (struct nodo*)malloc(sizeof(struct nodo)),
            *p2 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p3 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p4 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p5 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p6 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p7 = (struct nodo*)malloc(sizeof(struct nodo));
            p->link = p2;
            p2->link = p3;
            p3->link = p4;
            p4->link = p5;
            p5->link = p6;
            p6->link = p7;
            p7->link = NULL;
            printf("\n6A.3) Contagem de nodos: %d", contaNodo(p));
            free(p); free(p2); free(p3); free(p4); free(p5); free(p6); free(p7);
        }
    }
    // 6B
    {
        { // 6B.1
            struct nodo *p = NULL;
            printf("\n6B.1) Contagem de nodos: %d", contaNodo(p));
        }
        { // 6B.2
            struct nodo *p = (struct nodo*)malloc(sizeof(struct nodo));
            p->link = p;
            printf("\n6B.2) Contagem de nodos: %d", contaNodo(p));
            free(p);
        }
        { // 6B.3 (assumindo n = 7)
            struct nodo *p = (struct nodo*)malloc(sizeof(struct nodo)),
            *p2 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p3 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p4 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p5 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p6 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p7 = (struct nodo*)malloc(sizeof(struct nodo));
            p->link = p2;
            p2->link = p3;
            p3->link = p4;
            p4->link = p5;
            p5->link = p6;
            p6->link = p7;
            p7->link = p;
            printf("\n6B.3) Contagem de nodos: %d", contaNodo(p));
            free(p); free(p2); free(p3); free(p4); free(p5); free(p6); free(p7);
        }
    }
    // 6C
    {
        { // 6C.1
            struct nodo *p = NULL;
            printf("\n6C.1) Contagem de nodos: %d", contaNodo(p));
        }
        { // 6C.2
            struct nodo *p = (struct nodo*)malloc(sizeof(struct nodo));
            p->link = p;
            printf("\n6C.2) Contagem de nodos: %d", contaNodo(p));
            free(p);
        }
        { // 6C.3 (assumindo n = 7)
            struct nodo *p = (struct nodo*)malloc(sizeof(struct nodo)),
            *p2 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p3 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p4 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p5 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p6 = (struct nodo*)malloc(sizeof(struct nodo)),
            *p7 = (struct nodo*)malloc(sizeof(struct nodo));
            p->link = p2;
            p2->link = p3;
            p3->link = p4;
            p4->link = p5;
            p5->link = p6;
            p6->link = p7;
            p7->link = p7;
            printf("\n6C.3) Contagem de nodos: %d", contaNodo(p));
            free(p); free(p2); free(p3); free(p4); free(p5); free(p6); free(p7);
        }
    }
    // 6D
    {
        { // 6D.1
            struct descritor *p = (struct descritor*)malloc(sizeof(struct descritor));
            p->posicao = 0;
            p->primeiro = NULL;
            p->link = NULL;
            p->ultimo = NULL;
            printf("\n6D.1) Contagem de nodos com descritor: %d", contaNodoDesc(p));
            free(p);
        }
        { // 6D.2
            struct nodoD *p1 = (struct nodoD*)malloc(sizeof(struct nodoD));
            p1->esq = NULL;
            p1->dir = NULL;

            struct descritor *p = (struct descritor*)malloc(sizeof(struct descritor));
            p->primeiro = p1;
            p->link = p1;
            p->ultimo = p1;
            printf("\n6D.2) Contagem de nodos com descritor: %d", contaNodoDesc(p));
            free(p); free(p1);
        }
        { // 6D.3 (assumindo k = 7)
            struct nodoD *p1 = (struct nodoD*)malloc(sizeof(struct nodoD)),
            *p2 = (struct nodoD*)malloc(sizeof(struct nodoD)),
            *p3 = (struct nodoD*)malloc(sizeof(struct nodoD)),
            *p4 = (struct nodoD*)malloc(sizeof(struct nodoD)),
            *p5 = (struct nodoD*)malloc(sizeof(struct nodoD)),
            *p6 = (struct nodoD*)malloc(sizeof(struct nodoD)),
            *p7 = (struct nodoD*)malloc(sizeof(struct nodoD));
            p1->esq = NULL;
            p1->dir = p2;
            p2->esq = p1;
            p2->dir = p3;
            p3->esq = p2;
            p3->dir = p4;
            p4->esq = p3;
            p4->dir = p5;
            p5->esq = p4;
            p5->dir = p6;
            p6->esq = p5;
            p6->dir = p7;
            p7->esq = p6;
            p7->dir = NULL;

            struct descritor *p = (struct descritor*)malloc(sizeof(struct descritor));
            p->primeiro = p1;
            p->link = NULL;
            p->ultimo = p7;
            printf("\n6D.3) Contagem de nodos com descritor: %d", contaNodoDesc(p));
            free(p); free(p1); free(p2); free(p3); free(p4); free(p5); free(p6); free(p7);
        }
    }
    printf("\n");
    return 0;
}
