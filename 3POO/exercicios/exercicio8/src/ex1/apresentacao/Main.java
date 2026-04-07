package ex1.apresentacao;

import ex1.dados.Pessoa;
import ex1.negocio.Sistema;

import java.util.Scanner;

public class Main {
    private static Sistema sistema = new Sistema();
    private static Scanner escaninho = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int ans = -1;

        while (ans != 0) {
            printarMenu();
            ans = Integer.parseInt(escaninho.nextLine());

            if (ans == 0) {
                System.out.println(" Volte sempre!");
            } else if (ans == 1) {
                sistema.adicionarPessoa(cadastrarPessoa());
            } else if (ans == 2) {
                sistema.removerPessoa(escolherPessoa());
            } else if (ans == 3) {
                mostrarPessoas();
            } else {
                System.out.println(" Opcao invalida.");

            }
        }
    }

    public static void printarMenu() {
        System.out.println("Escolha uma opcao abaixo:");
        System.out.println("0 - Sair");
        System.out.println("1 - Cadastrar uma pessoa");
        System.out.println("2 - Remover uma pessoa");
        System.out.println("3 - Mostrar todas as pessoas");
    }

    public static Pessoa cadastrarPessoa() {
        Pessoa pessoa = new Pessoa();

        System.out.printf("Digite o nome: ");
        pessoa.setNome(escaninho.nextLine());

        System.out.printf("Digite a idade: ");
        pessoa.setIdade(Integer.parseInt(escaninho.nextLine()));

        System.out.printf("Digite a altura: ");
        pessoa.setAltura(Float.parseFloat(escaninho.nextLine()));

        System.out.printf("Digite a massa: ");
        pessoa.setMassa(Float.parseFloat(escaninho.nextLine()));

        System.out.println("Pessoa cadastrada com sucesso.");
        return pessoa;
    }

    // Utilizada no lugar de <removerPessoa>, presente no diagrama UML do exemplo
    private static Pessoa escolherPessoa() {
        mostrarPessoas();

        System.out.printf("Escolha uma pessoa: ");
        int ans = Integer.parseInt(escaninho.nextLine());

        if (ans < sistema.getList().size()) {
            System.out.println("Pessoa removida com sucesso.");
            return sistema.getList().get(ans);
        } else {
            System.out.println(" Pessoa nao encontrada.");
            return null;
        }
    }

    public static void mostrarPessoas() {
        for (int c = 0; c < sistema.getList().size(); c++) {
            System.out.println("Pessoa " + c + ": " + sistema.getList().get(c).toString());
        }
    }
}
