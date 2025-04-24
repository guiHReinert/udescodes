package dados;

import java.util.ArrayList;

public abstract class Gerador {
    protected ArrayList<Integer> sequencia = new ArrayList<Integer>();

    public abstract void gerar(int quantidade);

    public ArrayList<Integer> getSequencia(){
        return this.sequencia;
    }
}
