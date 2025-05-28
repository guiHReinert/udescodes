package ex2;

import java.util.List;
import java.util.ArrayList;

public class Pilha <T>{
    private int limite;
    private List<T> elementos = new ArrayList<T>();

    public Pilha(int limite){
        this.limite = limite;
    }

    public void inserir(T objeto) throws PilhaCheiaException{
        if(elementos.size() < limite){
            elementos.add(objeto);
        }
    }

    public T remover() throws PilhaVaziaException{
        T objeto = elementos.get(elementos.size() - 1);
        elementos.remove(objeto);
        return objeto;
    }

    public int getSize(){
        return elementos.size();
    }
    
}
