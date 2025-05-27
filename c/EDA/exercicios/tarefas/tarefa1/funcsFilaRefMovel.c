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

/*
    Utilizada somente em inserirCom() para calcular a menor distancia (em termos
    de valor de prioridade) entre o novo nodo a ser inserido na fila com um
    dos nodos anteriores a este (cauda ou ref. movel) ou com um dos nodos
    posteriores a este (frente ou ref. movel).
    A funcao entao retorna:
        - PELA_ESQUERDA:    se a distancia entre o novo nodo e o nodo ah
                            esquerda for menor;
        - PELA_DIREITA:     se a distancia entre o novo nodo e o nodo ah direita
                            for menor;
        - FRACASSO:         se a tag nao for reconhecida.
*/
char menorCaminho(nodo *start, nodo *end, nodo *newNodo, int (*compara)(info *novo, info *old, char tag), char tag) {

    // Distancias entre <newNodo> e os nodos <start> e <end>.
    int distEsquerda=0, distDireita=0;

    /*
        A implementacao varia de acordo com a tag utilizada.
        Por se tratarem de distancias, os valores abtidos nao podem ser
        negativos, logo utiliza-se abs() da biblioteca <stdlib.h>.
    */
    switch(tag){
        case MATRICULA:
            distEsquerda = abs(newNodo->dados.matricula - start->dados.matricula);
            distDireita = abs(newNodo->dados.matricula - end->dados.matricula);
            break;

        case RANKING:
            distEsquerda = abs(newNodo->dados.ranking - start->dados.ranking);
            distDireita = abs(newNodo->dados.ranking - end->dados.ranking);
            break;

        /*
            A funcao dificilmente retornarah FRACASSO, entretanto ainda assim
            considera-se este caso afim de evitar excecoes.
        */
        default:
            return FRACASSO;
    }

    // Caso as distancias sejam iguais, opta-se por inserir o nodo pela esquerda.
    if(distEsquerda <= distDireita) {return PELA_ESQUERDA;}

    else {return PELA_DIREITA;}
}

int inserirCom(info *novo, descM *desc, int (*compara)(info *novo, info *old, char tag), char tag){
    
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
                                FILA VAZIA
        Ponteiros de <newNodo> vazios, frente e cauda apontam para
        <newNodo>, ref aponta para <newNodo> e <def->tamFila> incrementa.
    */
    if(desc->frente == NULL && desc->cauda == NULL){
        desc->frente = newNodo;
        desc->cauda = newNodo;
        desc->ref = newNodo;
        desc->tamFila++;

        return SUCESSO;
    }

    /*
                        FILA COM PELO MENOS 1 NODO
    */
    /*
                        MENOR PRIORIDADE QUE A CAUDA
        - <newNodo->anterior>   aponta para NULL;
        - <newNodo->posterior>  aponta para a cauda;
        - <desc->cauda>         aponta para <newNodo>;
        - <desc->tamFila>       incrementa.
    */
    if(compara(novo, &(desc->cauda->dados), tag) == MENOR
        || compara(novo, &(desc->cauda->dados), tag) == IGUAL){
        newNodo->posterior = desc->cauda;
        desc->cauda->anterior = newNodo;
        desc->cauda = newNodo;

        // Nodo inserido: o referencial eh atualizado e o tamanho da fila incrementado.
        desc->ref = newNodo;
        desc->tamFila++;
        // printf("Inserido na cauda\n");

        return SUCESSO;
    }
    
    /*
                        MAIOR PRIORIDADE QUE A FRENTE
        - <newNodo->anterior>   aponta para a frente;
        - <newNodo->posterior>  aponta para NULL;
        - <desc->frente>        aponta para <newNodo>;
        - <desc->tamFila>       incrementa.
    */
    else if(compara(novo, &(desc->frente->dados), tag) == MAIOR){
        newNodo->anterior = desc->frente;
        desc->frente->posterior = newNodo;
        desc->frente = newNodo;

        // Nodo inserido: o referencial eh atualizado e o tamanho da fila incrementado.
        desc->ref = newNodo;
        desc->tamFila++;
        // printf("Inserido na frente\n");

        return SUCESSO;
    }
    
    /*
                    PRIORIDADE ENTRE A CAUDA E A FRENTE
                    
        Comparacao entre os dados de <newNodo> com os da cauda e da frente.
    */
    int compCauda = compara(novo, &(desc->cauda->dados), tag),
        compFrente = compara(novo, &(desc->frente->dados), tag),
        compRef = compara(novo, &(desc->ref->dados), tag);

    /*
        Verifica a posicao de <newNodo> em relacao ao referencial movel
        - <sobre>       <newNodo> com prioridade igual ao referencial movel;
        - <esquerda>    <newNodo> entre a cauda e o referencial movel;
        - <direita>     <newNodo> entre o referencial movel e a frente.
    */
    int sobre = compRef == IGUAL,
    esquerda = compCauda == MAIOR && (compRef == MENOR || compRef == IGUAL),
    direita = compRef == MAIOR && (compFrente == MENOR || compFrente == IGUAL);

    /*
                    PRIORIDADE IGUAL AO REFERENCIAL MOVEL
        - <newNodo->anterior>   aponta para o nodo anterior ao antigo
                                referencial movel;
        - <newNodo->posterior>  aponta para o antigo referencial movel;
        - <desc->ref>           aponta para <newNodo>;
        - <desc->tamFila>       incrementa.
    */
   if(sobre){
        newNodo->posterior = desc->ref;
        newNodo->anterior = desc->ref->anterior;
        if(desc->ref->anterior != NULL) {
           desc->ref->anterior->posterior = newNodo;
        }
        desc->ref->anterior = newNodo;
        desc->ref = newNodo;
        desc->tamFila++;
        
        return SUCESSO;
    }

    /*
        Os trechos a seguir de inserirCom() envolvem parte da logica basica da
        insercao de nodos de uma fila de prioridade com referencial movel.
        Ou seja, calcula-se a menor rota possivel entre os nodos de cauda,
        frente e referencial movel para inserir um nodo com menos repeticoes de
        laco para a indentificacao de sua posicao exata.

        A funcao menorCaminho() recebe os nodos de comeco (start), fim (end) e
        <newNodo>, comparar() e a tag utilizada para calcular a menor rota
        possivel em termos de prioridade. Os casos tratados adiante sao:

            (REGIOES)
        - <esquerda> e <direita>: "regioes" da fila onde serah inserido <newNodo>
        (em relacao ao referencial movel). Aqui se define os valores de <start>
        e de <end>:
            - <esquerda>:   <start> == cauda
                            <end>   == ref. movel
            - <direita>:    <start> == ref. movel
                            <end>   == frente

                (SENTIDOS)
            Em cada regiao pode-se inserir o nodo em um dos dois sentidos:
            - PELA_ESQUERDA:    caminho de <start> ateh <end>;
            - PELA_DIREITA:     caminho de <end> ateh <start>.

            Jah os codigos subsequentes de associacao de nodos sao semelhantes
            uns aos outros e conhecidos, portanto nao serao explicados.

            O contador de repeticoes utilizado para comparar os dois tipos de
            filas trabalhados incrementa dentro de cada while() de cada sentido
            adotado.
    */
    /*
                PRIORIDADE ENTRE A CAUDA E O REFERENCIAL MOVEL
    */
    else if(esquerda){

        // Caminho mais curto para um menor numero de repeticoes de laco.
        char way = menorCaminho(desc->cauda, desc->ref, newNodo, compara, tag);
        
        /*
                    REGIAO ESQUERDA, INSERCAO PELA ESQUERDA
            Com <walker> de prioridade imediatamente MAIOR que a de <newNodo>.
        */
        if(way == PELA_ESQUERDA){
            nodo *walker = desc->cauda;
            while(walker->posterior != NULL && compara(novo, &(walker->dados), tag) == MAIOR){
                walker = walker->posterior;
                desc->numRep++;
            }

            newNodo->posterior = walker;
            newNodo->anterior = walker->anterior;
            if(walker->anterior->posterior != NULL){
                walker->anterior->posterior = newNodo;
            }
            walker->anterior = newNodo;
            // printf("Inserido na regiao ESQUERDA pela CAUDA\n");
        }

        /*
                    REGIAO ESQUERDA, INSERCAO PELA DIREITA
            Com <walker> de prioridade imediatamente MENOR que a de <newNodo>.
        */
        else if(way == PELA_DIREITA){
            nodo *walker = desc->ref;
            while(walker->anterior != NULL && compara(novo, &(walker->dados), tag) == MENOR){
                walker = walker->anterior;
                desc->numRep++;
            }

            newNodo->anterior = walker;
            newNodo->posterior = walker->posterior;
            if(walker->posterior->anterior != NULL){
                walker->posterior->anterior = newNodo;
            }
            walker->posterior = newNodo;
            // printf("Inserido na regiao ESQUERDA pelo REFERENCIAL MOVEL\n");
        }

        /*
            Caso a verificacao fornecida por menorCaminho() falhar, o nodo nao
            serah inserido na fila.
        */
        else{return FRACASSO;}

        // Nodo inserido: o referencial eh atualizado e o tamanho da fila incrementado.
        desc->ref = newNodo;
        desc->tamFila++;

        return SUCESSO;
    }

    /*
                PRIORIDADE ENTRE O REFERENCIAL MOVEL E A FRENTE
    */
    else{
        int saida = 0;
        char way = menorCaminho(desc->ref, desc->frente, newNodo, compara, tag);
        
        /*
                    REGIAO DIREITA, INSERCAO PELA ESQUERDA
            Com <walker> de prioridade imediatamente MAIOR que a de <newNodo>.
        */
        if(way == PELA_ESQUERDA){
            nodo *walker = desc->ref;
            while(walker->posterior != NULL && compara(novo, &(walker->dados), tag) == MAIOR){
                walker = walker->posterior;
                desc->numRep++;
            }

            newNodo->posterior = walker;
            newNodo->anterior = walker->anterior;
            if(walker->anterior->posterior != NULL){
                walker->anterior->posterior = newNodo;
            }
            walker->anterior = newNodo;
            // printf("Inserido na regiao DIREITA pelo REFERENCIAL MOVEL\n");
        }
        
        /*
                    REGIAO DIREITA, INSERCAO PELA DIREITA
            Com <walker> de prioridade imediatamente MENOR que a de <newNodo>.
        */
        else if(way == PELA_DIREITA){
            nodo *walker = desc->frente;

            while(walker->anterior != NULL && compara(novo, &(walker->dados), tag) == MENOR){
                walker = walker->anterior;
                desc->numRep++;
            }

            /*
                Caso <walker> seja a frente (<newNodo> e <walker> possuem a 
                mesma prioridade), logo <newNodo> serah inserido antes da
                frente. 
            */
            if(walker->posterior == NULL){

                newNodo->anterior = walker->anterior;
                newNodo->posterior = walker;

                // Caso <walker> possua um nodo anterior a ele.
                if(walker->anterior->posterior != NULL){
                    walker->anterior->posterior = newNodo;
                }

                walker->anterior = newNodo;
            }

            // <walker> nao eh a frente.
            else{
                
                newNodo->anterior = walker;
                newNodo->posterior = walker->posterior;

                // Caso <walker> possua um nodo anterior a ele.
                if(walker->posterior->anterior != NULL){
                    walker->posterior->anterior = newNodo;
                }
                walker->posterior = newNodo;
            }

            // printf("Inserido na regiao DIREITA pela FRENTE\n");
        }

        /*
            Caso a verificacao fornecida por menorCaminho() falhar, o nodo nao
            serah inserido na fila.
        */
        else{return FRACASSO;}

        // Nodo inserido: o referencial eh atualizado e o tamanho da fila incrementado.
        desc->ref = newNodo;
        desc->tamFila++;

        return SUCESSO;
    }
}

// Remover nodos na fila (iteracao comecando pela cauda)
int removerNodoM(info *reg, descM  *desc){
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
    nodo *aux = NULL;
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
        return SUCESSO; 
    }
    return FRACASSO;	
}
