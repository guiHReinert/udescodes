#include "arq.h"

/*
    Cria o descritor da multipilha.
*/
descMP *criarDescMP(int L){

    // Declaracao valida para a criacao da MP.
    if (L > 0){

        // Aloca a memoria para a MP e verifica se foi bem sucedido.
        descMP *desc = (descMP *) malloc(sizeof(descMP));
        if(!desc){
            return FRACASSO;
        }
            
        // Iniciando o descritor da MP
        desc->topo1 = -1;
        desc->topo2 = L;
        desc->tamVet = L;
        
        // Alocacao de memoria para a MP (vet de unions), constituida de L nos.
        desc->vet = (nodo *) malloc(L * sizeof(nodo));
        if(!desc->vet) {
            free(desc);
            return FRACASSO;
        }

        return desc;
    }
}

// Destroi a MPE, liberando todos os seus dados alocados dinamicamente.
descMP* destruirDescMP(descMP *desc) { 
    if(!desc){
        return NULL;
    }

    for(int i=0; i <= desc->topo1; i++){
        if (desc->vet[i].dados) {
            free(desc->vet[i].dados->nome);
            free(desc->vet[i].dados);
        }
    }

	free(desc->vet);
    free(desc);
	return NULL;
}

int reiniciarPilha(descMP *desc, char pilha) {
    if (pilha == PILHA_DIRETA) {
        if (desc->topo1 == -1) return VAZIA;

        for (int i = 0; i <= desc->topo1; i++) {

            if (desc->vet[i].dados) {
                free(desc->vet[i].dados->nome);
                free(desc->vet[i].dados);
            }
        }
        desc->topo1 = -1;
        return SUCESSO;
    }

    else if (pilha == PILHA_INVERSA) {
        if (desc->topo2 == desc->tamVet) return VAZIA;

        for (int i = desc->tamVet - 1; i > desc->topo2; i--) {

            if (desc->vet[i].dados != NULL) {
                free(desc->vet[i].dados->nome);
                free(desc->vet[i].dados);
            }
        }
        desc->topo2 = desc->tamVet;
        return SUCESSO;
    }

    return FRACASSO;
}


/*
    Insere o novo nodo com os dados <novo> em seu respectivo topo em uma das
    pilhas da MP. A pilha em questão eh selecionada por <pilha>, que pode variar
    entre as constantes:
        - PILHA_DIRETA      com <newNodo> inserido em topo1;
        - PILHA_INVERSA     com <newNodo> inserido em topo2.
*/
int empilhar(descMP *desc, info *novo, char pilha){

    // Caso o vetor nao existir.
    if(!desc->vet) {
        return FRACASSO;
    }
    
    // Caso a MPE estiver cheia.
    if(desc->topo1 + 1 >= desc->topo2) {
        return FRACASSO;
    }

    /*
        Se a MPE existe e nao estah cheia, insercao pode ocorrer normalmente em
        uma das duas pilhas.
    */
    if(pilha == PILHA_DIRETA){
        desc->topo1++;
        desc->vet[desc->topo1].dados = novo;

        return SUCESSO;
    }
    else if(pilha == PILHA_INVERSA){
        desc->topo2--;
        desc->vet[desc->topo2].dados = novo;

        return SUCESSO;
    }
    else{
        return FRACASSO;
    }
}

int desempilhar(descMP *desc, char pilha){

    // Caso o vetor nao existir.
    if(!desc->vet) {
        return FRACASSO;
    }

    if(pilha == PILHA_DIRETA && desc->topo1 != -1){
        desc->vet[desc->topo1].dados = NULL;
        desc->topo1--;

        return SUCESSO;
    }
    else if(pilha == PILHA_INVERSA && desc->topo2 != desc->tamVet){
        desc->vet[desc->topo2].dados = NULL;
        desc->topo2++;

        return SUCESSO;
    }
    else{
        return FRACASSO;
    }
}
