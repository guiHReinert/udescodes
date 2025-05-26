#include "arq.h"

/*
    COMPILACAO

gcc main.c funcsCSV.c funcsGerais.c funcsFilaBasica.c funcsFilaRefMovel.c -o app
./app

    RESUMO

Fila Duplamente Encadeada com Prioridade
FDE-Prioridade
Implementacoes: Normal
                    (sem referencia movel)
                Com referencia movel
                    (otimizador para reduzir o numero de interacoes na insercao)

Escrever um menu as well

Separar os registros do dataset em intervalos para comparar aleatoriamente um a um com as duas filas implementadas:
500, 1000, 1500, 2000, ... , 8500, 9000.

Para cada uma das bases extraídas do arquivo csv, carregue cada FDE e calcule o
número médio de iterações de laço para a inserção de todos os itens na base em
questão utilizando a funcionalidade de inserção disponível na interface de cada fila.

4. Utilizar os valores de ranking e da matricula como prioridade

5.1 Implementar graficos comparando o numero de interacoes entre as duas filas

5.2 Explicar por que uma delas funciona melhor do que a outra, argumentando com base no comportamento do codigo

5.3 Explique qual seria o melhor conjunto de casos de inserção para a
FDE_PrioRefMovel?

5.4 Explique qual seria o pior conjunto de casos de inserção para a
FDE_PrioRefMovel?

                            ORGANIZACAO DOS ARQUIVOS

main.c:         Importa <> e instancia os objetos declarados dentro de void main(void){}
aqr.h:          Declara todas as funcoes em functions.c, structs e definicoes utilizadas em main.c e em functions.c
functions.c:    Declara todas as funcoes de manipulacao de nodos utilizados nos objetos de fila instanciados em main.c
    (REVISAR)
*/

int main(){

    /*
        Leitura de dataset_v1.csv:
        - <arquivo>         array de strings contendo todas as linhas do dataset;
        - <tamanhoDataset>  quantidade de linhas do dataset.
    */
    int tamanhoDataset;
    char **arquivo = lerDataset("dataset_v1.csv", &tamanhoDataset);

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
    
    descS descritores[NUM_BASES];

    for(int b=0; b < NUM_BASES; b++){
        
        descritores[b] = *criaDescF(sizeof(info));
        int range = bases[b];
        
        char **base = criarBase(arquivo, tamanhoDataset, range);
        for(int l=0; l < range; l++){
            if(base[l] != NULL){
                info *dados = criarDados(base[l]);
                if(dados == NULL){
                    printf("Erro ao criar dados\n");
                    return 1;
                }
                
                inserirSem(dados, &descritores[b], compararRank);
            }
        }
        printf("Base %d\tNumero de repeticoes: %d\tMedia de repeticoes: %.2f\n",
            range, (&descritores[b])->numRep, (float) descritores[b].numRep / range);        
    }
    return 0;
}