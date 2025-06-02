#include "arq.h"

void exibeTamanhoMP(MP *desc)
{  if (desc!=NULL) 
     printf(" %d pilhas de tamanho maximo = %d\n\n",desc->N, desc->L);
   else 
      printf("\n%s Multipilha inexistente! \n","\U0001F4E2");
}


MP * cria(MP *p, int N, int L, int tamInfo)
{
    int i, M;
    NoMP *aux;
    MP *desc = NULL, *ret=NULL; 

    if (N > 0 && L > 0 && tamInfo > 0) 
    {
        M = N*L;
        if( (desc = (MP*) malloc(sizeof(MP))) == NULL )
            ret= NULL;
        else  
            if( ( desc->vet = (NoMP*) malloc((M+N)* sizeof(info)) )==NULL) 
	     { 	// Aloca��o de mem�ria para a multipilha (vetor de unions) constituida de N*L n�s de dados (N*L = M) 			//e os N n�s descritores das respectivas pilhas; 
                free(desc);
                ret= NULL;
            }
            else 
		{
                	desc->N = N; /* Iniciando os atributos gerais da multi-pilha; */
                	desc->L = L;
                        desc->tamInfo = tamInfo;
        	        aux = desc->vet; /* Ponteiro auxiliar aux apontando para a �rea de descritores; */
        	        for(i = 0; i < N ; i++) 
        	        { /* Formatando a MpE: iniciando os descritores das pilhas; */
        	            (aux + i)->descritor.topo = -1;
        	            //Os topos s�o iniciados com valores que n�o indexam as parti��es das respectivas 				    //pilhas, indicando que a considerada pilha est� vazia. Perceba que tamb�m � poss�vel 				    //utilizar a sintaxe (*pp)->vet[i].descritor ou ((*pp)->vet + i).descritor para acesso 				    //ao i-�simo descritor. 
        	            (aux + i)->descritor.inicioParticao = N + i*L;
	
                	}
			ret= desc;
            	}
    }
    return ret;
}

int insereNaPilha(MP *p, int nPilha, info* novo)
{   int inicioParticao, topo;
    if(p->vet == NULL) { /*testa existencia da pilha*/
        printf(">>Erro ao inserir, pilha inexistente\n");
        return FRACASSO;
    }
    
    if(p->N < nPilha) {
        printf(">>Erro ao inserir, pilha inexistente\n");
        return FRACASSO;
    }

    if(p->vet[nPilha-1].descritor.topo == (p->L)-1) {
        printf(">>Erro ao inserir, a pilha %d est� cheia\n", nPilha);
        return FRACASSO;
    }

    /*se a pilha existe e n�o est� cheia, inser��o pode ocorrer normalmente*/
    inicioParticao = p->vet[nPilha-1].descritor.inicioParticao;
    p->vet[nPilha-1].descritor.topo += 1;
    topo = p->vet[nPilha-1].descritor.topo;

    memcpy(&(p->vet[inicioParticao + topo].dados), novo, p->tamInfo);

    return SUCESSO;
}

int removeDaPilha(MP *p, int nPilha, info* removido)
{
    int topo = p->vet[nPilha-1].descritor.topo;
    int inicioParticao = p->vet[nPilha-1].descritor.inicioParticao;

    if(topo == -1) {
        printf("\nA pilha %d esta vazia\n", nPilha);
        return FRACASSO;
    }

    memcpy(removido, &(p->vet[inicioParticao + topo].dados), p->tamInfo);
    p->vet[nPilha-1].descritor.topo--;

    return SUCESSO;
}

int consultaTopo(MP *p, int pilhaAlvo, info* consultado)
{
    int topo, inicioParticao; 
    topo = p->vet[pilhaAlvo-1].descritor.topo;
    inicioParticao = p->vet[pilhaAlvo-1].descritor.inicioParticao;
    if(pilhaAlvo < 1 || pilhaAlvo > p->N){
        printf("\n%s Nao existe #pilha = %d! \n","\U0001F4E2", pilhaAlvo);
        return FRACASSO;
    }
       
    if(topo == -1) {
        printf("\nA pilha %d esta vazia\n", pilhaAlvo);
        return FRACASSO;
    }

    memcpy(consultado, &(p->vet[inicioParticao + topo]), p->tamInfo);

    return SUCESSO;
}

MP * destroi(MP *p) 
{ 
	free(p->vet);
	return NULL;
}
