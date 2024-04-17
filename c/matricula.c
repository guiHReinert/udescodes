#include <stdio.h>
#include <string.h>

char fase, curso[2], ansVal, valAGT, valTGS,
ansALI, ansGAN, ansCDI, valCDI, ansICD,  ansECC;
int credit, discip;

int main(){
    printf("Digite o curso: ");
    scanf("%s", curso);

    if(strcmp(curso, "CC") == 0){
    printf("Qual sua fase? ");
    scanf(" %c", &fase);
        switch(fase){
            case '1':
                printf("Tentar validação?   ");
                scanf(" %c", &ansVal);
                if(ansVal == 'S'){
                    printf("***Vai validar AGT? ");
                    scanf(" %c", &valAGT);
                    printf("***Vai validar TGS? ");
                    scanf(" %c", &valTGS);
                }
                printf("\nMatricula compulsoria em:");
                printf("\nPrimeira fase----Cred.Teo------Cred.Prat--------");
                printf("\nAGT0001           02            02");
                printf("\nGAN0001           04");
                printf("\nICD0001           04");
                printf("\nLMA0001           02            02");
                printf("\nPFN0001");
                printf("\nTGS0001           02            02");
                printf("\n\nTotal de creditos: 24");
                printf("\nTotal de disciplinas: 6");
                printf("\nPedidos de validação:");
                if(valAGT == 'S'){
                    printf("\n AGT");
                }
                if(valTGS == 'S'){
                    printf("\n TGS");
                }
            break;
            case '2':
                printf("Vai fazer ALI?      ");
                scanf(" %c", &ansALI);
                if(ansALI == 'S'){
                    printf("***Ja fez GAN?      ");
                    scanf(" %c", &ansGAN);
                }
                printf("Vai fazer CDI?      ");
                scanf(" %c", &ansCDI);
                if(ansCDI == 'S'){
                    printf("***Ja fez ICD?      ");
                    scanf(" %c", &ansICD);
                }
                if(ansCDI != 'S'){
                    printf("***Vai validar CDI? ");
                    scanf(" %c", &valCDI);
                }
                printf("Vai fazer ECC?      ");
                scanf(" %c", &ansECC);
                if(ansGAN == 'S'){
                    discip++;
                    credit += 4;
                }
                if(ansICD == 'S'){
                    discip++;
                    credit += 4;
                }
                if(ansECC == 'S'){
                    discip++;
                    credit += 4;
                }
                printf("\nMatricula compulsoria em:");
                printf("\nPrimeira fase----Cred.Teo------Cred.Prat--------Pré-requisitos--------");
                printf("\nALI0001           04            00               GAN0001");
                printf("\nCDI0001           04            00               ICD0001");
                printf("\nECC0001           02            02");
                if(discip > 0){
                    printf("\nTotal de creditos: %d", credit);
                    printf("\nTotal de disciplinas: %d", discip);
                    printf("\nPedidos de validação:");
                    if(valCDI == 'S'){
                        printf("\n CDI");
                    }
                }else{
                    printf("\nSua matrícula vai constar como trancada. É preciso escolher ao menos uma disciplina.");    
                    printf("\n\nTotal de creditos: 0");
                    printf("\nTotal de disciplinas: 0");
                }
            break;
            default:
                printf("Por favor, digite a fase corretamente.");
        }
        printf("\n");
    }

    return 0;
}