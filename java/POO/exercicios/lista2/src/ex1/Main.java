package ex1;

import java.util.Scanner;

import java.util.ArrayList;

import java.io.File;
import java.io.Writer;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {
    private static ArrayList<Categoria> categorias = new ArrayList<Categoria>();
    private static ArrayList<Pessoa> pessoas = new ArrayList<Pessoa>();

    public static void main(String[] args) {
        categorias.add(new Categoria("Criancas", 1, 12));
        categorias.add(new Categoria("Adolescentes", 13, 18));
        categorias.add(new Categoria("Jovens", 19, 25));
        categorias.add(new Categoria("Adultos", 26, 59));
        categorias.add(new Categoria("Idosos", 60));

        Scanner scan = new Scanner(System.in);
        int ans = 0;
        while (true) {
            System.out.printf("Digite -1 para sair, ou qualquer outro numero para cadastrar uma nova pessoa: ");
            ans = Integer.parseInt(scan.nextLine());
            if (ans == -1) {
                break;
            } else {
                Pessoa pessoa = new Pessoa();

                System.out.printf("Digite o nome da pessoa: ");
                pessoa.setNome(scan.nextLine());
                System.out.printf("Digite a idade da pessoa: ");
                pessoa.setIdade(Integer.parseInt(scan.nextLine()));
                System.out.printf("Digite o CPF da pessoa: ");
                pessoa.setCpf(Long.parseLong(scan.nextLine()));
                System.out.printf("Digite a cidade da pessoa: ");
                pessoa.setCidade(scan.nextLine());

                try {
                    registrarPessoa(pessoa);
                    pessoas.clear();
                    pessoas = lerArquivo();
                    categorizarPessoas();
                    mostrarCategorias();
                } catch (IOException ex) {
                    System.out.printf(" Nao foi possivel registrar a pessoa: " + ex.getMessage());
                }
            }
        }
    }

    public static ArrayList<Pessoa> lerArquivo() {
        Scanner scan;
        try {
            scan = new Scanner(new File("src/ex1/pessoas.txt"));
            ArrayList<Pessoa> personas = new ArrayList<Pessoa>();
            while (scan.hasNextLine()) {
                String line = scan.nextLine();

                String[] raw = line.split(", ");
                String nome = raw[0];
                int idade = Integer.parseInt(raw[1]);
                long cpf = Long.parseLong(raw[2]);
                String cidade = raw[3];

                Pessoa pessoa = new Pessoa(nome, idade, cpf, cidade);
                personas.add(pessoa);
            }
            scan.close();
            return personas;
        } catch (FileNotFoundException ex) {
            System.out.printf(" Nao foi possivel encontrar o arquivo.\n");
            return null;
        }
    }

    public static void registrarPessoa(Pessoa pessoa) throws IOException {
        Writer wry = new FileWriter("src/ex1/pessoas.txt", true);
        BufferedWriter wryy = new BufferedWriter(wry);
        wryy.write(pessoa.toString());
        wryy.close();
    }

    private static void categorizarPessoas() {
        if (!pessoas.isEmpty()) {
            for (Categoria categoria : categorias) {
                categoria.clearPessoas();
                for (Pessoa pessoa : pessoas) {
                    categoria.cadastrarPessoa(pessoa);
                }
            }
        }
    }

    private static void mostrarCategorias() {
        System.out.println("");
        for (Categoria categoria : categorias) {
            categoria.mostrarCategoria();
        }
    }

}