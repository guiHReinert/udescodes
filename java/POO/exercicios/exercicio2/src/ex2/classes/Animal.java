package ex2.classes;

public class Animal {

    private String nome;
    private Dono dono;
    private String especie;
    private String descricao;

    public String getNome() {
        return nome;
    }

    public void setNome(String n) {
        nome = n;
    }

    public Dono getDono() {
        return dono;
    }

    public void setDono(Dono d) {
        dono = d;
    }

    public String getEspecie() {
        return especie;
    }

    public void setEspecie(String e) {
        especie = e;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String d) {
        descricao = d;
    }

    public String toString() {
        return "Nome: " + nome + "\nEspecie: " + especie + "\nDescricao: " + descricao;
    }
}
