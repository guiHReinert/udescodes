#include "../include/arvores.h"

/*
    Criacao
*/


/*
    Balanceamento
*/

void rot_esquerda_rubro_negra(rn_arvore_t* arvore, rn_nodo_t* nodo) {
    rn_nodo_t* direita = nodo->direita;
    nodo->direita = direita->esquerda;
    if (direita->esquerda != arvore->nulo)
        direita->esquerda->pai = nodo; //Se houver filho à esquerda em direita, ele será pai do nó

    direita->pai = nodo->pai; //Ajusta nodo pai do nó à direita

    if (nodo->pai == arvore->nulo)
        arvore->raiz = direita; //Se nó for raiz, o nó direita será a nodova raiz da árvore
    else if (nodo == nodo->pai->esquerda)
        nodo->pai->esquerda = direita; //Cor_trige relação pai-filho do nodovo pai (esquerda)
    else
        nodo->pai->direita = direita; //Cor_trige relação pai-filho do nodovo pai (direita)

    direita->esquerda = nodo; //Cor_trige relação pai-filho entre o nó pivô e o nó à direita
    nodo->pai = direita;
}

void rot_direita_rubro_negra(rn_arvore_t* arvore, rn_nodo_t* nodo) {
    rn_nodo_t* esquerda = nodo->esquerda;
    nodo->esquerda = esquerda->direita;
    if (esquerda->direita != arvore->nulo)
        esquerda->direita->pai = nodo; //Se houver filho à direita em esquerda, ele será pai do nó
    
        esquerda->pai = nodo->pai; //Ajusta nodo pai do nó à esquerda
    if (nodo->pai == arvore->nulo)
        arvore->raiz = esquerda; //Se nó for raiz, o nó esquerda será a nodova raiz da árvore
    else if (nodo == nodo->pai->esquerda)
        nodo->pai->esquerda = esquerda; //Cor_trige relação pai-filho do nodovo pai (esquerda)
    else
        nodo->pai->direita = esquerda; //Cor_trige relação pai-filho do nodovo pai (direita)
    
        esquerda->direita = nodo; //Cor_trige relação pai-filho entre o nó pivô e o nó à esquerda
    nodo->pai = esquerda;
}

void balancear_rubro_negra(rn_arvore_t* arvore, rn_nodo_t* nodo) {
    while (nodo->pai->cor == Vermelho) { //Garante que todos os níveis foram balanceados
        if (nodo->pai == nodo->pai->pai->esquerda) {
            rn_nodo_t *tio = nodo->pai->pai->direita;

            if (tio->cor == Vermelho) {
            tio->cor = Preto; //Resolve caso 2
            nodo->pai->cor = Preto;
            nodo->pai->pai->cor = Vermelho;
            nodo = nodo->pai->pai; //Vai para o nível anterior
            } else {
                if (nodo == nodo->pai->direita) {
                nodo = nodo->pai; //Vai para o nível anterior
                rot_esquerda_rubro_negra(arvore, nodo); //Resolve caso 3
                } else {
                nodo->pai->cor = Preto; //Resolve caso 4
                nodo->pai->pai->cor = Vermelho;
                rot_direita_rubro_negra(arvore, nodo->pai->pai);
                }
            }
        } else {
            //Repete o mesmo código do bloco if, invertendo o lado dos direita e esquerda
        }
    }
    arvore->raiz->cor = Preto; //Resolve caso 1
}
