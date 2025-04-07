package ex4Classes;

import java.util.Random;

public class Sorteador {
    private Pessoa[] pessoas = new Pessoa[99];
    private int numPessoas;

    public int getNumPessoas() {
        return numPessoas;
    }

    public Pessoa[] getPessoas() {
        return pessoas;
    }
    public void setPessoas(Pessoa[] pessoas) {
        this.pessoas = pessoas;
        int c, auxC=0;
        // Obter o indice do objeto nao-nulo de posicao mais alta para limitar o alcance do sorteio
        for(c=0; c < pessoas.length; c++){
            if(pessoas[c] != null){
                auxC = c;
            }
        }
        numPessoas = auxC;
    } 

    Pessoa sortearProximo(){
        Random random = new Random();
        Pessoa auxP = null;
        int sorted = random.nextInt(numPessoas);
        for(int j=0; j < pessoas.length; j++){
            if(j == sorted && pessoas[j] != null){
                auxP = pessoas[j];
                pessoas[j] = null;                
            }
        }
        // Atualizar o array <pessoas> para retirar a lacuna da pessoa removida
        Pessoa[] newPessoas = new Pessoa[pessoas.length];
        int pos=0;
        for(int j=0; j < numPessoas; j++){
            if(pessoas[j] != null){
                newPessoas[pos++] = pessoas[j];
            }
        }
        numPessoas--;
        pessoas = newPessoas.clone();
        return auxP;
    }
}
