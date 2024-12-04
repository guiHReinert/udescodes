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
void printar(struct musica mus);
int search(struct musica *cd, char *key, int *len);

int main() {
     struct musica *cd;
     cd = malloc(sizeof(struct musica));
     int n = 0, m = 0;
     int t = 0;
     while(t != 5){ 
          printMenu(); 
          scanf("%d", &t);
          if(t == 1){
               // inserir(cd, &n, &m);
               inserir(&cd, &n);
          }
          else if(t == 3){
               for(int c=0; c<n; c++){
                    printar(cd[c]);
               }
          } 
          else if(t == 4){
               int opc = 0;
               do{
                    printf("Digite o indice da musica a ser mostrada: ");
                    scanf("%d", &opc);
               }while(opc < 0 || opc > n - 1);
               printar(cd[opc]);
          }
     }

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

// void inserir(struct musica *cd, int *n, int *m){
     // (*m)++;
     // if(*n < *m){
     //      (*n)++;
     //      cd = realloc(cd, (*n) * sizeof(struct musica));
     // }
void inserir(struct musica **cd, int *n){
     (*n)++;
     *cd = realloc(*cd, sizeof(struct musica) * (*n));

     getchar();
     printf("\nDigite o nome da musica: ");
     // scanf("%[^\n]s", cd[*m - 1].titulo);
     scanf("%[^\n]s", (*cd)[*n - 1].titulo);

     // for(int i=0; i < *m - 1; i++){
     //      if(strcmp(cd[i].titulo, cd[*m - 1].titulo) == 0){
     //           printf("Musica ja cadastrada!\n");
     //           (*m)--;
     //           return;
     //      }
     for(int i=0; i < *n - 1; i++){
          if(strcmp((*cd)[i].titulo, (*cd)[*n - 1].titulo) == 0){
               printf("Musica ja cadastrada!\n");
               (*n)--;
               return;
          }
     }
     if(search(*cd, (*cd)[*n - 1].titulo, n) == -1){
          printf("Musica ja cadastrada!\n");
          (*n)--;
          return;
     }

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

void printar(struct musica mus){
     printf("\nNome: %s\
     \nGenero: %s\
     \nGravadora: %s\
     \nLancamento: %d/%d/%d\
     \nDuracao: %d min\
     \nCompositor(es): %s\
     \nNacionalidade(s): %s\n\
     ", mus.titulo, mus.estilo, mus.gravadora,
     mus.data.dia, mus.data.mes, mus.data.ano,
     mus.tempo, mus.compositor.nome, mus.compositor.nacionalidade);
}

int search(struct musica *cd, char *key, int *len){
     for(int i = 0; i < *len; i++){
          if(strcmp((*cd).titulo, (*cd).titulo) == 0){
               return i;
          }
     }
     return -1;
}
