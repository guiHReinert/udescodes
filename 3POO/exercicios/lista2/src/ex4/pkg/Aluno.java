package ex4.pkg;

import java.util.ArrayList;

public class Aluno {
    private String nome;
    private int idade;
    private ArrayList<Double> notas;

    public Aluno(String nome, int idade, ArrayList<Double> notas){
        this.nome = nome;
        this.idade = idade;
        this.notas = new ArrayList<Double>(notas);
    }

    public Double calcularMedia(){
        double sum = 0;
        for(Double nota : notas){
            sum += nota;
        }
        return sum / notas.size();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public ArrayList<Double> getNotas() {
        return notas;
    }

    public void setNotas(ArrayList<Double> notas) {
        this.notas = notas;
    }

    @Override
    public String toString() {
        return nome + ", "  + idade + ", " + notas + "\n";
    }
}
