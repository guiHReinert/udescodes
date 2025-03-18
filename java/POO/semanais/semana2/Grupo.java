package semana2;

public class Grupo {

    private Pessoa pessoas = new Pessoa[7];
    private int numPessoas = 0;

    public void newPessoa(Pessoa p){
        if(numPessoas < 7){
            pessoas[numPessoas] = p;
            numPessoas++;
        }
    }

    public void arrange(){

    }

}
