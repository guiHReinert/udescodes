package ex2.classes;

public class Veterinario {
    private static final int maxAnimais = 7; // numero maximo permitido
    private String nome;
    private float salario;
    private Endereco endereco;
    private Animal[] animais = new Animal[maxAnimais];
    private int numAnimais; // numero atual de animais

    public static int getMaxAnimais() {
        return maxAnimais;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String n) {
        nome = n;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float s) {
        salario = s;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public void setEndereco(Endereco e) {
        endereco = e;
    }

    public void novoAnimal(Animal anim) {
        if (numAnimais < maxAnimais) {
            animais[numAnimais] = anim;
            numAnimais++;
        } else {
            System.out.println("Quantidade maxima de animais atingida.\n");
        }
    }

    public Animal[] getAnimais() {
        return animais;
    }

    public int getNumAnimais() {
        return numAnimais;
    }

    public void setNumAnimais(int n) {
        numAnimais = n;
    }

    public String toString() {
        if (endereco != null) {
            return "Nome: " + nome + "\nSalario: " + salario + "\nEndereco: " + endereco;
        } else {
            return "Nome: " + nome + "\nSalario: " + salario;
        }
    }

}