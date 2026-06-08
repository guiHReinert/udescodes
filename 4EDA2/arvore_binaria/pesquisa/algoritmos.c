#include <algoritmos.h>

int main() {
    int n = 1000000;
    int v[n];
    
    populaVetor(v, n);
    
    printf("Pesquisa sequencial\n");
    printf("Melhor caso: %d\n", pesquisaSequencial(v[0], v, n));
    printf("Pior caso: %d\n", pesquisaSequencial(n, v, n));
    printf("Caso medio: %d\n", pesquisaSequencial(v[rand() % n], v, n));
}