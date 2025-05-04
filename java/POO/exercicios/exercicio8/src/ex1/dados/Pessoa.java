package ex1.dados;

public class Pessoa {
    private String nome;
    private int idade;
    private float massa;
    private float altura;

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

    public float getMassa() {
        return massa;
    }

    public void setMassa(float massa) {
        this.massa = massa;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    @Override
    public boolean equals(Object o) {
        Pessoa p = (Pessoa) (o);
        if (p.getNome() == this.getNome()) {
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return nome + ", " + idade + ", " + massa + "kg, " + altura + "m\n";
    }

}
