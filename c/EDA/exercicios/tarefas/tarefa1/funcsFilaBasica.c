#include "arq.h"

// Criar novo descritor sem referencia movel
descF *criaDescF(int tamInfo){   	
    descF *desc = (descF*) malloc(sizeof(descF));
    if(desc != NULL) {
        desc->cauda = NULL;
        desc->frente = NULL;
	    desc->tamInfo = tamInfo;
    }
    return desc;
}

// Remover descritor da memoria
descF *destroiDescF(descF *desc){
    reinicia(desc);
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
    entre nodos. Bem como descF->cauda->anterior == NULL e
    descF->frente->posterior == NULL.
*/
int inserirSem(info *novo, descF *desc, int (*compara)(info *novo, info *walker), int *count){
    // Resultado da comparacao
	int result;
  	nodo *newNodo=NULL, *walker=NULL;
      
      // Alocar dinamicamente o novo nodo vazio, e verificar se a alocacao foi funcionou
      if ((newNodo = (nodo*) malloc(sizeof(nodo))) != NULL){ 
          // Copiar as novas informacoes de <novo> para <newNodo->dados>
          memcpy(&(newNodo->dados), novo, desc->tamInfo);
          newNodo->anterior = NULL;
          newNodo->posterior = NULL;

        /*
		    Fila vazia:
            - Ponteiros de <newNodo> vazios, frente e cauda apontam para <newNodo>.
        */
		if(desc->frente == NULL && desc->cauda == NULL){
			newNodo->anterior = NULL;
            newNodo->posterior = NULL;
    	    desc->frente = newNodo;
            desc->cauda = newNodo;
		}

        // Fila com pelo menos 1 nodo
		else{
            // Comparacao entre dados de <newNodo> e da cauda
			result = (*compara)(novo, &(desc->cauda->dados));

            /*
			    <newNodo> eh de menor prioridade que a cauda.
                - <newNodo->anterior>   <newNodo> aponta para NULL;
                - <newNodo->posterior>  aponta para a cauda;
                - <cauda>               aponta para <newNodo>;
                - <cauda->anterior>     aponta para <newNodo>.
            */
			if(result == MENOR){
                newNodo->posterior = desc->cauda;
				desc->cauda->anterior = newNodo;
				desc->cauda = newNodo;
            }
            
            // <newNodo> possui prioridade maior ou igual ah da cauda
            else{
                
                /*
                    while_1: <walker> irah percorrer a fila pela frente ate que
                    a sua prioridade seja imediatamente maior que a de <newNodo>.
                */
                walker = desc->frente; 
                while(walker->anterior != NULL && (*compara)(novo, &(walker->dados)) != MAIOR ){
                    walker = walker->anterior;
                    (*count)++;
                }
                // Comparacao entre os dados de <newNodo> e de <walker>
				result = (*compara)(novo, &(walker->dados));

                /*
                    <newNodo> se insere imediatamente atras de <walker>.
                    Sempre valerah quando:
                    - <newNodo->anterior> apontar para a cauda;
                    - <newNodo->posterior> apontar para a frente;
                    - <newNodo> estiver em qualquer outra posicao entre os dois.
                */
                if(result == MENOR || result == IGUAL){
                    newNodo->posterior = walker;
                    walker->anterior->posterior = newNodo;
                    newNodo->anterior = walker->anterior;
                    walker->anterior = newNodo;
                }

                /*
                    <newNodo> eh de maior prioridade que a frente.
                    - <newNodo->posterior>  aponta para NULL;
                    - <newNodo->anterior>   aponta para a frente;
                    - <frente>              aponta para <newNodo>;
                    - <frente->anterior>    aponta para <newNodo>.
                */
       	   		else{   	
					newNodo->anterior = desc->frente;
                    desc->frente->posterior = newNodo;
                    desc->frente = newNodo;     						
				}	
			}	
		}
		return SUCESSO;
    }
	return FRACASSO;
}

// Remover nodos na fila (iteracao comecando pela cauda)
int remove_(info *reg, descF  *desc){
	int ans = FRACASSO;
	nodo *aux = desc->cauda;
    // Fila nao vazia
    if(desc->cauda != NULL && desc->frente != NULL){
       	memcpy(reg, &(desc->frente->dados), desc->tamInfo);
		if(aux == desc->frente) { // Caso tenha 1 elemento apenas
			free(desc->frente);
			desc->frente = desc->cauda = NULL;
		}
		else {
			desc->frente= desc->frente->anterior;
            free(desc->frente->posterior); 
            desc->frente->posterior = NULL;
		}
		ans = SUCESSO;
	}
	return ans;
}
// Reiniciar fila
int reinicia(descF *desc){
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

// Buscar frente da fila
int buscaNaFrente(info *reg, descF *desc){  
    int ret = FRACASSO;
    if(desc->frente != NULL && desc->cauda != NULL) { 	
        memcpy(reg, &(desc->frente->dados), desc->tamInfo);
        ret = SUCESSO;
    }
    return ret;
}
// Buscar cauda da fila
int buscaNaCauda(info *reg, descF *desc){
    int ret = FRACASSO;
    if(desc->cauda != NULL && desc->frente != NULL) {
        memcpy(reg, &(desc->cauda->dados), desc->tamInfo);
	    ret = SUCESSO;
    }
    return ret;
}

// Verificar se estah vazia
int testaVazia(descF *desc){
    if(desc->frente == NULL && desc->cauda == NULL) {
        return SIM;
    }
    return NAO;
}

