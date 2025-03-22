package classes;

public class Dono{
    private String nome;
    private Endereco endereco;
    private String cpf;

    public String getNome(){
        return nome;
    }
    public void setNome(String n){
        nome = n;
    }

    public Endereco getEndereco(){
        return endereco;
    }
    public void setEndereco(Endereco e){
        endereco = e;
    }

    public String getCPF(){
        return cpf;
    }
    public void setCPF(String c){
        cpf = c;
    }
}