package ex2;

public class Processo {
    private int id;
    private String nome;

    public Processo(){}

    public Processo(int id){
        this.id = id;
    }

    public Processo(int id, String nome){
        this.id = id;
        this.nome = nome;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
}
