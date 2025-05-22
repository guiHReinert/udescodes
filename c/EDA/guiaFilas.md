# Filas

Organiza um conjunto de elementos de modo que o primeiro elemento a ser adicionado é o primeiro a ser retirado, como demanda a sigla **FIFO** (*First In, First Out*).

Uma das suas principais diferenças em relação às pilhas é que qualquer elemento pode ser retirado, uma vez que for a vez deste, sem que ele esteja na extremidade da fila (na cauda ou na frente).

## Sumário

1. [Características Básicas](#características-básicas)
2. [Tipos](#tipos)
    1. [FES](#fes-fila-estática-simplória-se)
    2. [FEM-1](#fem-1-fila-estática-com-movimentação-de-dados-a-cada-remoção---1-se)
    3. [FEM-2](#fem-2-fila-estática-com-movimentação-de-dados-a-cada-remoção---2-se)
    4. [FEC](#fec-fila-estática-circular-se)
    5. [FDE-Prioridade](#fde-prioridade-fila-duplamente-encadeada-de-prioridade)

## Características Básicas

- **Sobre Vetor**: Nodos ordenados a partir de um array de suporte, sem ponteiros para nodos anteriores ou posteriores;
- **Encadeadas**: Nodos ordenados a partir de ponteiros próprios para os nodos anteriores e/ou sucessores. Podem ser simplesmente (SE) ou duplamente (DE) encadeados;

    - **SE**: Possuem um ponteiro para o nodo antecessor ou sucessor;
    - **DE**: Possuem dois ponteiros: um para o nodo antecessor e outro para o sucessor.

- **Estática ou Dinâmica**: Filas estáticas possuem um tamanho fixo, e as dinâmicas um tamanho variávei;
- **De Prioridade**: Ordena os nodos utilizando um de seus campos como comparativo entre si;
- **Descritor/Otimizador**: Struct auxiliar com informações úteis à fila. Tais como o tamanho da fila, ponteiro para a cauda, ponteiro para a frente, tamanho em bytes do nodo, ponteiro para um nodo de referência, etc;

## Tipos

### FES (Fila Estática Simplória) (SE)
    
1. Inicialização: `cauda = -1, frente = 0`
2. Num. elementos na fila: `cauda - frente + 1`
3. Fila vazia: `cauda < frente`
4. Fila cheia: `cauda == comprimentoDoVetor - 1`

> **Remoção e Inserção**: Incrementa-se a cauda quando um nodo é inserido. No momento que um nodo é removido, incrementa-se a frente. Assim se informa a quantidade de nodos inseridos e removidos da fila.

*(Método que infelizmente é operacionalmente custoso após repetidas realocações de filas)*

Exemplos de funções e declarações básicas para a manipulação de uma FES:

```c
// Nodo com encadeamento simples
typedef struct{
    int idade;
    char nome[30];
	}info;

// Descritor da fila
struct descFES{
    int cauda;
    int frente;
    info *vet; 
    int tamVet;
    };
```
<details>

<summary>Verificação da Fila</summary>

```c
// Verificar se estah cheia
int cheia(struct descFES *pF){ 	
	if (pF->cauda >= pF->tamVet-1){
		return 1;
    }
	else{
		return 0;
    }
}
```

```c
// Verificar se estah vazia
int vazia(struct descFES *pF){
    if (pF->cauda < pF->frente){
        return 1;
    }
    else{
        return 0;
    }
}
```

</details>

<details>

<summary>Descritor</summary>

```c
// Criar novo descritor
struct descFES *cria(int tamVet){
    struct descFES *p=NULL;
	p = (struct descFES*) malloc(sizeof(struct descFES));
    if (p){
        p->vet = (info*) malloc(sizeof(info) * tamVet);//<<<<<<
        if (p->vet){
            p->cauda = -1;
            p->frente = 0;
            p->tamVet = tamVet;
        }
    }
    return p;
}
```

```c
// Remover descritor de fila
struct descFES* destroi(struct descFES *pF){
    free(pF->vet);
    free(pF);
    return NULL;	
}	
```

</details>

<details>

<summary>Alteração de Nodos da Fila</summary>

```c
// Inserir nodo na fila
int insere(info *reg, struct descFES *pF){    
    if (pF->cauda < pF->tamVet-1){	 
        pF->cauda +=1;
	    memcpy(&(pF->vet[pF->cauda]), reg, sizeof(info));
        return 1;
    }
    else{
        return 0;
    }
}
```

```c
// Remover elemento da fila
int remove_(info *reg, struct descFES *pF){  
    if (pF->cauda < pF->frente){
        return 0; // Fila vazia  (-1 < 0)
    }
    else{
        // Copia o struct de endereco &pF->vet[pF->frente] para reg, sendo que ambos os structs possuem tamanho sizeof(info) (limitador de memcpy)
		memcpy(reg, &(pF->vet[pF->frente]), sizeof(info));
        // &pF->vet[pF->frente]: local da memoria do struct ah frente do struct pF->vet no descritor pF
        pF->frente += 1;
        return 1;
	}
        
}
```

</details>

<details>

<summary>Buscar Extremidades da Fila</summary>

```c
//  Buscar cauda da fila
int buscaCauda(info *reg, struct descFES *pF){  
    if (pF->cauda >= pF->frente){
        memcpy(reg, &(pF->vet[pF->cauda]),sizeof(info)); //<<<<<<<<<<<
        return 1;
    }
    else{
        return 0;
    }
}
```
```c
// Buscar frente da fila
int buscaFrente(info *reg, struct descFES *pF){  
    if (pF->cauda >= pF->frente){
        memcpy(reg, &(pF->vet[pF->frente]),sizeof(info)); //<<<<<<<<<<<
        return 1;
    }
    else{
        return 0;
    }
}
```

</details>

<details>

<summary>Calcular Tamanho da Fila</summary>


```c
// Calcular tamanho da fila
int tamanhoDaFila(struct descFES *pF){
    return pF->cauda - pF->frente + 1;
}
```

</details>

---

### FEM-1 (Fila Estática com Movimentação de Dados a cada Remoção) - 1 (SE)

1. Inicialização: `cauda = -1, frente = 0` (frente constante)
2. Num. elementos na fila: `cauda + 1`
3. Fila vazia: `cauda < frente`
4. Fila cheia: `cauda == comprimentoDoVetor - 1`

> **Remoção e Inserção**: Incrementa-se somente a cauda quando um nodo é inserido. Sempre que se remove um elemento desta fila, todos os demais são realocados de modo a comportar o espaço recentemente liberado:

```c
for (i=0; i < tamanhoDaFila; i++){
    vet[i] = vet[i+1];
    cauda = cauda - 1;
    frente = 0;
}
```

---

### FEM-2 (Fila Estática com Movimentação de Dados a cada Remoção) - 2 (SE)

    1. Inicialização: `cauda = -1, frente = 0`
    2. Num. elementos na fila: `cauda - frente + 1`
    3. Fila vazia: `cauda < frente`
    4. Fila cheia: `cauda == comprimentoDoVetor - 1`

<details>

<summary>Pseudocódigo de Inserção</summary>

```c
inserção(....)
    if (cauda == comprimentoDoVetor - 1){ // Fila cheia
        tamanhoDaFila = cauda - frente + 1;
        // Ha espaço sobrando na fila
        if (tamanhoDaFila < comprimentoDoVetor){
            for(i=0; i < tamanhoDaFila; i++){
                vet[i] = vet[i+frente];
                cauda -= frente;
                frente = 0;
            }
            <inserção no final da fila>;
        }
        else{
            <fila realmente cheia>;
        }
    }
    else{ // Fila com espaco na cauda
        <inserção no final da fila>;
    }
```

</details>

### FEC (Fila Estática Circular) (SE)

O nodo da frente aponta para o nodo da cauda.

1. Inicialização: `cauda = -1, frente = 0`
2. Num. elementos na fila: contido no descritor
3. Fila vazia: `numElementos == 0`
4. Fila cheia: `numElementos == cumprimentoDoVetor`


Exemplo de estrutura básica:

```c
typedef struct {
    void *vetFila;
    int tamanhoDoVetor;
    int frente;         // Indexa o início da Fila
    int cauda;          // Indexa o final da Fila
    int tamanhoDaFila;  // Num de elementos
} Fila;
```

> **Inserção**: Incrementa a cauda e adiciona o nodo no espaço disponível mais inicial da fila.

<details>

<summary>Pseudocódigo</summary>

```c
insercao(...){
    // Ha espaço no início do vetor
    if (tamanhoAtualFila < tamanhoDoVetor){
        if (cauda == tamanhoDoVetor - 1){
            // Utilize o aspecto circular
            /*
            cauda = (cauda + 1) % tamanhoDoVetor;
            vet[cauda] = novo;
            tamanhoAtualFila++;
            */
            cauda = 0;
        }
        else{
            cauda++;
            vet[cauda] = novo;
            tamanhoAtualFila++;
        }
    }
    else{
        <fila realmente cheia>;
    }
}
```

</details>

> **Remoção**: Incrementa a frente e remove o nodo na posição mais frontal da fila.

<details>

<summary>Pseudocódigo</summary>

```c
Remocao(...){
    if(tamanhoDaFila == 0){
        <fila vazia>;
    }
    else{
        if(frente == tamanhoDoVetor-1){
            /*
            frente = (frente + 1) % tamanhoDoVetor;
            tamanhoDaFila--;
            */
            frente = 0;
        }
        else{
            frente++;
            tamanhoDaFila--;
        }
    }
}
```

</details>

---

### FDE-Prioridade (Fila Duplamente Encadeada de Prioridade)

Ordena os nodos de uma lista usando um de seus campos como comparativo entre todos eles.

Exemplos de funções e declarações básicas para a manipulação de uma FED-Prioridade:

```c
// Dados do nodo
typedef struct{
	int chave;
	char nome[30];
} info;

// Nodo duplamente encadeado
struct noFila{
	info dados;
	struct noFila *atras;
	struct noFila *defronte;
};

// Descritor da fila
struct descF{
	struct noFila *frente;
	struct noFila *cauda;
	int tamInfo;
};
```

<details>

<summary>Descritor</summary>

```c
// Criar novo descritor
struct descF * cria(int tamInfo){   	
    struct descF *desc = (struct descF*) malloc(sizeof(struct descF));
    if(desc != NULL) {
        desc->cauda = NULL;
        desc->frente = NULL;
	desc->tamInfo= tamInfo;
    }
    return desc;
}
```

```c
// Remover descritor
struct descF * destroi(struct descF *p){
    reinicia(p);
    free(p);
    return NULL; // Aterra o ponteiro externo, declarado na aplicação
}
```

</details>

<details>

<summary>Inserir Nodos</summary>

```c
// Inserir nodos na fila a partir da cauda
// (Com a implementacao do ponteiro da funcao compara())
int insere(info *novo,struct descF *p, int(*compara)(info *novo,info *visitado)){
	int result;
  	struct noFila *novoNoFila=NULL, *visitado=NULL;
 	if ((novoNoFila = (struct noFila *) malloc(sizeof(struct noFila))) != NULL){ 
		memcpy(&(novoNoFila->dados), novo, p->tamInfo);
		// Fila vazia
		if(p->frente == NULL && p->cauda == NULL){
			novoNoFila->atras = novoNoFila->defronte = NULL;
    	    p->frente = p->cauda = novoNoFila;
		}
		else{
			result = (*compara)(novo,&(p->cauda->dados));
			// Novo elemento é o de menor prioridade
			if(result == MENOR){
				novoNoFila->atras = NULL;
				novoNoFila->defronte = p->cauda;
				p->cauda->atras = novoNoFila;
				p->cauda = novoNoFila;
    	 	}
    	 	else{
				// Maior prioridade na frente
		   		visitado = p->frente; 
       	   		while(visitado->atras != NULL && (*compara)(novo,&(visitado->dados)) != MAIOR ) 
  					visitado = visitado->atras; /*comparou(A,B) e A < B ou A == B*/
				result = (*compara)(novo,&(visitado->dados));
				// Novo item fica a frente do visitado
       	   		if(result == MAIOR) {   	
					novoNoFila->atras = visitado;
      				if (visitado->defronte != NULL){
						novoNoFila->defronte = visitado->defronte;
						visitado->defronte->atras = novoNoFila;
      				} 
					// Novo item é o de maior prioridade de todos na fila, sendo a nova frente
      				else{  
						novoNoFila->defronte = NULL;      
						p->frente = novoNoFila;
					}	   
					visitado->defronte = novoNoFila;  
					novoNoFila->atras = visitado;       						
				}	
			}	
		}
		return SUCESSO;
    }
	return FRACASSO;
}

// Comparador entre dois valores inteiros
int compara(info *a, info *b){
    if (a->chave > b->chave)
        return MAIOR;
    else
        if (a->chave < b->chave)
            return MENOR;
        else
            return IGUAL;
}
```

</details>

<details>

<summary>Inserir Nodos (alternativa)</summary>

```c
// Inserir nodos na fila a partir da frente
int insere(info *pInfo, struct descF *p){
	int result;
	struct noFila *novoNoFila=NULL, *visitado=NULL;
	if ((novoNoFila = (struct noFila *) malloc(sizeof(struct noFila))) != NULL){ 
		memcpy(&(novoNoFila->dados),pInfo, p->tamInfo);
		// Fila vazia
  		if(p->frente == NULL && p->cauda == NULL) {
			novoNoFila->atras = novoNoFila->defronte = NULL;
    	    p->frente = p->cauda = novoNoFila;
		}
        else{ 
			// Novo elemento eh o de menor prioridade que o da cauda
    	 	if(novoNoFila->dados.idade < p->cauda->dados.idade) {
				novoNoFila->atras=NULL;
    	 		novoNoFila->defronte = p->cauda;
    	 		p->cauda->atras = novoNoFila;
    	 		p->cauda = novoNoFila; // Inseriu na cauda da lista
    	 	}
			// Possui prioridade maior que o da cauda
    	 	else{
		   		visitado = p->frente;
				// Cancela quando visitado chegar na cauda E a idade do visitado for menor que a do novo item
				// Ou seja, o novo item eh imediatamente o de maior prioridade
       	   		while(visitado->atras != NULL && (visitado->dados.idade >= novoNoFila->dados.idade)) 
  					visitado = visitado->atras; /* A(idade) <= B(idade) */
				// Novo item fica a frente do visitado
       	   		if(visitado->dados.idade < novoNoFila->dados.idade) {   	
					novoNoFila->atras = visitado;
      				if (visitado->defronte != NULL){
						// Encaixar o novo nodo entre o visitado e o sucessor do visitado
						novoNoFila->defronte = visitado->defronte;
						visitado->defronte->atras = novoNoFila;
      				} 
					// Novo item eh o de maior prioridade de todos na fila, sendo a nova frente
      				else{
						novoNoFila->defronte = NULL;      
						p->frente = novoNoFila;
				    }	   
					visitado->defronte = novoNoFila;  
				}	
         	}   	
		}
		return SUCESSO;
    }
	return FRACASSO;
}

```

</details>

<details>

<summary>Remover Nodos</summary>

```c
// Remover nodos na fila
int remove_(info *reg, struct descF  *p){
	int ret = FRACASSO;
	struct noFila *aux = p->cauda;
    if(p->cauda != NULL && p->frente != NULL){
       	memcpy(reg, &(p->frente->dados), p->tamInfo);
		if(aux == p->frente) { // Caso tenha 1 elemento apenas
			free(p->frente);
			p->frente = p->cauda = NULL;
		}
		else {
			p->frente= p->frente->atras;
            free(p->frente->defronte); 
            p->frente->defronte = NULL;
		}
		ret = SUCESSO;
	}
	return ret;
}
```

```c
// Reiniciar fila
int reinicia(struct descF *p){
	int ret=FRACASSO;
    struct noFila *aux=NULL;
    if(p->frente != NULL && p->cauda != NULL){  
        aux = p->cauda->defronte;
        while(aux != NULL) {
            free(p->cauda);
            p->cauda = aux;
            aux = aux->defronte;
        }
        free(p->cauda);
        p->frente = NULL;
        p->cauda = NULL;
        ret=SUCESSO; 
    }
    return ret;	
}
```

</details>

<details>

<summary>Buscar Extremidades da Fila</summary>

```c
// Buscar frente da fila
int buscaNaFrente(info *reg, struct descF *p){  
    int ret = FRACASSO;
    if(p->frente != NULL && p->cauda != NULL) { 	
        memcpy(reg, &(p->frente->dados), p->tamInfo);
        ret = SUCESSO;
    }
    return ret;
}
```

```c
// Buscar cauda da fila
int buscaNaCauda(info *reg, struct descF *p){
    int ret = FRACASSO;
    if(p->cauda != NULL && p->frente != NULL) {
        memcpy(reg, &(p->cauda->dados), p->tamInfo);
	    ret = SUCESSO;
    }
    return ret;
}
```

</details>

<details>

<summary>Fila Vazia</summary>

```c
// Verificar se estah vazia
int testaVazia(struct descF *p){
    if(p->frente == NULL && p->cauda == NULL) {
        return SIM;
    }
    return NAO;
}
```

</details>