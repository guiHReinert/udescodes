# Filas

Organiza um conjunto de elementos de modo que o primeiro elemento a ser adicionado é o primeiro a ser retirado, como demanda a sigla **FIFO** (*First In, First Out*).

## Tipos

Características básicas de uma fila:

- **Encadeadas**: simplesmente ou duplamente;
- **Inserção pela cauda ou pela frente**, ou seja, remoção pela frente ou pela cauda, respectivamente;
- **Estática ou Dinâmica**: variação de tamanho;
- **De Prioridade** (com ou sem otimizador);

Tipos específicos:
- ***FES*** : Fila Estática Simplória.
    
    1. Inicialização: `cauda = -1, frente = 0`
    2. Num. elementos na fila: `cauda - frente + 1`
    3. Fila vazia: `cauda < frente`
    4. Fila cheia: `cauda == comprimentoDoVetor - 1`

> **Remoção e Inserção**: Incrementa-se a cauda quando um nodo é inserido. No momento que um nodo é removido, incrementa-se a frente. Assim se informa a quantidade de nodos inseridos e removidos da fila.

- ***FEM-1***: Fila Estática com Movimentação de Dados a cada Remoção (1).

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
Método que infelizmente é operacionalmente custoso após repetidas realocações de filas...

- ***FEM-2***: Fila Estática com Movimentação de Dados a cada Remoção (2).

    1. Inicialização: `cauda = -1, frente = 0`
    2. Num. elementos na fila: `cauda - frente + 1`
    3. Fila vazia: `cauda < frente`
    4. Fila cheia: `cauda == comprimentoDoVetor - 1`

> 

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

- ***FEC***: Fila Estática Circular: O nodo da frente aponta para o nodo da cauda.

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

> **Inserção**: Incrementa a cauda e adiciona o nodo no espaço disponível mais inicial da fila:

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

> **Remoção**: Incrementa a frente e remove o nodo na posição mais frontal da fila:

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

---

### Simplesmente Encadeada

Possui um ponteiro em seus atributos que aponta OU para o membro anterior OU para o sucessor. Também podem ser implementadas junto de um descritor.

Exemplos de funções e declarações básicas para a manipulação de FES:

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

```c
// Inserir elemento na fila
int insere(info *reg, struct descFES *pF){    
    if (pF->cauda < pF->tamVet-1){	 
	    pF->cauda +=1;
	    memcpy(&(pF->vet[pF->cauda]),reg,sizeof(info)); //<<<<<<<
        return 1;
    }
    else{
        return 0;
    }
}
```

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

```c
// Remover descritor de fila
struct descFES* destroi(struct descFES *pF){
    free(pF->vet);
    free(pF);
    return NULL;	
}	
```

```c
// Calcular tamanho da fila
int tamanhoDaFila(struct descFES *pF){
    return pF->cauda - pF->frente + 1;
}
```

### Duplamente Encadeada

Possui dois ponteiros em seus atributos, cada um apontando para o seu antecessor e para o seu sucessor.

### De Prioridade s/ Otimizador

Cada nodo é associado a um valor, e 

### De Prioridade com Otimizador

