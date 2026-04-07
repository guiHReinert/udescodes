package ex4.pkg;

public class Equipe <T> extends Turma{
    private String nome;

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString(){
        return nome + '\n';
    }
}
