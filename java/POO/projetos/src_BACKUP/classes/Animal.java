package classes;

public class Animal {
    
    private String nome;
    private Dono dono;
    private String cpf;
    private String descricao;

    public String getNome(){
        return nome;
    }
    public void setNome(String n){
        nome = n;
    }

    public Dono getDono(){
        return dono;
    }
    public void setDono(Dono d){
        dono = d;
    }

    public String getCPF(){
        return cpf;
    }
    public void setCPF(String c){
        cpf = c;
    }

    public String getDescricao(){
        return descricao;
    }
    public void setDescricao(String d){
        descricao = d;
    }
}
