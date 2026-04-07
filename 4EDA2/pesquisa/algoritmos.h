#include <stdio.h>
#include <stdlib.h>

void populaVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 999;
    }
}

// Buscas pela Memoria Interna

int pesquisaSequencial(int chave, int v[], int n) {
    int contador = 1;
    for (int i = 0; i < n; i++) {
        contador++;
        if (v[i] == chave) {
            return contador;
        }
        contador++;
    }
    return contador;
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
    int i = 0;
    v[n] = chave; //A última posicao do vetor possui o sentinela
    while (v[i] != chave) {
        i++;
    }
    if (i < n) return i;
    return -1; // Indice invalido
}

// Semelhante com a pesquisa binaria, mas com um calculo diferente do meio
int pesquisaInterpolacao(int chave, int v[], int n) {
    int ini = 0, meio, fim = n - 1;
    while (ini <= fim && chave >= v[ini] && chave <= v[fim]) {
        // Protecao de uma divisao por 0
        if (ini == fim) return v[ini] == chave ? ini : -1; 
            meio = ini + (((double) (fim - ini) / (v[fim] - v[ini])) * (chave - v[ini]));
        if (chave == v[meio]) {
            return meio;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return -1; // Indice impossivel
}

// pesquisa direta (hashing)

// Buscas pela Memoria Externa

int pesquisaBinaria(int chave, int v[], int n) {
    int inicio = 0, meio, fim = n - 1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave == v[meio]) {
            return meio;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
        inicio = meio + 1;
        }
    }
    return -1; // Indice invalido
}

int pesquisaBinariaRecursiva(int chave, int v[], int ini, int fim) {
    int meio = (ini + fim) / 2;
    if (ini > fim)
        return -1;
    if (chave == v[meio])
        return meio;
    else if (chave < v[meio])
        return pesquisaBinariaRecursiva(chave, v, ini, meio - 1);
    else
        return pesquisaBinariaRecursiva(chave, v, meio + 1, fim);
}

// arvore B, B+, B*


// arvore trie e patricia
