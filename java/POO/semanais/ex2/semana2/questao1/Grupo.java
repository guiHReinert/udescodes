package ex2.semana2.questao1;

import java.util.Arrays;

public class Grupo {
    private final int MAX = 7;

    private Pessoa pessoas[] = new Pessoa[this.MAX];
    private float IMCs[] = new float[this.MAX];
    private int numPessoas = 0;

    public void newPessoa(Pessoa p){
        if(numPessoas < 7){
            pessoas[numPessoas++] = p;
        }
        else{System.out.println("Numero maximo de pessoas alcancado.\n");}
    }

    public void arrange(){
        for(int j=0; j<this.numPessoas; j++){
            this.IMCs[j] = this.pessoas[j].getIMC();
        }
        Arrays.sort(this.IMCs);
    }

}
