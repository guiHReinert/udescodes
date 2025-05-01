package ex1;

public class Pessoa {
    private String nome;
    private int idade;
    private long cpf;
    private String cidade;

    public Pessoa() {
        this.nome = "";
        this.idade = 0;
        this.cpf = 0;
        this.cidade = "";
    }

    public Pessoa(String nome, int idade, long cpf, String cidade) {
        this.nome = nome;
        this.idade = idade;
        this.cpf = cpf;
        this.cidade = cidade;
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

    public long getCpf() {
        return cpf;
    }

    public void setCpf(long cpf) {
        this.cpf = cpf;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    @Override
    public String toString() {
        return nome + ", " + idade + ", " + cpf + ", " + cidade + '\n';
    }
}
