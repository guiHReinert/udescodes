package main;

public class Veterinario{
    
    private String nome;
    private float salario;
    private String endereco;
    private String[] animais;
    private int numAnimais;

    public String getNome(){
        return nome;
    }
    public void setNome(String n){
        nome = n;
    }

    public float getSalario(){
        return salario;
    }
    public void setSalario(float s){
        salario = s;
    }

    public String getEndereco(){
        return endereco;
    }
    public void setEndereco(String e){
        endereco = e;
    }

    // Array de animais
    // public String getNome(){
    //     return nome;
    // }
    // public void setNome(String n){
    //     nome = n;
    // }

    public int getNumAimais(){
        return numAnimais;
    }
    public void setNumAnimais(int n){
        numAnimais = n;
    }

}