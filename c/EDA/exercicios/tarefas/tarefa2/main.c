#include "arq.h"

/*
    Como Compilar esta Tarefa

gcc funcsGerais.c funcsMPE.c funcsMPE_HTML.c main.c -o app
./app

    RESUMO

1) Considere uma multipilha estática contendo duas pilhas em um mesmo vetor (Fig. 2):
pilha 1: cresce da esquerda para a direita (topo1 = -2 (vazio a esquerda))
pilha 2: cresce da direita para a esquerda (topo2 = tamVetor (vazio a esquerda))

I) Inicialização (durante a criação) dos topos das pilhas como topo1 = -1 e topo2 = tamVetor;

II) Todas as alocações de memória são realizadas na criação;
(instanciar e alocar todos os nodos pela main)

III) As pilhas concorrem livremente pelo espaço no vetor, crescendo em direções opostas sem
sobreposição de uma na outra.

Operacoes:
    1   Criacao (instanciacao)
    2   Destruicao (remocao da memoria)
    3   Reinicializao de uma pilha-alvo
    4   Empilhamento de uma pilha-alvo
    5   Testar se a pila esta cheia
    6   Testar se a pilha esta vazia
    7   Buscar o topo da pilha
    8   Calcular o numero de elementos de uma pilha

    VERIFICACAO DE HTML

Cada tag deve possuir as suas tags internas completamente contidas nela. Ou seja, dentro de uma tag,
caso outra tag for aberta, esta deve ser fechada dentro desta tag superior e nao depois do fim de
seu corpo.

*/

int main(){
    descMP *descritor=NULL;
    
    int ans=1;

    char *menu =
        "Digite o indice correspondente ah operacao abaixo:\
        \n1 - Criar descritor da MpE com 2 pilhas;\
        \n2 - Remover MPE criada;\
        \n3 - Reiniciar pilha;\
        \n4 - Empilhar pilha;\
        \n5 - Desempilhar pilha;\
        \n6 - Verificar se a pilha estah cheia;\
        \n7 - Verificar se a pilha estah vazia;\
        \n8 - Buscar topo da pilha;\
        \n9 - Calcular tamanho da pilha\
        \n10 - Mostrar MPE;\
        \n11 - Verificar estrutura de arquivo HTML;\
        \n12 - Sair.";
        
        printf("\n%s\n", menu);
        while(1){
        printf("\n >> ");
        scanf("%d", &ans);

        // Criar MpE.
        if(ans == 1){
            if(!descritor){
                int tamVet;
                
                printf("Digite a quantidade total de nodos da MPE: ");
                scanf("%d", &tamVet);

                if(tamVet > 0){
                    descritor = criarDescMP(descritor, tamVet);
                    
                    if(descritor){
                        printf("Descritor criado com sucesso.\n");
                    }
                    else{
                        printf(" Nao foi possivel criar o descritor.\n");
                    }
                }
                else{
                    printf(" Digite um numero maior que 0.\n");
                }
            }
            else{
                printf(" Descritor jah criado.\n");
            }
        }

        // Remover MPE.
        else if(ans == 2){
            if(descritor){
                descritor = destruirDescMP(descritor);

                if(!descritor){
                    printf("Fila removida com sucesso.\n");
                }
                else{
                    printf(" Nao foi possivel remover a pilha.\n");
                }
            }
            else{
                printf(" Descritor nao criado.\n");
            }
        }

        // Reiniciar uma das pilhas de MPE.
        else if(ans == 3){
            if(descritor){
                if(descritor->topo1 != -1 || descritor->topo2 != descritor->tamVet){

                    int pilha;

                    printf("Deseja reiniciar qual pilha? (0 para a direta e 1 para a inversa): ");
                    scanf("%d", &pilha);

                    if(reiniciarPilha(descritor, pilha ? PILHA_INVERSA : PILHA_DIRETA)){
                        printf("Pilha reiniciada com sucesso.\n");
                    }
                    else{
                        printf(" Nao foi possivel reiniciar a pilha");
                    }
                }
                else{
                    printf(" A MPE estah vazia.");
                }
            }
            else{
                printf(" Descritor nao criado.");
            }
        }

        // Empilhar uma das pilhas de MPE.
        else if(ans == 4){
            if(descritor){
                if(descritor->topo1 + 1 < descritor->topo2){
                    
                    info *dados = (info *) malloc(sizeof(info));
                    if(!dados){
                        printf(" Nao foi possivel alocar memoria para os dados do nodo.");
                    }
                    
                    int pilha, num;
                    
                    // Insercao de dados no novo nodo.
                    printf("\nDigite o numero do nodo a ser empilhado: ");
                    scanf("%d", &num);

                    dados->num = num;
                    
                    printf("Deseja empilhar em qual sentido? (0 para direto e 1 para inverso): ");
                    scanf("%d", &pilha);
                    
                    if(empilhar(descritor, dados, pilha ? PILHA_INVERSA : PILHA_DIRETA)){
                        printf("Pilha empilhada com sucesso.\n");
                    }
                    else{
                        printf(" Nao foi possivel empilhar.");
                    }
                }
                else{
                    printf(" A MPE estah cheia.");
                }
            }
            else{
                printf(" Descritor nao criado.");
            }
        }

        // Desempilhar uma das pilhas de MPE.
        else if(ans == 5){
            if(descritor){
                if(descritor->topo1 != -1 || descritor->topo2 != descritor->tamVet){
                    
                    int pilha;
                    
                    printf("Deseja desempilhar em qual sentido? (0 para direto e 1 para inverso): ");
                    scanf("%d", &pilha);
                    
                    if(desempilhar(descritor, pilha ? PILHA_INVERSA : PILHA_DIRETA)){
                        printf("Pilha desempilhada com sucesso.\n");
                    }
                    else{
                        printf(" Nao foi possivel desempilhar.");
                    }
                }
                else{
                    printf(" A MPE estah vazia.");
                }
            }
            else{
                printf(" Descritor nao criado.");
            }
        }

        /*
            Verificar se MPE estah cheia. Aqui se verifica a condicao de toda a
            MPE, pois, uma vez que quaisquer uma das pilhas direta ou inversa
            estiver cheia, logo todo o vetor estarah cheio.
        */
        else if(ans == 6){
            if(descritor){
                if(descritor->topo1 = 1 >= descritor->topo2){
                    printf("A MPE estah cheia.\n");
                }
                else{
                    printf("A MPE ainda nao estah cheia.\n");
                }
            }
            else{
                printf(" Descritor nao criado.");
            }
        }

        // Verificar se uma das pilhas de MPE estah vazia.
        else if(ans == 7){
            if(descritor){

                int pilha;

                printf("Digite o numero referente ah pilha para verificar se ela estah vazia (0 para direta e 1 para inversa): ");
                scanf("%d", &pilha);

                pilha = pilha ? PILHA_INVERSA : PILHA_DIRETA;

                if(pilha == PILHA_DIRETA && descritor->topo1 == -1){
                    printf("A pilha do sentido DIRETO estah vazia.\n");
                }
                else if(pilha == PILHA_DIRETA && descritor->topo2 == descritor->tamVet){
                    printf("A pilha do sentido INVERSO estah vazia.\n");
                }
                else{
                    printf("A pilha nao estah vazia.");
                }
            }
            else{
                printf(" Descritor nao criado.");
            }
        }

        // Buscar topo de uma das pilhas de MPE.
        else if(ans == 8){
            if(descritor){

            }
            else{
                printf(" Descritor nao criado.");
            }
        }

        // Calcular tamanho de uma das pilhas de MPE.
        else if(ans == 9){
            if(descritor){

            }
            else{
                printf(" Descritor nao criado.");
            }
        }

        // Mostrar MPE.
        else if(ans == 10){
            if(descritor){
                printarMP(descritor);
            }
            else{
                printf(" Descritor nao criado.\n");
            }
        }

        // Analise de HTML.
        else if(ans == 11){

        }

        // Sair do menu.
        else if(ans == 12){
            printf("\n Saindo...\n");
            break;
        }

        // Caso tenha sido digitado uma opcao invalida.
        else{
            printf(" Digite um opção valida.\n");
        }
    }
    
    return 0;
}
