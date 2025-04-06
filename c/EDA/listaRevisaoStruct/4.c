#include <stdio.h>
#include <stdlib.h>

//4
int main(){
    // 4.1
    {
        struct xxx{
            int w;
            struct xxx *b;
        }*pt3, *pt2, *pt1;
        
        // A1
        pt1->b = pt3;
        pt2->b = NULL;
        pt3->b = NULL;
        // Resposta
        pt1->b = pt2;
        pt2->b = pt3;
    }
    // 4.2
    {
        struct yyy{
            int k;
            struct yyy *a;
            struct yyy *b;
        }*pt1, *pt2;
        struct yyy pentag;
        // B1
        pt1->a = NULL;
        pt1->b = NULL;
        pt2->a = &pentag;
        pt2->a->b = pt2;
        // Resposta
        pt1->b = pt2;
        pt1->a = pt2->a;
        pt1->a->b = pt1;
        pt2->a = pt1;

    }
    return 0;
}