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

void printm(); // printa o menu de opcoes
void inserir(struct musica *cd, int *n, int *m);
void print(struct musica *mus, int *id);

int main() {
     struct musica *cd;
     cd = malloc(sizeof(struct musica));
     int n = 0, m = 0;
     int t = 0;
     while(t != 5){ 
          printm(); 
          scanf("%d", &t);
          if(t == 1){
               inserir(cd, &n, &m);
          }
     }

     print(cd, &n);

     return 0;
}

void printm(){
     printf("\nDigite a ação desejada:\
     \n1 - Inserir uma nova musica ao registro\
     \n2- Remover uma musica do registro\
     \n3- Exibir as musicas registradas\
     \n4- Consultar um registro especifico\
     \n5- Sair do programa\n > ");
}

// Insere as informacoes em musica e nos structs correspondentes
// inserir(struct musica <pont das musicas>, int <cap do vetor>, int <qnt de musicas>)
void inserir(struct musica *cd, int *n, int *m){
     (*m)++;
     if(*n < *m){
          (*n)++;
          cd = realloc(cd, (*n) * sizeof(struct musica));
     }

     getchar();
     printf("\nDigite o nome da musica: ");
     scanf("%[^\n]s", cd[*m - 1].titulo);

     for(int i=0; i < *m - 1; i++){
          if(strcmp(cd[i].titulo, cd[*m - 1].titulo) == 0){
               printf("Musica ja cadastrada\n");
               (*m)--;
               return;
          }
     }
     getchar();
     printf("Informe o genero musical: ");
     scanf("%[^\n]s", cd[*n - 1].estilo);
     getchar();
     printf("Informe a gravadora: ");
     scanf("%[^\n]s", cd[*n - 1].gravadora);
     printf("Informe a data de lancamento (formato dd mm aaaa): ");
     scanf("%d%d%d", &cd[*n - 1].data.dia, &cd[*n - 1].data.mes, &cd[*n - 1].data.ano);
     printf("Informe a duracao da musica (tempo aproximado em minutos): ");
     scanf("%d", &cd[*n - 1].tempo);
     getchar();
     printf("Informe o nome do(as) compositor(as): ");
     scanf("%[^\n]s", cd[*n - 1].compositor.nome);
     getchar();
     printf("Informe a nacionalidade do/da compositor/compositora: ");
     scanf("%[^\n]s", cd[*n-1].compositor.nacionalidade);
}

void print(struct musica *mus, int *id){
     (*id)--;
     printf("\nNome: %s\
     \nGenero: %s\
     \nGravadora: %s\
     \nLancamento: %d/%d/%d\
     \nDuracao: %d min\
     \nCompositor(es): %s\
     \nNacionalidade(s): %s\n\
     ", mus[*id].titulo, mus[*id].estilo, mus[*id].gravadora,
     mus[*id].data.dia, mus[*id].data.mes, mus[*id].data.ano,
     mus[*id].tempo, mus[*id].compositor.nome, mus[*id].compositor.nacionalidade);
}
