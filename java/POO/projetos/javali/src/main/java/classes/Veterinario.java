package classes;

public class Veterinario{
    private String nome;
    private float salario;
    private Endereco endereco;
    private Animal[] animais;
    private int numAnimais; // numero atual de animais
    private final int maxAnimais = 7; // numero maximo permitido

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

    public Endereco getEndereco(){
        return endereco;
    }
    public void setEndereco(Endereco e){
        endereco = e;
    }

    public void newAnimal(Animal anim){
        if(numAnimais < maxAnimais){
            animais[numAnimais] = anim;
            numAnimais++;
        }
        else{System.out.println("Quantidade maxima de animais atingida.\n");}
    }

    public int getNumAnimais(){
        return numAnimais;
    }
    public void setNumAnimais(int n){
        numAnimais = n;
    }

}