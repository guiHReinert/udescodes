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
        else{
            throw new PilhaCheiaException();
        }
    }

    public T remover() throws PilhaVaziaException{
        if(elementos.size() > 0){
            T objeto = elementos.get(elementos.size() - 1);
            elementos.remove(objeto);
            return objeto;
        }
        else{
            throw new PilhaVaziaException();
        }
    }

    public int getSize(){
        return elementos.size();
    }

    public int getLimite() {
        return limite;
    }

    public void setLimite(int limite) {
        this.limite = limite;
    }

    public List<T> getElementos() {
        return elementos;
    }

    public void setElementos(List<T> elementos) {
        this.elementos = elementos;
    }
}
