#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Data{
     int dia, mes, ano;
};
struct Compositor{
     char nome[MAX], nacionalidade[MAX]; 
};

// musica contem os structs acima
struct musica{
     char titulo[MAX], estilo[MAX], gravadora[MAX];
     int tempo;
     struct Data data;
     struct Compositor compositor;
};

void printMenu(); // printa o menu de opcoes
void inserir(struct musica **cd, int *n);
void printar(struct musica mus, FILE *file);
void printar_terminal(struct musica mus);
void remover(struct musica **cd, int *n, char *s);
int search(struct musica **cd, char *key, int len);

int main() {
    struct musica *cd;
    cd = malloc(sizeof(struct musica));
    int n = 0, t = 0;
    FILE *file;
    char f[MAX];
    printf("Digite o nome do arquivo a ser aberto: ");
    scanf("%s", f);
    file = fopen(f, "rt");
    if(file == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }else{
        int m;
        fscanf(file, "%d", &m);
        n = m;
        cd = realloc(cd, n * sizeof(struct musica));
        for(int i = 0; i < n; i++){
            fscanf(file, " %[^\n]s", cd[i].titulo);
            fscanf(file, " %[^\n]s", cd[i].estilo);
            fscanf(file, " %[^\n]s", cd[i].gravadora);
            fscanf(file, "%d %d %d", &cd[i].data.dia, &cd[i].data.mes, &cd[i].data.ano);
            fscanf(file, "%d", &cd[i].tempo);
            fscanf(file, " %[^\n]s", cd[i].compositor.nome);
            fscanf(file, " %[^\n]s", cd[i].compositor.nacionalidade);
        }
        fclose(file);
    }
    file = fopen("musicas.txt", "wt");
    
    while(t != 5){ 
        printMenu(); 
        scanf("%d", &t);
        if(t == 1){
            // inserir(cd, &n, &m);
            inserir(&cd, &n);
        }
        else if(t == 2){
            printf("Digite o titulo da musica a ser removida\n");
            char s[MAX];
            getchar();
            scanf("%[^\n]s", s);
            remover(&cd, &n, s);
        }
          else if(t == 3){
            int op;
            printf("\n1 - Mostrar no terminal\n2 - Mostrar no arquivo de texto\n");
            scanf("%d", &op);
            if(op == 2){
               if(n == 0){
                printf("Nao ha musicas registradas\n");
                continue;
               } 
               file = fopen("musicas.txt", "wt");
               for(int c=0; c<n; c++){
                    printar(cd[c], file);
               }
               fclose(file);
            }
            if(op == 1){
                if(n == 0){
                printf("Nao ha musicas registradas\n");
                continue;
               } 
               for(int c=0; c<n; c++){
                    printar_terminal(cd[c]);
               }
            }
          } 
          else if(t == 4){
            if(n == 0){
                printf("\nNao ha musicas registradas\n");
                continue;
            }
               char name[MAX];
               int namePos = 0;
               while(1){
                    getchar();
                    printf("Digite o nome da musica a ser mostrada: ");
                    scanf("%[^\n]s", name);
                    namePos = search(&cd, name, n);
                    if(namePos > -1){          
                        printar_terminal(cd[namePos]);
                        break;
                }
                else{
                        printf("Esta musica nao esta registrada.\n");
                }
            }
        }
        else if(t == 5){
            printf("\nAdeus!\n");
        }
        else{
            printf("Opcao invalida\n");
        }
    }
    file = fopen(f, "wt");
    fprintf(file, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(file, "%s\n%s\n%s\n%d %d %d\n%d\n%s\n%s\n", cd[i].titulo, cd[i].estilo, cd[i].gravadora, cd[i].data.dia, cd[i].data.mes, cd[i].data.ano, cd[i].tempo, cd[i].compositor.nome, cd[i].compositor.nacionalidade);
    }

    fclose(file);
    free(cd);
    return 0;
}

void printMenu(){
    printf("\nDigite a ação desejada:\
    \n1 - Inserir uma nova musica ao registro\
    \n2 - Remover uma musica do registro\
    \n3 - Exibir as musicas registradas\
    \n4 - Consultar um registro especifico\
    \n5 - Sair do programa\n > ");
}

// Insere as informacoes em musica e nos structs correspondentes
// inserir(struct musica <pont das musicas>, int <cap do vetor>, int <qnt de musicas>)

void inserir(struct musica **cd, int *n){
    char title[MAX];
    getchar();
    printf("\nDigite o nome da musica: ");
    scanf("%[^\n]s", title);

    if(search(&(*cd), title, *n) > -1){
        printf("Musica ja cadastrada!\n");
        return;
    }
    (*n)++;
    *cd = realloc(*cd, sizeof(struct musica) * (*n));
    strcpy((*cd)[*n - 1].titulo, title);

    getchar();
    printf("Informe o genero musical: ");
    scanf("%[^\n]s", (*cd)[*n - 1].estilo);
    getchar();
    printf("Informe a gravadora: ");
    scanf("%[^\n]s", (*cd)[*n - 1].gravadora);
    printf("Informe a data de lancamento (formato dd mm aaaa): ");
    scanf("%d%d%d", &(*cd)[*n - 1].data.dia, &(*cd)[*n - 1].data.mes, &(*cd)[*n - 1].data.ano);
    printf("Informe a duracao da musica (tempo aproximado em minutos): ");
    scanf("%d", &(*cd)[*n - 1].tempo);
    getchar();
    printf("Informe o nome do(as) compositor(as): ");
    scanf("%[^\n]s", (*cd)[*n - 1].compositor.nome);
    getchar();
    printf("Informe a nacionalidade do/da compositor/compositora: ");
    scanf("%[^\n]s", (*cd)[*n - 1].compositor.nacionalidade);
}

void printar(struct musica mus, FILE *file){
    fprintf(file,"\nNome: %s\
    \tGenero: %s\
    \tGravadora: %s\
    \tLancamento: %d/%d/%d\
    \tDuracao: %d min\
    \tCompositor(es): %s\
    \tNacionalidade(s): %s\n\
    ", mus.titulo, mus.estilo, mus.gravadora,
    mus.data.dia, mus.data.mes, mus.data.ano,
    mus.tempo, mus.compositor.nome, mus.compositor.nacionalidade);
}

void printar_terminal(struct musica mus){
    printf("\nNome: %s\
    \tGenero: %s\
    \tGravadora: %s\
    \tLancamento: %d/%d/%d\
    \tDuracao: %d min\
    \tCompositor(es): %s\
    \tNacionalidade(s): %s\n\
    ", mus.titulo, mus.estilo, mus.gravadora,
    mus.data.dia, mus.data.mes, mus.data.ano,
    mus.tempo, mus.compositor.nome, mus.compositor.nacionalidade);
}

void remover(struct musica **cd, int *n, char *s){
    int ind = search(cd, s, *n);
    if(ind == -1){
        printf("Musica nao cadastrada\n");
        return;
    }
    for(int i = ind; i < *n-1; i++){
        (*cd)[i] = (*cd)[i+1];
    }
    (*n)--;
    *cd = realloc(*cd, sizeof(struct musica) * (*n));
    printf("%s foi removida com sucesso\n", s);
    return;
}

int search(struct musica **cd, char *key, int len){
    for(int i = 0; i < len; i++){
        // printf("\nComparando (%s) com (%s)\n", (*cd)[i].titulo, key);
        if(strcmp((*cd)[i].titulo, key) == 0){
            return i;
        }
    }
    return -1;
}
