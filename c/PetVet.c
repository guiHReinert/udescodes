#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main () {

    char nome[25], nomeani[25], data[15], remedio[99], telefone[25], ddd[10],
    caso, animal, tamanho;
    int pacotes;
    double total, valorRac;

    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("──────▄▀▄─────▄▀▄\n─────▄█░░▀▀▀▀▀░░█▄\n─▄▄──█░░░░░░░░░░░█──▄▄\n█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█\n");
    printf("-----------------------\n");
    printf("Olá! Bem vindo(a) ao nosso Petshop PetVet !S2\n");
    printf("Nossa clínica oferece os seguintes serviços:\n");
    printf("1) Vacina\n");
    printf("2) Castração\n");
    printf("3) Venda de ração\n");
    printf("4) Medicamentos\n");
    printf("Qual seu o nome social?\n >> ");
    scanf("%[^\n]s", nome);
    printf("Escolha um de nossos serviços enumerados acima:\n >> ");
    scanf(" %c", &caso);
    getchar();

     switch (caso){
        case '1': // Vacina
            printf("Felino ou Canino? (F/C) \n >> ");
            scanf(" %c", &animal);
            getchar();
            if (animal == 'f' || animal == 'F') {
                printf("Nome do felino: \n >> ");
                scanf("%s", nomeani);
                getchar();
            } else if (animal == 'c' || animal == 'C'){
                printf("Nome do canino: \n >> ");
                scanf("%s", nomeani);
                getchar();
            } else {
                printf("Digite uma opção válida!\n");
                return 0;
            }
            printf("Data da vacinação: \n >> ");
            scanf("%s", data);
            getchar();
            printf("-----------------------\n");

            printf("Cliente: %s\n", nome);
            printf("Serviço: Vacina\n");
            if (animal == 'F') {
                printf("Felino: %s\n", nomeani);
            } else {
                printf("Canino: %s\n", nomeani);
            }
            printf("Data: %s\n", data);
            printf(" >> Preço total: R$ 190,00\n");
    
        break;
        case '2': // Castração
            printf("Felino ou Canino? (F/C) \n >> ");
            scanf(" %c", &animal);
            getchar();
            if (animal == 'F') {
                printf("Nome do felino: \n >> ");
                scanf("%s", nomeani);
                getchar();
            } else if (animal == 'C'){
                printf("Nome do canino: \n >> ");
                scanf("%s", nomeani);
                getchar();
            } else {
                printf("Digite uma opção válida!\n");
                return 0;
            }
            printf("Data da castração: \n >> ");
            scanf("%s", data);
            getchar();
            printf("-----------------------\n");

            printf("Cliente: %s\n", nome);
            printf("Serviço: Castração\n");
            if (animal == 'F') {
                printf("Felino: %s\n", nomeani);
                printf("Data: %s\n", data);
                printf(">> Preço total: R$ 220.00\n");
            } else {
                printf("Canino: %s\n", nomeani);
                printf("Data: %s\n", data);
                printf(" >> Preço total: R$ 280.00\n");
            }
        break;
        case '3': // Venda de ração
            printf("Quantos pacotes serão comprados? \n >> ");
            scanf("%i", &pacotes);
            getchar();
            printf("Qual será o tamanho dos pacotes? (P/M/G) \n >> ");
            scanf(" %c", &tamanho);
            getchar();
            if (tamanho == 'p' || tamanho == 'P') {
                valorRac = 30 * pacotes;
            } else if (tamanho == 'm' || tamanho == 'M') {
                valorRac = 70 * pacotes;
            } else if (tamanho == 'g' || tamanho == 'G') {
                valorRac = 120 * pacotes;
            } else {
            printf("Digite uma opção válida!\n");
            return 0; 
            }

            printf("-----------------------\n");
            
	        printf("Cliente: %s\n", nome);
            printf("Serviço: Venda de ração\n");
            printf("Pedido: %i unidades de tamanho %c cada.\n", pacotes, tamanho);
            if (pacotes > 1){
                printf("Valor bruto: R$ %.2lf\n", valorRac);
            	printf("Desconto: 10 %% \n");
                total = 0.9 * valorRac;
            } else {
                printf("Desconto: 0 %% \n");
                total = valorRac;
                }
            printf(" >> Preço total: R$ %.2lf\n", total);
        break;
        case '4':   
            
            printf("Digite o nome do remédio para encomendar:\n >> ");
            scanf("%[^\n]s", remedio);
            getchar();
            
            
            printf("Digite o seu telefone:\n >> ");
                scanf("%s"" ""%s", ddd, telefone);
                getchar();


            printf("-----------------------\n");

            printf("Cliente: %s\n", nome);
            printf("Serviço: Encomenda de medicamento\n");
            printf("Medicamento: %s\n", remedio);
            printf("Contato: %s"" ""%s\n", ddd, telefone);
    

        break;
     }
return 0;
}
