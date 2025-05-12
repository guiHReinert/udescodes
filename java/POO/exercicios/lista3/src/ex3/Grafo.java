package ex3;

public class Grafo extends Digrafo{
    @Override
    public void adicionarAresta(int origem, int destino){
        if(this.matrizAdjacencia.containsKey(origem) && matrizAdjacencia.containsKey(destino)){
            matrizAdjacencia.get(origem).set(destino, 1);
            matrizAdjacencia.get(destino).set(origem, 1);
        }
    }
}
