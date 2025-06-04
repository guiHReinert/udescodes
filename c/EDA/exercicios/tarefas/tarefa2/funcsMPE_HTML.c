#include "arq.h"

/*
<========================== PILHA ESCOLHIDA ===================================>

    Para a analise do aninhamento de arquivos HTML, utiliza-se somente a pilha
    direta da MPE jah criada para a implementação do menu.

<==============================================================================>
*/

/*
    Le um arquivo HTML de caminho <path> (com a extensao .html) e armazena a
    quantidade de linhas do documento em <tamanho>.
*/
char **lerHTML(char *path, int *tamanho){

    // Abre o arquivo e verifica se o arquivo existe.
    FILE *file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    /*
        Conta o numero de linhas do documento a partir de <buffer>, de tamanho
        TAM_LINHA caracteres.
    */
    char buffer[TAM_LINHA];
    *tamanho = 0;
    while(fgets(buffer, TAM_LINHA, file)){
        // printf("Linha %d: %s", *tamanho, buffer);
        (*tamanho)++;
    }

    // Realoca o arquivo para o seu inicio e possibilitar a sua releitura.
    rewind(file);

    /*
        Aloc dinamicamente o ponteiro para salvar as linhas do arquivo.
    */
    char **arquivo = (char **) malloc((*tamanho) * sizeof(char *));
    if(!arquivo){
        printf(" Erro ao alocar memoria para o arquivo HTML.");
        return NULL;
    }

    // Percorre por todas as linhas de <file>.
    int pos=0;
    while(fgets(buffer, TAM_LINHA, file)){

        // Aloca dinamicamente os ponteiros para as linhas de <arquivo>
        arquivo[pos] = (char *) malloc(TAM_LINHA * sizeof(char));
        if(!arquivo[pos]){
            printf(" Erro ao alocar memoria para uam das linahs doi arquivo HTML.");
            fclose(file);
            return NULL;
        }

        // Copia as cada linha de <file> para <arquivo>.
        strcpy(arquivo[pos++], buffer);
    }

    // Retorna o arquivo lido.
    fclose(file);
    return arquivo;
}

/*
    Le uma linha ou string e retorna somente o nome de uma tag na forma <"nome
    da tag">. A funcao eh capaz de identificar somente a primeira tag de uma
    mesma linha, ou seja, tags como "<p>" e "<\p>" (de paragrafo), que abrem e
    fecham na mesma linha, potencialmente serao dadas como mal fechadas.
*/
char *lerTag(char *linha){

    /*
        Posicao do caractere de <linha> e condicao <ehTag> de deteccao de uma
        tag (indentificou o caractere "<" na linha, logo o resto pode ser uma
        tag).
    */
    int pos=0 , ehTag=0;

    // Aloca dinamicamente o nome da tag de tamanho TAM_TAG.
    char *nome_tag = (char *) malloc(TAM_TAG * sizeof(char));
    if(!nome_tag){
        printf(" Erro ao alocar memoria para o nome da tag");
        return NULL;
    }

    /*
        Percorre por cada caractere de <linha> e retorna o nome da tag presente
        nele.
    */
    for(int i=0; i < TAM_TAG; i++){

        if(ehTag){
            // Procura o caractere ">" apos identificar o caractere "<".
            if(linha[i] == '>'){

                // "Fecha" e retorna a string contendo o nome da tag.
                nome_tag[pos] = '\0';
                return nome_tag;
            }

            // Proximo caractere.
            nome_tag[pos++] = linha[i];
        }
        
        // Identificou o caractere "<", logo pode haver uma tag nesta linha.
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
/*
    Funcao principal para analisar o aninhamento das tags de um HTML. 
    - <html>        Arquivo HTML lido por lerHTML();
    - <tamanho>     Numero de linhas do arquivo HTML.
*/
int analisarHTML(char **html, int tamanho){

    // Caso o arquivo nao existir.
    if(!html){
        return FRACASSO;
    }

    // Cria um novo descritor da MPE.
    descMP *desc = criarDescMP(tamanho);

    // Percorre por todas as linhas de <html>.
    for(int i = 0; i < tamanho; i++) {

        /*
            Caso nao for identificado nenhuma tag nesta linha, verifica-se a
            proxima.
        */
        char *tag = lerTag(html[i]);
        if (!tag) {
            free(tag);
            continue;
        }

        // Desconsidera-se as tags abaixo.
        if(tag[0] == '!' || strcmp(tag, "input") == 0 || strcmp(tag, "frame") == 0
            || strcmp(tag, "br") == 0 || strcmp(tag, "img") == 0)
        {
            free(tag);
            continue;
        }

        // Indentificou-se uma tag de fechamento.
        if(tag[0] == '/') {

            /*
                Desconsidera-se esta tag caso a MPE estiver vazia (sem tags de
                abertura restando).
            */
            if(desc->topo1 < 0){
                free(tag);
                continue;
            }

            /*
                Cria-se uma string respectiva ah tag de fechamento esperada para
                a tag no topo da pilha.
            */
            char tagFechada[TAM_TAG] = "/";
            strcat(tagFechada, desc->vet[desc->topo1].dados->nome);

            /*
                Desempilha a MPE caso a tag identificada for a tag de fechamento
                esperada (removeu um bloco de tags).
            */
            if(strcmp(tagFechada, tag) == 0) {
                desempilhar(desc, PILHA_DIRETA);
            }
            else {
                printf("\n ERRO de aninhamento da tag na linha %d. Esperado %s, mas encontrou %s\n", i + 1, tagFechada, tag);
                free(tag);
                return FRACASSO;
            }
        }

        // A tag identificada eh de abertura.
        else {

            // Aloca dinamicamente um struct dados.
            info *dados = (info *) malloc(sizeof(info));
            if(!dados) {
                printf(" Erro ao alocar memoria para o struct dados da tag.\n");
                free(tag);
                return FRACASSO;
            }

            /*
                Aloca dinamicamente o nome do struct anterior com tamanho
                <TAM_TAG>
            */
            dados->nome = malloc(TAM_TAG * sizeof(char));
            if (!dados->nome) {
                printf(" Erro ao alocar memoria para o nome da tag.\n");
            }

            /*
                Copia o nome da tag identificada para o nome alocado
                anteriormente e "fecha" esta string.
            */
            strncpy(dados->nome, tag, TAM_TAG - 1);
            dados->nome[TAM_TAG - 1] = '\0';

            // Empilha esta tag de abertura.
            empilhar(desc, dados, PILHA_DIRETA);

            free(tag);
        }
    }

    // Faltou uma ou mais tags de fechamento para as tags abertas.
    if(desc->topo1 >= 0){
        printf("\n\tERRO de aninhamento: %d tags abertas nao fechadas.\n", desc->topo1 + 1);

        destruirDescMP(desc);
        return FRACASSO;
    }

    // MPE vazia, arquivo bem aninhado.
    printf("\nO arquivo HTML está bem aninhado.\n");

    destruirDescMP(desc);
    return SUCESSO;
}
