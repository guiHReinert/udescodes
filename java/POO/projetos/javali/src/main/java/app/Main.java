package app;

import java.util.Scanner;

import classes.SistemaPetShop;

public class Main{
    public static void main(String[] args){
        Scanner inputer = new Scanner(System.in);
        SistemaPetShop petShop = new SistemaPetShop();

        int ans;
        String tempNome;
        float tempSalario;

        System.out.println("                    JAVALI                    ");
        System.out.println("Digite o indice respectivo a opção do menu abaixo:");
        System.out.println("1 - Cadastrar novo veterinario.");
        System.out.println("2 - Mostrar os veterinarios registrados.");
        System.out.println("3 - Cadastrar endereco de veterinario.");
        System.out.println("4 - Cadastrar novo animal.");
        System.out.println("5 - Mostrar os animais registrados.");
        System.out.println("6 - Cadastrar novo dono do JAVALI.");
        System.out.println("7 - Cadastrar endereco do dono.");
        System.out.printf(" >> ");
        ans = Integer.parseInt(inputer.nextLine());

        // Cadastrar novo veterinario
        if(ans==1){
            System.out.printf("Nome do novo veterinario:\n >> ");
            tempNome = inputer.nextLine();
            System.out.printf("Salario de %s:\n >> ", tempNome);
            tempSalario = Float.parseFloat(inputer.nextLine());
            petShop.cadastrarVeterinario(tempNome, tempSalario);
        }
        // Mostrar os veterinarios
        else if (ans==2) {
            petShop.mostrarVeterinarios();
        }
        else{System.out.printf("Digite um numero adequado.");}
    }
}
