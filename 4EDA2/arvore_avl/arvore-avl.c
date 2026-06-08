#include <stdlib.h>
#include <stdio.h>

/*
    Definicoes
*/

typedef struct nodo {
    struct nodo* pai;
    struct nodo* esquerda;
    struct nodo* direita;
    int valor;
    int altura;
} Nodo;

typedef struct arvore {
    struct nodo* raiz;
} Arvore;

void balanceamento(Arvore*, Nodo*);
int altura(Nodo*);
int fb(Nodo*);
Nodo* rsd(Arvore*, Nodo*);
Nodo* rse(Arvore*, Nodo*);
Nodo* rdd(Arvore*, Nodo*);
Nodo* rde(Arvore*, Nodo*);
Nodo* criarNodo(Nodo*, int);

/*
    Funcoes Gerais
*/

Arvore* criar() {
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
  
    return arvore;
}

int vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

Nodo* adicionarNodo(Nodo* nodo, int valor) {
    if (valor > nodo->valor) {
        if (nodo->direita == NULL) {
            Nodo* nodovo = criarNodo(nodo, valor);
            nodo->direita = nodovo;
				
            return nodovo;
        } else {
            return adicionarNodo(nodo->direita, valor);
        }
    } else {
        if (nodo->esquerda == NULL) {
            Nodo* nodovo = criarNodo(nodo, valor);
            nodo->esquerda = nodovo;
			
            return nodovo;
        } else {
            return adicionarNodo(nodo->esquerda, valor);
        }
    }
}

Nodo* criarNodo(Nodo* pai, int valor) {
    printf("Adicionando %d\n",valor);

    Nodo* nodo = malloc(sizeof(Nodo));
    nodo->valor = valor;
    nodo->pai = pai;
    nodo->esquerda = NULL;
    nodo->direita = NULL;

    return nodo;
}

Nodo* adicionar(Arvore* arvore, int valor) {
    if (vazia(arvore)) {
        Nodo* nodovo = criarNodo(NULL, valor);
        arvore->raiz = nodovo;
			
        return nodovo;
    } else {
        Nodo* nodo = adicionarNodo(arvore->raiz, valor);
        balanceamento(arvore, nodo);
        
        return nodo;
    }
}

Nodo* localizar(Nodo* nodo, int valor) {
    if (nodo->valor == valor) {
        return nodo;
    } else {
        if (valor < nodo->valor) {
            if (nodo->esquerda != NULL) {
                return localizar(nodo->esquerda, valor);
            }
        } else {
            if (nodo->direita != NULL) {
                return localizar(nodo->direita, valor);
            }
        }
    }

    return NULL;
}

void percorrer(Nodo* nodo, void (*callback)(int)) {
    if (nodo != NULL) {
        percorrer(nodo->esquerda,callback);
        callback(nodo->valor);
        percorrer(nodo->direita,callback);
    }
}

void visitar(int valor){
    printf("%d ", valor);
}

int altura(Nodo* nodo){
    int esquerda = 0,direita = 0;

    if (nodo->esquerda != NULL) {
        esquerda = altura(nodo->esquerda) + 1;
    }

    if (nodo->direita != NULL) {
        direita = altura(nodo->direita) + 1;
    }
  
    //max(esquerda,direita)
    return esquerda > direita ? esquerda : direita;
}

int fb(Nodo* nodo) {
    int esquerda = 0,direita = 0;
  
    if (nodo->esquerda != NULL) {
        esquerda = altura(nodo->esquerda) + 1;
    }

    if (nodo->direita != NULL) {
        direita = altura(nodo->direita) + 1;
    }
  
    return esquerda - direita;
}

/*
    Balanceamento
*/

void balanceamento(Arvore* arvore, Nodo* nodo) {
    while (nodo != NULL) {
        int fator = fb(nodo);

        if (fator > 1) { //árvore mais profunda a esquerda
            //rotação para a direita
            if (fb(nodo->esquerda) > 0) {
                printf("RSD(%d)\n",nodo->valor);
                //rotação simples a direita, FB do filho tem sinal igual
                rsd(arvore, nodo); 
            } else {
                printf("RDD(%d)\n",nodo->valor);
                //rotação dupla a direita, FB do filho tem sinal diferente
                rdd(arvore, nodo); 
            }
        } else if (fator < -1) { //árvore mais profunda a direita
            //rotação para a esquerda
            if (fb(nodo->direita) < 0) {
                printf("RSE(%d)\n",nodo->valor);
                //rotação simples a esquerda, FB do filho tem sinal igual
                rse(arvore, nodo); 
            } else {
                printf("RDE(%d)\n",nodo->valor);
                //rotação dupla a esquerda, FB do filho tem sinal diferente
                rde(arvore, nodo);
            }
        }

        nodo = nodo->pai; 
    }
}

Nodo* rse(Arvore* arvore, Nodo* nodo) {
    Nodo* pai = nodo->pai;
    Nodo* direita = nodo->direita;

    if (direita->esquerda != NULL) {
        direita->esquerda->pai = nodo;
    } 
  
    nodo->direita = direita->esquerda;
    nodo->pai = direita;

    direita->esquerda = nodo;
    direita->pai = pai;

    if (pai == NULL) {
        arvore->raiz = direita;
    } else {
        if (pai->esquerda == nodo) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

Nodo* rsd(Arvore* arvore, Nodo* nodo) {
    Nodo* pai = nodo->pai;
    Nodo* esquerda = nodo->esquerda;

    if (esquerda->direita != NULL) {
        esquerda->direita->pai = nodo;
    } 
  
    nodo->esquerda = esquerda->direita;
    nodo->pai = esquerda;
  
    esquerda->direita = nodo;
    esquerda->pai = pai;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    } else {
        if (pai->esquerda == nodo) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

Nodo* rde(Arvore* arvore, Nodo* nodo) {
    nodo->direita = rsd(arvore, nodo->direita);
    return rse(arvore, nodo);
}

Nodo* rdd(Arvore* arvore, Nodo* nodo) {
    nodo->esquerda = rse(arvore, nodo->esquerda);
    return rsd(arvore, nodo);
}

int main() {
    Arvore* a = criar();

    adicionar(a, 3);
    adicionar(a, 1);
    adicionar(a, 2);
    adicionar(a, 6);
    adicionar(a, 5);
    adicionar(a, 7);
    adicionar(a, 4);

    printf("In-order: ");
    percorrer(a->raiz,visitar);
    printf("\n");

    printf("Altura: %d\n", altura(a->raiz) + 1);
}