package ex1.classes;

public abstract class Animal {
    protected String nome;

    public abstract String emitirSom();

    @Override
    public String toString() {
        return nome + ": " + emitirSom();
    }
}
