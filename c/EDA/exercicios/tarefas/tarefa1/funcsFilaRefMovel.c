#include "arq.h"

// Criar novo descritor com referencial movel
descM *criaDescM(int tamInfo){   	
    descM *desc = (descM*) malloc(sizeof(descM));
    
    if(!desc) {
        printf("Erro ao alocar memoria para o descritor\n");
        return NULL;
    }

    desc->cauda = NULL;
    desc->frente = NULL;
    desc->ref = NULL;
    desc->tamInfo = tamInfo;
    desc->tamFila = 0;
    desc->numRep = 0;

    return desc;
}

// Remover descritor da memoria
descM *destroiDescM(descM *desc){
    reinicia(desc);
    free(desc);
    return NULL; // Aterra o ponteiro externo, declarado na aplicacao
}

int inserirCom(info *novo, descM *desc, int (*compara)(info *novo, info *walker), int *count){
    
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
        Fila vazia: Ponteiros de <newNodo> vazios, frente e cauda apontam para
        <newNodo>, ref aponta para <newNodo> e <def->tamFila> incrementa.
    */
    if(desc->frente == NULL && desc->cauda == NULL){
        desc->frente = newNodo;
        desc->cauda = newNodo;
        desc->ref = newNodo;
        desc->tamFila++;
    }

    // Fila com pelo menos 1 nodo.
    else{
   
        /*
            <newNodo> eh de menor prioridade que a cauda.
            - <newNodo->anterior>   aponta para NULL;
            - <newNodo->posterior>  aponta para a cauda;
            - <desc->cauda>         aponta para <newNodo>;
            - <desc->ref>           aponta para <newNodo>;
            - <desc->tamFila>       incrementa.
        */
        if(compara(novo, &(desc->cauda->dados)) == MENOR || compara(novo, &(desc->cauda->dados)) == IGUAL){
            newNodo->posterior = desc->cauda;
            desc->cauda->anterior = newNodo;
            desc->cauda = newNodo;
            desc->ref = newNodo;
            desc->tamFila++;
            printf("Inserido na cauda\n");
        }
        
        // Caso nodo na frente
        
        // Caso intermediario
        
    }
    return SUCESSO;
}

// Remover nodos na fila (iteracao comecando pela cauda)
int remove_(info *reg, descM  *desc){
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
int reinicia(descM *desc){
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
int buscaNaFrente(info *reg, descM *desc){  
    int ret = FRACASSO;
    if(desc->frente != NULL && desc->cauda != NULL) { 	
        memcpy(reg, &(desc->frente->dados), desc->tamInfo);
        ret = SUCESSO;
    }
    return ret;
}
// Buscar cauda da fila
int buscaNaCauda(info *reg, descM *desc){
    int ret = FRACASSO;
    if(desc->cauda != NULL && desc->frente != NULL) {
        memcpy(reg, &(desc->cauda->dados), desc->tamInfo);
	    ret = SUCESSO;
    }
    return ret;
}

// Verificar se estah vazia
int testaVazia(descM *desc){
    if(desc->frente == NULL && desc->cauda == NULL) {
        return SIM;
    }
    return NAO;
}
