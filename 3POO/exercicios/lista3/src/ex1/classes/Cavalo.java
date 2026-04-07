package ex1.classes;

public class Cavalo extends Animal {
    public Cavalo(String nome) {
        this.nome = nome;
    }

    @Override
    public String emitirSom() {
        return "Iiirrrri in in";
    }
}
