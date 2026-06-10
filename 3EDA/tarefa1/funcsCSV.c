#include "arq.h"

/*
    Le o arquivo CSV e armazena todos os dados em uma array de strings de
    tamanho TAM_CSV (10002).
*/
char **lerDataset(char *path, int *tamanho){
    // Abre o arquivo e verifica se ele nao existe
    FILE *file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    /*
        Buffer e numero de linhas do CSV para alocar espaco na memoria de 
        <pessoas> de acordo com o tamanho do arquivo.
    */
    char buffer[TAM_LINHA];
    *tamanho = 0;
    while(fgets(buffer, TAM_LINHA, file)){
        (*tamanho)++;
    }
    /*
        Reposiciona o ponteiro do arquivo para o inicio do arquivo para nova
        leitura.
    */
    rewind(file);
    
    // Posicao utilizada para acessar cada string de <pessoas>
    int pos = 0;
    /*
        Aloca espaco na memoria para a array contendo as linhas do CSV e 
        verifica se a alocacao foi possivel.
        */
    char **pessoas = (char **) malloc((*tamanho) * sizeof(char *));
    if(!pessoas){
        printf("Erro ao alocar memoria para a array <pessoas>\n");
        fclose(file);
        return NULL;
    }

    /*
        Lê o arquivo CSV linha por linha e armazena cada linha no buffer
        ja declarado. Em seguida, aloca espaco na memoria para cada
        linha.
    */
    while(fgets(buffer, TAM_LINHA, file)){
        pessoas[pos] = (char *) malloc(TAM_LINHA);
        if(!pessoas[pos]){
            printf("Erro ao alocar memoria da linha %d.\n", pos);
            fclose(file);
            return NULL;
        }
        /*
            Copia a linha lida do buffer para uma array de <pessoas> e
            incrementa o buffer.
        */
        strcpy(pessoas[pos], buffer);
        pos++;
    }

    /*
        Fecha o arquivo, retorna a array criada, uma vez que a funcao foi
        executada com sucesso.
    */
    fclose(file);
    return pessoas;
}

/*
    Cria uma base de dados a partir de um CSV lido em <pessoas> e tamanho
    definido. A base em si eh constituida de <tamanhoBase> linhas aleatorias
    das linhas de <pessoas>, sendo que tamanhoBase <= tamanho.
*/
char **criarBase(char **pessoas, int tamanho, int tamanhoBase){

    // Aloca uma copia de <pessoas> para nao interferir com os dados originais.
    char **copia = (char **) malloc(tamanho * sizeof(char *));
    for(int i=0; i < tamanho; i++){
        copia[i] = (char *) malloc(TAM_LINHA);
        if(!copia[i]){
            printf("Erro ao alocar memoria da linha %d.\n", i);
            return NULL;
        }

        // Copia cada linha de <pessoas> para <copia>.
        strcpy(copia[i], pessoas[i]);
    }
    
    // Gera um valor de seed aleatorio
    srand(time(NULL));
    
    /*
        Algoritmo principal de Fisher-Yates para "aleatorizar" as linhas de
        <copia>: Em <num> se cria um numero aleatorio entre 0 e <tamanho> para
        servir de indice de <copia>, e em seguida sao trocados os valores entre
        <copia[i]> e <copia[num]>. E, por característica do algoritmo, os
        elementos sorteados nunca sao repetidos.
    */
    for(int i = tamanho - 1; i > 0; i--){
        int num = rand() % (i + 1);
        
        char temp[TAM_LINHA];
        strcpy(temp, copia[i]);
        strcpy(copia[i], copia[num]);
        strcpy(copia[num], temp);
    }

    // Aloca a base de tamanho <tamanhoBase>.
    char **base = (char **) malloc(tamanhoBase * sizeof(char *));
    if(!base){
        printf("Erro ao alocar memoria para a array <base>\n");
        return NULL;
    }
    
    /*
        Copia as <tamanhoBase> primeiras linhas de <copia> para <base>. E, uma
        vez que <copia> passou pelo processo de aleatorizacao, as linhas
        contidas em <base> tambem sao aleatorias.
    */
    for(int i=0; i < tamanhoBase; i++){
        base[i] = (char *) malloc(TAM_LINHA);
        if(!base[i]){
            printf("Erro ao alocar memoria da linha %d.\n", i);
            return NULL;
        }
        
        strcpy(base[i], copia[i]);
    }
    
    /*
        Libera a memoria alocada para <pessoas> e <copia>, uma vez que
        ambas ja foram utilizadas.
    */
    for(int i=0; i < tamanho; i++){
        free(copia[i]);
    }
    free(copia);

    // Retorna a base criada.
    return base;
}

/*
    Cada string contida em uma base eh convertida em um unico struct do tipo
    <info>. A funcao retorna o ponteiro para este struct.
*/
info *criarDados(char *linha){

    /*
        Aloca uma copia de <linha> para evitar qualquer interferencia com a
        string original.
    */
    char *copia = (char *) malloc(strlen(linha) + 1);
    if(!copia){
        printf("Erro ao alocar memoria para a copia da linha\n");
        return NULL;
    }
    strcpy(copia, linha);

    /*
        Aloca um novo struct <dados> de tipo <info>. <dados> armazenarah os
        dados de <linha> separados por <token>.
    */
    info *dados = (info*) malloc(sizeof(info));
    if(!dados){
        printf("Erro ao alocar memoria para o struct dados\n");
        return NULL;
    }

    char *token;

    /*
        strtok() eh utilizado para separar os dados contidos em <copia> e
        separados por ",". strtok(copia, ",") retorna o primeiro token, e os
        subconsequentes sao retornados respectivamente por strtok(NULL, ","),
        substituindo o delimitador "," por '\0' em cada dado.
        Para cada dado obtido, verifica-se tambem se o token gerado foi nulo.
    */
    token = strtok(copia, ",");
    if(!token){return NULL;}

    /*
        Aloca espaco na memoria para o nome do aluno e copia o token
        correspondente. strlen(token) + 1 cosidera o tamanho de <token> + '\0'.
    */
    dados->nome = (char *) malloc(strlen(token) + 1);
    if (!dados->nome) {
        printf("Erro ao alocar memoria para nome\n");
        return NULL;
    }
    strcpy(dados->nome, token);

    /*
        Renova o valor de <token> para conter o numero de matricula e converte
        este valor de string para inteiro com atoi().
    */
    token = strtok(NULL, ",");
    if(!token) {return NULL;}
    dados->matricula = atoi(token);

    // Processo similar ah matricula do aluno para a conversao do ranking.
    token = strtok(NULL, ",");
    if(!token) {return NULL;}
    dados->ranking = atoi(token);

    // Processo similar ao nome do aluno, porem agora para o seu curso.
    token = strtok(NULL, ",");
    if(!token) {return NULL;}
    dados->curso = (char *) malloc(strlen(token) + 1);
    if (!dados->curso) {
        printf("Erro ao alocar memoria para curso\n");
        return NULL;
    }
    strcpy(dados->curso, token);

    /*
        Remove o caractere de quebra de linha em <dados->curso> para mostrar o
        seu valor devidamente: strspn() retorna o indice da string anterior ah
        presenca de '\n', e substitui este caractere por '\0'.
    */
    dados->curso[strcspn(dados->curso, "\n")] = '\0';

    // Retorna o struct de dados criado e libera na memoria <copia>.
    free(copia);
    return dados;
}

/*
    Cria um unico nodo a partir de um struct <info>, mas sem adiciona-lo a
    a qualquer fila.
*/
nodo *criarNodo(info *dados){
    
    // Aloca o novo nodo.
    nodo *nd = (nodo *) malloc(sizeof(nodo));
    if(!nd){
        printf("Erro ao alocar memoria para o nodo\n");
        return NULL;
    }

    // Define os campos do nodo.
    memcpy(&(nd->dados), dados, sizeof(info));
    nd->anterior = NULL;
    nd->posterior = NULL;

    // Retorna o nodo criado.
    return nd;
}