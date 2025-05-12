package ex1.classes;

public class Cobra extends Animal {
    public Cobra(String nome) {
        this.nome = nome;
    }

    @Override
    public String emitirSom() {
        return "SsSsSs";
    }
}
