package ex1.classes;

public class Sapo extends Animal {
    public Sapo(String nome) {
        this.nome = nome;
    }

    @Override
    public String emitirSom() {
        return "croac";
    }
}
