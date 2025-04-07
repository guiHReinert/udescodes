package apresentacao;

import dados.Contato;
import negocio.ListaTelefonica;

import java.util.Scanner;
import java.util.List;
import java.util.Map;

public class Main {
    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        menu();
        

    }

    // public Contato novoContato(){

    // }

    public void adicionarContato(){

    }

    public void removerContato(){

    }

    // public exibirContatos(){

    // }

    public void exibirContatos(char letra){

    }

    public static int menu(){
        System.out.println("\n Selecione abaixo o indice referente a opcao desejada:");
        System.out.println("1 - Adicionar contato");
        System.out.println("2 - Excluir contato");
        System.out.println("3 - Listar contatos");
        System.out.println("4 - Excluir contatos com uma inicial em especifico");
        System.out.println("5 - Sair do sistema");
        System.out.printf(" >> ");
        return Integer.parseInt(scan.nextLine());
    }
}