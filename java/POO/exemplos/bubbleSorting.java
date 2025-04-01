// Fonte:
// https://www.devmedia.com.br/entendendo-o-algoritmo-bubble-sort-em-java/24812

public class bubbleSorting{
    public static void main(String args[]){
        String[] nomes = {"Juiz Dredd", "Silva", "Batman", "Gadolino", "Amanda"};
        int[] vet = {8, 9, 3, 5, 1};
        String auxS = "";
        int auxN = 0;

        System.out.println("Vetor de numeros desordenado: ");
        for(int i = 0; i<5; i++){
            System.out.printf(" "+vet[i]);
        }
        System.out.printf("\n\n");
        
        System.out.println("Vetor de nomes desordenado: ");
        for(int i = 0; i<5; i++){
            System.out.printf(" "+nomes[i]);
        }
        System.out.printf("\n\n");
        
        // Bubble sorting
        for(int i = 0; i<5; i++){
            for(int j = 0; j<4; j++){
                if(vet[j] > vet[j + 1]){ // Caso o numero seja maior que o seguinte
                    auxN = vet[j];
                    auxS = nomes[j];

                    vet[j] = vet[j+1];
                    nomes[j] = nomes[j+1];

                    vet[j+1] = auxN;
                    nomes[j+1] = auxS;
                }
            }
        }

        System.out.println("Vetor de numeros organizado:");
        for(int i = 0; i<5; i++){
            System.out.printf(" "+vet[i]);
        }
        System.out.printf("\n\n");
        
        System.out.println("Vetor de nomes organizado:");
        for(int i = 0; i<5; i++){
            System.out.printf(" "+nomes[i]);
        }
        System.out.printf("\n");
    }
}