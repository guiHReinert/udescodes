package ex2.dados;

import java.util.ArrayList;

public class Viveiro {
    protected String nome;
    protected float comprimento;
    protected float largura;
    protected ArrayList<Animal> animais;

    public float calculaEspaco() {
        return comprimento * largura;
    }

    private float espacoOcupado() {
        float sum = 0;
        for (Animal a : animais) {
            sum += a.calculaEspacoOcupado();
        }
        return sum;
    }

    public float espacoDisponivel() {
        return calculaEspaco() - espacoOcupado();
    }

    public boolean adicionarAnimal(Animal animal) {
        if(animal instanceof Animal && espacoOcupado() / calculaEspaco() <= 0.7){
            animais.add(animal);
            return true;
        } else {
            return false;
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public float getComprimento() {
        return comprimento;
    }

    public void setComprimento(float comprimento) {
        this.comprimento = comprimento;
    }

    public float getLargura() {
        return largura;
    }

    public void setLargura(float largura) {
        this.largura = largura;
    }

    public ArrayList<Animal> getAnimais() {
        return animais;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Viveiro other = (Viveiro) obj;
        if (nome == null) {
            if (other.nome != null)
                return false;
        } else if (!nome.equals(other.nome))
            return false;
        if (Float.floatToIntBits(comprimento) != Float.floatToIntBits(other.comprimento))
            return false;
        if (Float.floatToIntBits(largura) != Float.floatToIntBits(other.largura))
            return false;
        if (animais == null) {
            if (other.animais != null)
                return false;
        } else if (!animais.equals(other.animais))
            return false;
        return true;
    }

    public String toString(){
        String animaisStr = new String();
        for(Animal animal : animais){
            animaisStr += '\n' + animal.toString();
        }
        
        return "Nome: " + nome +
        "\nComprimento: " + comprimento +
        "\nLargura: " + largura +
        animaisStr +'\n';
    }
}
