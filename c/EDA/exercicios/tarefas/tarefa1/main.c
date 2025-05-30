#include "arq.h"

/*
    Como compilar este projeto:

gcc main.c funcsCSV.c funcsGerais.c funcsFilaBasica.c funcsFilaRefMovel.c -o app
./app

*/

int main(){

    /*
        Leitura de dataset_v1.csv:
        - <arquivo>         array de strings contendo todas as linhas do dataset;
        - <tamanhoDataset>  quantidade de linhas do dataset.
    */
    int tamanhoDataset, ans=-1, *range, id=0, count=0;
    char **arquivo = lerDataset("dataset_v1.csv", &tamanhoDataset), **base;
    descM *descritor;

    /*
        Menu com as operacoes basicas para a manipulacao de uma FDE-prioridade
        com referencia movel.
    */
    char *menu =
        "\n Selecione o indice respectivo ah opcao abaixo para manipular uma FDE com referencia movel:\
        \n\n 1 - Formar uma base aleatoria a a partir de \"dataset_v1.csv\"\
        \n 2 - Mostrar base\
        \n 3 - Criar descritor unico\
        \n 4 - Inserir nodo no descritor\
        \n 5 - Remover nodo com maior prioridade\
        \n 6 - Buscar cauda\
        \n 7 - Buscar frente\
        \n 8 - Mostrar fila e tamanho da fila\
        \n 9 - Reiniciar fila (remocao de todos os nodos)\
        \n 10 - Calcular desempenho entre as FDE-prioridade com e sem re. movel (ranking)\
        \n 11 - Calcular desempenho entre as FDE-prioridade com e sem re. movel (matricula)\
        \n 0 ou 12 - Sair.\n";
    printf("%s", menu);

    while(1){
        printf("\n >> ");
        scanf("%d", &ans);
        
        // Criar nova base.
        if(ans == 1){
            printf("Digite a tamanho da base a ser utilizada: ");
            scanf("%d", range);

            base = criarBase(arquivo, tamanhoDataset, *range);
            printf(" Base criada com sucesso.\n");
        }

        // Mostrar a base.
        else if(ans == 2){
            if(base != NULL){
                printarBase(base, range);
            }
            else{
                printf(" Base nao criada.\n");
            }
        }

        // Criar novo descritor unico.
        else if(ans == 3){
            if(descritor != NULL){
                printf(" Descritor ja criado.\n");
            }
            else{
                descritor = criaDescM(sizeof(info));
                printf(" Descritor criado com sucesso.\n");
            }

        }

        /*
            Insere um nodo no descritor utilizando RANKING como criterio de
            prioridade. Pode inserir nodos repetidos tambem.
        */
        else if(ans == 4){
            id = 0;
            if(descritor != NULL){
                printarBase(base, range);
                printf("\nDigite o indice do nodo acima a ser inserido na fila: ");
                scanf("%d", &id);
                
                inserirCom(criarDados(base[id]), descritor, comparar, RANKING);
                
                printf("\nNODO INSERIDO: ");
                printarNodo(criarNodo(criarDados(base[id])));
                printf("\n");
            }
            else{
                printf(" Descritor nao criado.\n");
            }
        }

        // Remover nodo com maior prioridade.
        else if(ans == 5){
            if(base != NULL){
                if(descritor != NULL){                      
                    if(descritor->tamFila > 0){
                        printf("NODO REMOVIDO: ");
                        printarNodo(descritor->frente);
                        
                        removerNodoM(descritor);
                    }
                    else{
                        printf(" Fila vazia.\n");
                    }
                }
                else{
                    printf(" Descritor nao criado.\n");
                }
            }
            else{
                printf(" Base nao criada.\n");
            }
        }
        
        // Buscar a cauda da fila.
        else if(ans == 6){
            
            if(descritor != NULL){

                info *out = (info *) malloc(descritor->tamInfo);
                if(out == NULL){
                    printf(" Nao foi possivel alocar memoria para a cauda da fila.\n");
                }

                if(buscaNaCauda(out, descritor)){
                    printf("Cauda da fila: ");
                    printarNodo(criarNodo(out));
                    free(out);
                }
                else{
                    printf(" Fila vazia.\n");
                }
            }
            else{
                printf(" Descritor nao criado.\n");
            }
        }

        // Buscar a frente da fila
        else if(ans == 7){
            
            if(descritor != NULL){

                info *out = (info *) malloc(descritor->tamInfo);
                if(out == NULL){
                    printf(" Nao foi possivel alocar memoria para a frente da fila.\n");
                }

                if(buscaNaFrente(out, descritor)){
                    printf("Frente da fila: ");
                    printarNodo(criarNodo(out));
                    free(out);
                }
                else{
                    printf(" Fila vazia.\n");
                }
            }
            else{
                printf(" Descritor nao criado.\n");
            }
        }
        
        // Mostrar a fila formada e o tamanho dela.
        else if(ans == 8){
            if(descritor != NULL){

                printf("\n");
                printarFilaCom(descritor);
                
                printf("\tTamanho da fila: %d\n", descritor->tamFila);
            }

            else{
                printf(" Descritor nao criado.\n");
            }
            
        }
        
        // Reiniciar a fila.
        else if(ans == 9){
            if(descritor != NULL){
                if(descritor->tamFila > 0){

                reinicia(descritor);

                printf(" Fila reiniciada com sucesso.\n");
                }
                else{
                    printf(" Fila vazia.\n");
                }
            }
            else{
                printf(" Descritor nao criado.\n");
            }
        }

        // Compara o desempenho entre as filas pelo ranking.
        else if(ans == 10){
            compararDesempenho(arquivo, &tamanhoDataset, RANKING);
        }

        // Compara o desempenho entre as duas filas pela matricula.
        else if(ans == 11){
            compararDesempenho(arquivo, &tamanhoDataset, MATRICULA);
        }

        // Sair do sistema.
        else if(ans == 0 || ans == 12){
            printf("Saindo...\n");
            break;
        }

        // Opcao invalida.
        else{
            printf("%s", menu);
            printf(" Digite uma opcao valida.\n");
        }
        
    }

    return 0;
}

void printarBase(char **base, int *range){
    printf("\n");
    for(int b=0; b < *range; b++){
        printf("[%d]\t", b);
        printarNodo(criarNodo(criarDados(base[b])));
    }
}

/*
    Cria uma sequencia de bases de nodos as quais ambas as filas FDE-prioridade
    e FDE-prioridade com referencia movel utilizarao para terem seus nodos
    inseridos pelo criterio <tag> (RANKING ou MATRICULA).

    Cada base conterah 500, 1000, 1500, ..., 8500 e 9000 nodos que serao
    inseridos em cada fila e, para cada descritor de cada fila, o campo
    <tamFila> serah incrementado para cada laco de repeticao utilizado na sua
    respectiva funcao de insercao de nodos (inserirSem() e inserirCom()).

    No final serah mostrada uma tabela comparando estes dados entre todas as
    filas, bem como a media de repeticoes de laco e as razoes
        - numRep_Sem / numRep_Com:  Quantas vezes o num. de repeticoes da fila
                                    sem ref. movel eh maior que o da fila com
                                    ref. movel;
        - numRep_Com / numRep_Sem:  A porcentagem do num. de repeticoes da fila
                                    com ref. movel em relacao ao num de
                                    repeticoes da fila sem ref. movel.
*/
void compararDesempenho(char **arquivo, int *tamanhoDataset, char tag){

    // Para calcular o tempo de execucao.
    clock_t start = clock();

    /*
        Criacao do array com todas as quantidades de nodos de cada base formada.
        Como (9000 - 500) / 500 == 17, logo serao 17 as bases implementadas para
        cada tipo de funcao de insercao de nodos (sem referencial movel e com
        referencial movel).
    */
    int NUM_BASES = (9000 - 500) / 500 + 1;

    int bases[NUM_BASES];
    for(int i=0; i <= NUM_BASES; i++){
        bases[i] = (i + 1) * 500;
    }
    
    /*
        Array contendo os decritores de cada fila sem referencial movel. Cada
        descritor ou elemento de <descritores> eh uma fila separada e possui a
        propria base.
    */
    descS descritoresSem[NUM_BASES];

    /*
        Array contendo os descritores de cada fila com referencial movel.
    */
    descM descritoresCom[NUM_BASES];
    
    // Titulo da tabela.
    printf("\n%40s INSERCAO POR ", "");
    if(tag == RANKING){
        printf("RANKING\n\n");
    }
    else if(tag == MATRICULA){
        printf("MATRICULA\n\n");
    }
    
    // Categorias da tabela.
    printf(" Base |   Fila   | Num Repeticoes | Media Repeticoes | numRep_Sem / numRep_Com | numRep_Com / numRep_Sem");
    printf("\n------|----------|----------------|------------------|-------------------------|-------------------------\n");
    
    for(int b=0; b < NUM_BASES; b++){
        
        // Base atual.
        int range = bases[b];

        /*
            Criacao de um novo descritor para cada elemento das arrays. Apos a
            chamada de cada implementarBase(), a fila resultante da base
            carregarah este descritor para que entao sejam trabalhados os seus
            dados.
        */
        descritoresSem[b] = *criaDescF(sizeof(info));
        descritoresCom[b] = *criaDescM(sizeof(info));
        
        implementarBaseSem(arquivo, *tamanhoDataset, range, &descritoresSem[b], tag);
        implementarBaseCom(arquivo, *tamanhoDataset, range, &descritoresCom[b], tag);

        // Renomeacao dos descritores por fins de legibilidade.
        descS *descritorSem = &(descritoresSem[b]);
        descM *descritorCom = &(descritoresCom[b]);
        
        // Impressao da tbela
        printf("%-5d | %-7s | %-14d | %-16.2f | %13.2f%10s |", range, "SEM REF:",
            descritorSem->numRep,
            (float) descritorSem->numRep / range,
            (float) descritorSem->numRep / descritorCom->numRep,
            ""
        );
        printf("\n%-5s | %-7s | %-14d | %-16.2f | %23s | %14.2f%%\n", "", "COM REF:",
            descritorCom->numRep, 
            (float) descritorCom->numRep / range,
            "", (float)descritorCom->numRep / descritorSem->numRep * 100
        );
        
        printf("------|----------|----------------|------------------|-------------------------|-------------------------\n");
    }

    printf("\nTempo de execucao: %lfs\n", (double) (clock() - start) / CLOCKS_PER_SEC);
}
