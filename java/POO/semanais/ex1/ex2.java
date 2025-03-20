package ex1;
import java.util.Scanner;

public class ex2{
    public static void main(String[] args){
        Scanner escaninho = new Scanner(System.in);

        String[] nomes = new String[3];
        int[] ages =  new int[3];
        
        for(int j=0; j<3; j++){
            System.out.format("Digite o nome da %da pessoa:\n >> ", j+1);
            nomes[j] = escaninho.nextLine();
            System.out.format("Digite a idade de %s:\n >> ", nomes[j]);
            ages[j] = escaninho.nextInt();

            escaninho.nextLine();
        }

        // Sort das pessoas pelas suas idades (ordem descrescente)
        

        System.out.println("");
        for(int k=0; k<3; k++){
            System.out.format("%d: %s\nidade: %d\n", k+1, nomes[k], ages[k]);
        }

    }
}