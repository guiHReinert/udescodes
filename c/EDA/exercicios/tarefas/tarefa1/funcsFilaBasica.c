#include "arq.h"

// Criar novo descritor sem referencial movel
descS *criaDescF(int tamInfo){   	
    descS *desc = (descS*) malloc(sizeof(descS));
    
    if(!desc) {
        printf("Erro ao alocar memoria para o descritor\n");
        return NULL;
    }

    desc->cauda = NULL;
    desc->frente = NULL;
    desc->tamInfo = tamInfo;
    desc->numRep = 0;

    return desc;
}

// Remover descritor da memoria
descS *destroiDescF(descS *desc){
    reiniciaS(desc);
    free(desc);
    return NULL; // Aterra o ponteiro externo, declarado na aplicacao
}

/*
    Insere nodos na fila a partir da cauda, com base nas suas prioridades:
    - <novo>      dados do novo nodo (chamado de <newNodo>);
    - <desc>      ponteiro para o descritor da fila;
    - <compara>   eh a funcao de comparacao utilizada no contexto. Portanto, variavel;
    - <count>     incrementa sempre que while_1() for executado. (unica iteracao
                  da funcao)

    As filas aqui consideradas nao possuem "buracos", ou seja, espacos vazios
    entre nodos. Bem como descS->cauda->anterior == NULL e
    descS->frente->posterior == NULL.
*/
int inserirSem(info *novo, descS *desc, int (*compara)(info *novo, info *old)){
    
    // Definicao dos nodos uteis ah funcao.
    nodo *newNodo=NULL, *walker=NULL;
      
    // Alocar dinamicamente o novo nodo vazio, e verificar se a alocacao funcionou.
    newNodo = (nodo*) malloc(sizeof(nodo));
    if (!newNodo){
        printf("Erro ao alocar memoria para o novo nodo\n");
        return FRACASSO;
    } 

    // Copiar as novas informacoes de <novo> para <newNodo->dados>.
    memcpy(&(newNodo->dados), novo, desc->tamInfo);
    newNodo->anterior = NULL;
    newNodo->posterior = NULL;
    
    /*
        Fila vazia:
        - Ponteiros de <newNodo> vazios, frente e cauda apontam para <newNodo>.
    */
   if(desc->frente == NULL && desc->cauda == NULL){
       desc->frente = newNodo;
       desc->cauda = newNodo;
    }
    
    // Fila com pelo menos 1 nodo
    else{

        // Comparacao entre os dados de <newNodo> com os da cauda e da frente.
        int compCauda = compara(novo, &(desc->cauda->dados)),
            compFrente = compara(novo, &(desc->frente->dados));
        
        /*
            <newNodo> possui priidade menor ou igual que a da cauda.
            - <newNodo->anterior>   aponta para NULL;
            - <newNodo->posterior>  aponta para a cauda;
            - <desc->cauda>         aponta para <newNodo>;
        */
       if(compCauda == MENOR || compCauda == IGUAL){
           newNodo->posterior = desc->cauda;
           desc->cauda->anterior = newNodo;
           desc->cauda = newNodo;
            // printf("Inserido na cauda\n");
        }

        /*
            <newNodo> eh de maior prioridade que a frente.
            - <newNodo->anterior>   aponta para a frente;
            - <newNodo->posterior>  aponta para NULL;
            - <desc->frente>        aponta para <newNodo>;
        */
        else if(compFrente == MAIOR){
            newNodo->anterior = desc->frente;
            desc->frente->posterior = newNodo;
            desc->frente = newNodo;
            // printf("Inserido na frente\n");
        }
        
        // <newNodo> possui prioridade maior que a da cauda e menor que a da frente
        else{
            
            /*
                while_1: <walker> irah percorrer a fila pela cauda ate que
                a sua prioridade seja imediatamente maior que a de <newNodo>.
            */
            walker = desc->cauda; 
            while(walker->posterior != NULL && (*compara)(novo, &(walker->dados)) == MAIOR){
                walker = walker->posterior;
                desc->numRep++;
            }

            /*
                Sempre valerah quando:
                - <newNodo->anterior>   apontar para a cauda;
                - <newNodo->posterior>  apontar para a frente;
                - <newNodo>             estiver em qualquer outra posicao entre
                                        os dois.
            */
            newNodo->posterior = walker;
            newNodo->anterior = walker->anterior;
            walker->anterior->posterior = newNodo;
            walker->anterior = newNodo;
            // printf("Inserido no intermediario\n");
        }	
    }
    return SUCESSO;
}


// Reiniciar fila
int reiniciaS(descS *desc){
	int ret=FRACASSO;
    nodo *aux=NULL;
    if(desc->frente != NULL && desc->cauda != NULL){  
        aux = desc->cauda->posterior;
        while(aux != NULL) {
            free(desc->cauda);
            desc->cauda = aux;
            aux = aux->posterior;
        }
        free(desc->cauda);
        desc->frente = NULL;
        desc->cauda = NULL;
        ret=SUCESSO; 
    }
    return ret;	
}