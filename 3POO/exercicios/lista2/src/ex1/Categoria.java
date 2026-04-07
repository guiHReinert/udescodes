package ex1;

import java.util.ArrayList;

public class Categoria {
    private String nome; // No plural
    private int idadeMinima;
    private int idadeMaxima;
    private ArrayList<Pessoa> pessoas = new ArrayList<Pessoa>();

    public Categoria(String nome, int idadeMinima) {
        this.nome = nome.substring(0, 1).toUpperCase() + nome.substring(1).toLowerCase();
        this.idadeMinima = idadeMinima;
    }

    public Categoria(String nome, int idadeMinima, int idadeMaxima) {
        this.nome = nome.substring(0, 1).toUpperCase() + nome.substring(1).toLowerCase();
        this.idadeMinima = idadeMinima;
        this.idadeMaxima = idadeMaxima;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome.substring(0, 1).toUpperCase() + nome.substring(1).toLowerCase();
    }

    public int getIdadeMinima() {
        return idadeMinima;
    }

    public void setIdadeMinima(int idadeMinima) {
        this.idadeMinima = idadeMinima;
    }

    public int getIdadeMaxima() {
        return idadeMaxima;
    }

    public void setIdadeMaxima(int idadeMaxima) {
        this.idadeMaxima = idadeMaxima;
    }

    public void clearPessoas() {
        pessoas.clear();
    }

    public void cadastrarPessoa(Pessoa pessoa) {
        if (idadeMaxima != 0) {
            if (pessoa.getIdade() >= idadeMinima && pessoa.getIdade() <= idadeMaxima) {
                pessoas.add(pessoa);
            }
        } else {
            if (pessoa.getIdade() >= idadeMinima) {
                pessoas.add(pessoa);
            }
        }
        pessoas.sort((p1, p2) -> p1.getNome().compareTo(p2.getNome()));
    }

    public void mostrarCategoria() {
        if (idadeMaxima != 0) {
            System.out.printf(nome + " de " + idadeMinima + " a " + idadeMaxima + " anos:\n");
        } else {
            System.out.printf(nome + " de " + idadeMinima + " anos ou mais:\n");
        }
        for (Pessoa pessoa : pessoas) {
            System.out.printf(" - " + pessoa.toString());
        }
        System.out.println("");
    }

}
