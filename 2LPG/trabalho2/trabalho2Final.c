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

struct musica{
     char titulo[MAX], estilo[MAX], gravadora[MAX];
     int tempo;
     struct Data data;
     struct Compositor compositor;
};

void printMenu();                                           // Printa o menu de opcoes
void inserir(struct musica **cd, int *n);                   // Armazena uma nova musica
void registrar(struct musica *mus, FILE *file, int len);    // Exporta/registra uma nova musica
void printar(struct musica mus);                            // Mostra os dados de uma musica no terminal
void remover(struct musica **cd, int *n, char *s);          // Remove uma musica armazenada
int search(struct musica **cd, char *key, int len);         // Retorna o indice de uma musica pelo seu nome(chave)

int main() {
     struct musica *cd;
     cd = malloc(sizeof(struct musica));

     int n = 0, t = 0;
     FILE *dados, *musicas;
     char f[MAX];

     // Recebe os dados salvos no arquivo de texto <f>
     printf("Digite o nome do arquivo a ser aberto: ");
     scanf("%s", f);
    while(strcmp(f, "musicas.txt") == 0){
        printf(" Nome de arquivo invalido. Digite outro nome: ");
        scanf("%s", f);
    }
     dados = fopen(f, "rt");

     if(dados == NULL){
          printf(" Arquivo nao encontrado");
     }else{
          printf(" Arquivo encontrado com sucesso");
          int m;
          fscanf(dados, "%d", &m);
          n = m;
          cd = realloc(cd, n * sizeof(struct musica));
          for (int i = 0; i < n; i++) {
               fscanf(dados, " %[^\n]s", cd[i].titulo);
               fscanf(dados, " %[^\n]s", cd[i].estilo);
               fscanf(dados, " %[^\n]s", cd[i].gravadora);
               fscanf(dados, "%d %d %d", &cd[i].data.dia, &cd[i].data.mes, &cd[i].data.ano);
               fscanf(dados, "%d", &cd[i].tempo);
               fscanf(dados, " %[^\n]s", cd[i].compositor.nome);
               fscanf(dados, " %[^\n]s", cd[i].compositor.nacionalidade);
     }
          fclose(dados);
     }

    while(t != 5){ 
          printMenu(); 
          scanf("%d", &t);
          if(t == 1){// Inserir uma nova musica
               inserir(&cd, &n);
          }
          else if(t == 2){// Remover uma musica
               printf("Digite o titulo da musica a ser removida\n");
               char s[MAX];
               getchar();
               scanf("%[^\n]s", s);
               remover(&cd, &n, s);
          }
          else if(t == 3){
               if(n == 0){
                    printf(" Nao ha musicas registradas\n");
                    continue;
               } 
               int opc = 0; 
               printf("1 - Mostrar as musicas no terminal\n2 - Exportar para o arquivo de texto\n >");
               scanf("%d", &opc);
               if(opc == 1){// Mostrar todas as musicas
                   printf("%-25s| %-25s| %-25s| %-25s| %-25s| %-25s| %-25s\n\n",
                        "Titulo:","Genero:","Gravadora:","Lancamento:","Duracao(min):","Compositor(es):","Nacionalidade(s):");
                   for(int c=0; c<n; c++){
                        printar(cd[c]);
                   }
               }
                else if(opc == 2){// Registrar os dados no relatorio
                  musicas = fopen("musicas.txt", "wt");
                  registrar(cd, musicas, n);
                  fclose(musicas);
               }
               else{
                   printf(" Opcao invalida\n");
                   continue;
               }
          }
          else if(t == 4){// Mostrar uma musica especifica
               if(n == 0){
                    printf("\n Nao ha musicas registradas\n");
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
                         printf("%-25s| %-25s| %-25s| %-25s| %-25s| %-25s| %-25s\n\n",
                              "Titulo:","Genero:","Gravadora:","Lancamento:","Duracao(min):","Compositor(es):","Nacionalidade(s):");    
                         printar(cd[namePos]);
                         break;
                    }
                    else{
                         printf(" Musica nao registrada.\n");
                    }
               }
          }
          else if(t == 5){
               printf("\nAdeus!\n");
          }
          else{
               printf(" Opcao invalida\n");
          }
     }
         // Registrar os dados no cadastro
         dados = fopen(f, "wt");
         fprintf(dados, "%d\n", n);
         for(int i = 0; i < n; i++){
              fprintf(dados, "\n%s\n%s\n%s\n%d %d %d\n%d\n%s\n%s\n",
              cd[i].titulo, cd[i].estilo, cd[i].gravadora,
              cd[i].data.dia, cd[i].data.mes, cd[i].data.ano,
              cd[i].tempo, cd[i].compositor.nome, cd[i].compositor.nacionalidade);
         }
    
         fclose(dados);
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

     // Insere uma nova musica no vetor
void inserir(struct musica **cd, int *n){
     char title[MAX];
     getchar();
     printf("\nDigite o nome da musica: ");
     scanf("%[^\n]s", title);

     if(search(&(*cd), title, *n) > -1){
          printf(" Musica ja cadastrada!\n");
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

void registrar(struct musica *mus, FILE *file, int len){// Registra todas as musicas armazenadas no relatorio
     fprintf(file, "%-25s| %-25s| %-25s| %-25s| %-25s| %-25s| %-25s\n\n",
          "Titulo:","Genero:","Gravadora:","Lancamento:","Duracao(min):","Compositor(es):","Nacionalidade(s):");
     char strLan[MAX];
     for(int c=0; c<len; c++){
          sprintf(strLan, "%d/%d/%d", mus[c].data.dia, mus[c].data.mes, mus[c].data.ano);
          fprintf(file,"%-25s| %-25s| %-25s| %-25s| %-25d| %-25s| %-25s\n",
               mus[c].titulo, mus[c].estilo, mus[c].gravadora,
               strLan, mus[c].tempo,
               mus[c].compositor.nome, mus[c].compositor.nacionalidade);
     }
}

void printar(struct musica mus){// Mostra uma unica musica no terminal
     char strLan[MAX];
     sprintf(strLan, "%d/%d/%d", mus.data.dia, mus.data.mes, mus.data.ano);
     printf("%-25s| %-25s| %-25s| %-25s| %-25d| %-25s| %-25s\n",
          mus.titulo, mus.estilo, mus.gravadora,
          strLan, mus.tempo,
          mus.compositor.nome, mus.compositor.nacionalidade);
}

void remover(struct musica **cd, int *n, char *s){// Remove uma unica musica
     int ind = search(cd, s, *n);
     if(ind == -1){
          printf(" Musica nao cadastrada\n");
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

int search(struct musica **cd, char *key, int len){// Retorna o indice de uma musica caso ela exista
     for(int i = 0; i < len; i++){
          if(strcmp((*cd)[i].titulo, key) == 0){
               return i;
          }
     }
     return -1;
}