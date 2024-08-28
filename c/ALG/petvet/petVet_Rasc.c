#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// #include <windows.h>

float matriz[4][99]; // Matriz de preços pagos pelo cliente
// [0]: Vacinas
// [1]: Castrações
// [2]: Rações
// [3]: Medicamentos

char recibo[99][5][100]; // Matriz para armazenar detalhes dos serviços
// [][0]: Tipo de serviço
// [][1]: Animal
// [][2]: Nome do animal
// [][3]: Data / contato do medicamento
// [][4]: Preço total

float somat(int pos) {
    float soma = 0;
    for (int l = 0; l < 4; l++) {
        for (int c = 0; c < (pos + 1); c++) {
            soma += matriz[l][c];
        }
    }
    return soma;
}

void imprimirRecibo(int totalServicos) {
    float total = 0.0;

    printf("\nRecibo Final:\n");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < totalServicos; i++) {
        // Exibe o nome do animal com o tipo entre parênteses
        if (strcmp(recibo[i][1], "f") == 0 || strcmp(recibo[i][1], "F") == 0) {
            printf("%s (f)\n", recibo[i][2]);
        } else if (strcmp(recibo[i][1], "c") == 0 || strcmp(recibo[i][1], "C") == 0) {
            printf("%s (c)\n", recibo[i][2]);
        } else {
            printf("%s\n", recibo[i][2]);
        }

        // Exibe o serviço
        printf("%s\n", recibo[i][0]);

        // Exibe o preço do serviço
        printf("%s\n", recibo[i][4]);

        total += atof(recibo[i][4] + 3); // Adiciona o valor, ignorando o "R$ " inicial

        printf("\n"); // Adiciona uma linha em branco entre as sessões
    }

    printf("--------------------------------------------------------------------------------\n");
    printf("Preço total de todos os serviços: R$ %.2f\n", total);
    printf("--------------------------------------------------------------------------------\n");
}

int main() {
    //SetConsoleOutputCP(CP_UTF8);

    printf("                 "); printf("  _\n");
    printf(" ___ ____ ___    "); printf(" / \\__\n");
    printf(" █_█ █___  █     "); printf("(    @\\___");   printf("  ❤\n");
    printf(" █   █___  █     "); printf(" /        O");   printf("    /\\_/\\\n");
    printf("     ____ ___    "); printf("/   (_____/");   printf("   ( o.o )\n");
    printf(" █ █ █___  █     "); printf("/_____/  U");    printf("     > ^ <\n");
    printf("  █  █___  █     \n");

    char nome[60] = "0", nomeani[60], data[30], remedio[99], telefone[25], ddd[10],
    caso, animal, tamanho, resposta;
    int pacotes, vez = -1;
    double total, valorRac;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    while ((resposta != 'n') && (resposta != 'N')) {
        vez++;
        printf("\n--------------------------------------------\n");
        printf("• Olá! Bem vindo(a) ao nosso Petshop PetVet!\n");
        printf("Nossa clínica oferece os seguintes serviços:\n");
        printf("1) Vacina\n");
        printf("2) Castração\n");
        printf("3) Venda de ração\n");
        printf("4) Medicamentos\n");
        if (strcmp(nome, "0") == 0) { // GAMBIARRA. cada vez que o loop do while era executado, <nome> era ignorado
            printf("• Qual seu o nome social? ");
            scanf(" %[^\n]s", nome);
        }
        printf("• Escolha um de nossos serviços enumerados acima:\n >> ");
        scanf(" %c", &caso);
        getchar();

        switch (caso) {
            case '1': // VACINA
                printf("• Felino ou Canino? (F/C) \n >> ");
                scanf(" %c", &animal);
                getchar();
                if (animal == 'f' || animal == 'F') {
                    printf("• Nome do felino: \n >> ");
                    scanf(" %[^\n]s", nomeani);
                    getchar();
                } else if (animal == 'c' || animal == 'C') {
                    printf("• Nome do canino: \n >> ");
                    scanf(" %[^\n]s", nomeani);
                    getchar();
                } else {
                    printf("Digite uma opção válida!\n");
                    return 0;
                }
                printf("• Data da vacinação: \n >> ");
                scanf(" %[^\n]s", data);
                getchar();
                printf("///////////////////////\n");

                printf("Cliente: %s\n", nome);
                printf("Serviço: Vacina\n");
                if (animal == 'F' || animal == 'f') {
                    printf("Felino: %s\n", nomeani);
                } else {
                    printf("Canino: %s\n", nomeani);
                }
                printf("Data: %s\n", data);
                printf(" >> Preço total: R$ 190,00\n");
                matriz[0][vez] = 190.0;

                // Armazenar no recibo
                strcpy(recibo[vez][0], "Vacina");
                sprintf(recibo[vez][1], "%c", animal);
                sprintf(recibo[vez][2], "%s", nomeani);
                sprintf(recibo[vez][3], "%s", data);
                sprintf(recibo[vez][4], "R$ 190,00");

                break;

            case '2': // CASTRAÇÃO
                printf("• Felino ou Canino? (F/C) \n >> ");
                scanf(" %c", &animal);
                getchar();
                if (animal == 'f' || animal == 'F') {
                    printf("• Nome do felino: \n >> ");
                    scanf(" %[^\n]s", nomeani);
                    getchar();
                } else if (animal == 'c' || animal == 'C') {
                    printf("• Nome do canino: \n >> ");
                    scanf(" %[^\n]s", nomeani);
                    getchar();
                } else {
                    printf("Digite uma opção válida!\n");
                    return 0;
                }
                printf("• Data da castração: \n >> ");
                scanf(" %[^\n]s", data);
                getchar();
                printf("-----------------------\n");

                printf("Cliente: %s\n", nome);
                printf("Serviço: Castração\n");
                if (animal == 'F' || animal == 'f') {
                    printf("Felino: %s\n", nomeani);
                    printf("Data: %s\n", data);
                    printf(" >> Preço total: R$ 220,00\n");
                    matriz[1][vez] = 220.0;

                    // Armazenar no recibo
                    strcpy(recibo[vez][0], "Castração");
                    sprintf(recibo[vez][1], "%c", animal);
                    sprintf(recibo[vez][2], "%s", nomeani);
                    sprintf(recibo[vez][3], "%s", data);
                    sprintf(recibo[vez][4], "R$ 220,00");

                } else {
                    printf("Canino: %s\n", nomeani);
                    printf("Data: %s\n", data);
                    printf(" >> Preço total: R$ 280,00\n");
                    matriz[1][vez] = 280.0;

                    // Armazenar no recibo
                    strcpy(recibo[vez][0], "Castração");
                    sprintf(recibo[vez][1], "%c", animal);
                    sprintf(recibo[vez][2], "%s", nomeani);
                    sprintf(recibo[vez][3], "%s", data);
                    sprintf(recibo[vez][4], "R$ 280,00");
                }

            break;

            case '3': // VENDA DE RAÇÃO
                printf("• Quantos pacotes serão comprados? \n >> ");
                scanf("%d", &pacotes);
                getchar();
                printf("• Qual será o tamanho dos pacotes? (P/M/G) \n >> ");
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
                printf("Pedido: %d unidades de tamanho %c cada.\n", pacotes, tamanho);
                if (pacotes > 1) {
                    printf("Valor bruto: R$ %.2lf\n", valorRac);
                    printf("Desconto: 10 %% \n");
                    total = 0.9 * valorRac;
                } else {
                                        printf("Desconto: 0 %% \n");
                    total = valorRac;
                }
                printf(" >> Preço total: R$ %.2lf\n", total);
                matriz[2][vez] = total;

                // Armazenar no recibo
                strcpy(recibo[vez][0], "Venda de ração");
                sprintf(recibo[vez][1], "N/A");
                sprintf(recibo[vez][2], "%d pacotes de tamanho %c", pacotes, tamanho);
                sprintf(recibo[vez][3], "N/A");
                sprintf(recibo[vez][4], "R$ %.2lf", total);

                break;

            case '4': // MEDICAMENTOS
                printf("• Digite o nome do remédio para encomendar:\n >> ");
                scanf(" %[^\n]s", remedio);
                getchar();

                printf("• Digite o seu telefone, com espaço após DDD:\n >> ");
                scanf(" %s %s", ddd, telefone);
                getchar();

                printf("-----------------------\n");

                printf("Cliente: %s\n", nome);
                printf("Serviço: Encomenda de medicamento\n");
                printf("Medicamento: %s\n", remedio);
                printf("Contato: %s %s\n", ddd, telefone);
                
                // Armazenar no recibo
                strcpy(recibo[vez][0], "Medicamento");
                sprintf(recibo[vez][1], "N/A");
                sprintf(recibo[vez][2], "Remédio: %s", remedio);
                sprintf(recibo[vez][3], "Contato: %s %s", ddd, telefone);
                sprintf(recibo[vez][4], "R$ 0.00"); // Valor fictício, pode ser ajustado

                break;

            default:
                printf("Digite uma opção válida!\n");
                return 0;
        }

        printf("\nDeseja pedir outro serviço? (S/N) ");
        scanf(" %c", &resposta);
        getchar();
    }

    imprimirRecibo(vez + 1);

    return 0;
}

