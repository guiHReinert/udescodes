#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
     int dia, mes, ano;
};
struct Compositor{
     char nome[50], nacionalidade[50]; 
};
struct musica{
     char titulo[100], estilo[50], gravadora[50];
     int tempo;
     struct Data data;
     struct Compositor compositor;
};

void printm();
void inserir(struct musica *cd, int *n, int *m);
void print();

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
}

void printm(){
     printf("Digite a ação desejada:\n1 - Inserir uma nova musica ao registro\n2 - Remover uma musica do registro\n3 - Exibir as musicas registradas\n4 - Consultar um registro especifico\n5 - Sair do programa\n");
}

void inserir(struct musica *cd, int *n, int *m){
     *m = *m + 1;
     if(*n < *m){
          *n = *n + 1;
          cd = realloc(cd, 1 * sizeof(struct musica));
     }
     printf("Digite o nome da musica: ");
     scanf("%s", cd[*m - 1].titulo);
     for(int i = 0; i < *m - 1; i++){
          if(strcmp(cd[i].titulo, cd[*m - 1].titulo) == 0){
               printf("Musica ja cadastrada\n");
               *m = *m - 1;
               return;
          }
     }
     printf("Informe o genero musical: ");
     scanf("%[^\n]", cd[*n - 1].estilo);
     printf("Informe a gravadora: ");
     scanf("%[^\n]", cd[*n - 1].gravadora);
     printf("Informe a data de lancamento (formato dd mm aaaa): ");
     scanf("%d%d%d", &cd[*n - 1].data.dia, &cd[*n - 1].data.mes, &cd[*n - 1].data.ano);
     printf("Informe a duracao da musica (tempo aproximado em minutos): ");
     scanf("%d", &cd[*n - 1].tempo);
     printf("Informe o nome do/da compositor/compositora: ");
     scanf("%[^\n]", cd[*n - 1].compositor.nome);
     printf("Informe a nacionalidade do/da compositor/compositora: ");
     scanf("%[^\n]", cd[*n-1].compositor.nacionalidade);
}
