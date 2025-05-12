package ex3;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class Digrafo{
    protected Map<Integer, List<Integer>> matrizAdjacencia = new HashMap<>();

    public void adicionarVertice(){
        matrizAdjacencia.put(matrizAdjacencia.keySet().size(), new ArrayList<>());
    }

    public void adicionarAresta(int origem, int destino){
        if(matrizAdjacencia.containsKey(origem) && matrizAdjacencia.containsKey(destino)){
            matrizAdjacencia.get(origem).set(destino, 1);
        }
    }

    @Override
    public String toString(){
        StringBuffer str = new StringBuffer();
        matrizAdjacencia.forEach((key, list) -> {
            str.append(key + ": ");
            list.forEach(value -> {
                str.append(value + ' ');
            });
            str.append('\n');
        }); 
        return str.toString();
    }
}
