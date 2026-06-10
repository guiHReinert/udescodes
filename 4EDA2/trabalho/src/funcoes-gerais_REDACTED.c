/*
    Gerais
*/
Nodo_t* localizar(Nodo_t* nodo, int valor) {
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

void percorrer(Nodo_t* nodo, void (*callback)(int)) {
    if (nodo != NULL) {
        percorrer(nodo->esquerda, callback);
        callback(nodo->valor);
        percorrer(nodo->direita, callback);
    }
}




