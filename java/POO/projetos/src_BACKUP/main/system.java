package main;

import classes;
import java.util.Scanner;

public class system{
    public static void main(String[] args){
        Scanner escaninho = new Scanner(System.in);

        int ans=0;

        System.out.println("    JAVALI  ");
        System.out.println(" Digite o indice respectivo a opção do menu abaixo:");
        System.out.println("1 - Cadastrar novo veterinario.");
        System.out.println("2 - Mostrar os veterinarios registrados.");
        System.out.println("3 - Cadastrar endereco de veterinario.");
        System.out.println("4 - Cadastrar novo animal.");
        System.out.println("5 - Mostrar os animais registrados.");
        System.out.println("6 - Cadastrar novo dono do JAVALI.");
        System.out.println("7 - Cadastrar endereco do dono.\n >> ");
        ans = escaninho.nextInt();

        if(ans==1){
            
        }
    }
}
