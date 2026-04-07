package ex2.apresentacao;

import ex2.dados.Contato;
import ex2.negocio.ListaTelefonica;

import java.util.Scanner;
import java.util.Map;
import java.util.List;

public class Main {
    private static Scanner scan = new Scanner(System.in);
    private static ListaTelefonica listaTel = new ListaTelefonica();

    public static void main(String[] args) {
        int ans = 0;
        while (true) {
            ans = menu();
            if (ans == 1) {
                adicionarContato();
            } else if (ans == 2) {
                removerContato();
            } else if (ans == 3) {
                exibirContatos();
            } else if (ans == 4) {
                System.out.printf("Digite a inicial dos contatos a serem mostrados: ");
                exibirContatos(scan.nextLine().charAt(0));
            } else if (ans == 5) {
                System.out.printf(" Volte sempre!\n");
                break;
            } else {
                System.out.printf(" Por favor, digite um indice valido.\n");
            }

        }
    }

    public static int menu() {
        System.out.println("\n                    EXERCICIO 5");
        System.out.println(" Selecione abaixo o indice referente a opcao desejada:");
        System.out.println("1 - Adicionar contato");
        System.out.println("2 - Excluir contato");
        System.out.println("3 - Listar contatos");
        System.out.println("4 - Exibir contatos com uma inicial em especifico");
        System.out.println("5 - Sair do sistema");
        return Integer.parseInt(scan.nextLine());
    }

    public static Contato novoContato() {
        Contato contato = new Contato();
        System.out.printf("Digite o nome do novo contato:\n");
        contato.setNome(scan.nextLine());
        System.out.println("Digite o numero de telefone de " + contato.getNome() + ':');
        contato.setTelefone(Integer.parseInt(scan.nextLine()));
        return contato;
    }

    public static void adicionarContato() {
        Contato contato = novoContato();
        listaTel.adicionarContato(contato);
        System.out.printf("Novo contato adicionado com sucesso.\n");
    }

    public static void removerContato() {
        Character inicial;
        System.out.printf("Digite a inicial do contato a ser removido: ");
        inicial = scan.nextLine().charAt(0);
        List<Contato> lista = listaTel.buscarContatos(inicial);
        System.out.println("");
        if (lista.isEmpty()) {
            System.out.printf(" Nao ha contatos com a letra " + Character.toUpperCase(inicial) + ".\n");
        } else {

            for (int c = 0; c < lista.size(); c++) {
                System.out.printf(c + " - " + lista.get(c).toString());
            }

            System.out.printf("\nDigite o indice respectivo ao contato a ser removido:");
            listaTel.removerContato(lista.get(Integer.parseInt(scan.nextLine())));
            System.out.printf("Contato removido com sucesso!\n");

        }
    }

    public static void exibirContatos() {
        System.out.println("");
        Map<Character, List<Contato>> contatos = listaTel.listarContatos();
        contatos.forEach((carac, lista) -> {
            System.out.printf(carac + ":\n");
            for (Contato contato : lista) {
                System.out.printf("- " + contato.getNome() + ": " + contato.getTelefone() + '\n');
            }
        });
    }

    public static void exibirContatos(char letra) {
        List<Contato> lista = listaTel.buscarContatos(letra);
        System.out.println("");
        if (lista.isEmpty()) {
            System.out.printf(" Nao ha contatos com a letra " + Character.toUpperCase(letra) + ".\n");
        } else {
            for (int c = 0; c < lista.size(); c++) {
                System.out.printf("- " + lista.get(c).toString());
            }
        }
    }
}