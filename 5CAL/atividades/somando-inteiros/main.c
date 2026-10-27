#include <stdio.h>
#include <stdlib.h>

long pot (long a, long b) {
    int c = a;
    for (int i=1; i < b; i++) {
        c *= a;
    }
    return c;
}

int num_bits(long num) {
    int count = 0;
    float base = 1;
    while (num/base) {
        printf("\tnum: %ld\n\tbase: %f\n\tresult: %f\n\tcount: %d\n\n",
            num, base, num/base, count);
        count++;
        base *= 10;
    }
    return count;
}

// long karatsuba(long a, long b) { // Abordagem por binario (blocos)
//     int toka1 = 
//     return 0;
// }

void main(int argc, char* argv[]) {
    long teste1 = 9223372036854775807, teste2 = 1;

    // printf("\tTeste do enunciado: %ld \n", karatsuba(teste1, teste2, 10));
    printf("\tbits: %d\n", num_bits(teste1));
}
