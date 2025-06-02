#include "arq.h"


char **lerHTML(char *path, int *tamanho){

    FILE *file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    char buffer[TAM_LINHA];
    *tamanho = 0;
    while(fgets(buffer, TAM_LINHA, file)){
        // printf("Linha %d: %s", *tamanho, buffer);
        (*tamanho)++;
    }
    // printf("\n");
    rewind(file);

    char **arquivo = (char **) malloc((*tamanho) * sizeof(char *));
    if(!arquivo){
        printf(" Erro ao alocar memoria para o arquivo HTML.");
        return NULL;
    }

    int pos=0;
    while(fgets(buffer, TAM_LINHA, file)){

        arquivo[pos] = (char *) malloc(TAM_LINHA * sizeof(char));
        if(!arquivo[pos]){
            printf(" Erro ao alocar memoria para uam das linahs doi arquivo HTML.");
            fclose(file);
            return NULL;
        }

        strcpy(arquivo[pos++], buffer);
    }

    fclose(file);
    return arquivo;
}

/*
    Le uma linha ou string e retorna o nome de uma tag na forma <"nome da tag">.
*/
char *lerTag(char *linha){
    int pos=0 , ehTag=0;

    char *nome_tag = (char *) malloc(TAM_TAG * sizeof(char));
    if(!nome_tag){
        printf(" Erro ao alocar memoria para o nome da tag");
        return NULL;
    }

    for(int i=0; i < TAM_TAG; i++){
        if(ehTag){
            if(linha[i] == '>'){
                nome_tag[pos] = '\0';
                return nome_tag;
            }

            nome_tag[pos++] = linha[i];
        }
        
        if(linha[i] == '<'){
            ehTag = 1;
        }
    }
    return NULL;
}

/*
    PSEUDOCODIGO DE ANALISE DE HTML

    Abre arquivo fonte HTML
    Cria pilha
    Le primeiro nome-tag e o empilha
        ENQUANTO houver tags no arquivo
            Le proxima tag
            SE nome-tag eh precedido por barra
                SE pilha contem no topo o mesmo nome-tag sem a barra
                    Desempilha o topo
                SENAO
                    ERRO de "aninhamento" da nome-tag na linha xx
                    Encerra
            SENAO
                Empilha nome-tag
    SE pilha nao vazia
        ERRO de "aninhamento" da nome-tag na linha xx
        Encerra
    SENAO
        HTML com as tags bem "aninhadas".
*/


int analisarHTML(char **html, int tamanho){

    descMP *desc = criarDescMP(tamanho);
    if (!desc) {
        printf("Erro ao criar descritor da MP\n");
        return FRACASSO;
    }

    for(int i = 0; i < tamanho; i++) {

        char *tag = lerTag(html[i]);
        if (!tag) {
            continue;
        }

        if(tag[0] == '!' || strcmp(tag, "input") == 0 || strcmp(tag, "frame") == 0
            || strcmp(tag, "br") == 0 || strcmp(tag, "img") == 0)
        {
            free(tag);
            continue;
        }

        if(tag[0] == '/') {

            if(desc->topo1 < 0){
                continue;
            }

            char tagFechada[TAM_TAG] = "/";
            strcat(tagFechada, desc->vet[desc->topo1].dados->nome);

            if(strcmp(tagFechada, tag) == 0) {
                desempilhar(desc, PILHA_DIRETA);
            }
            else {
                printf("\n ERRO de aninhamento da tag na linha %d. Esperado %s, mas encontrou %s\n", i + 1, tagFechada, tag);
                free(tag);
                return FRACASSO;
            }
        }
        else {

            info *dados = (info *) malloc(sizeof(info));
            if(!dados) {
                printf(" Erro ao alocar memoria para o struct dados da tag.\n");
                free(tag);
                return FRACASSO;
            }

            dados->nome = malloc(TAM_TAG * sizeof(char));
            if (!dados->nome) {
                printf(" Erro ao alocar memoria para o nome da tag.\n");
            }

            strncpy(dados->nome, tag, TAM_TAG - 1);
            dados->nome[TAM_TAG - 1] = '\0';

            empilhar(desc, dados, PILHA_DIRETA);
        }

        free(tag);
    }

    if(desc->topo1 >= 0){
        printf("\n\tERRO de aninhamento: %d tags abertas nao fechadas.\n", desc->topo1 + 1);

        destruirDescMP(desc);
        return FRACASSO;
    }

    printf("\nO arquivo HTML está bem aninhado.\n");

    destruirDescMP(desc);
    return SUCESSO;
}
