package ex3;

import ex3.classes.Digrafo;
import ex3.classes.Grafo;

public class Main{
    public static void main(String[] args){
        Digrafo digrafo = new Digrafo();
        Grafo grafo = new Grafo();

        for(int i = 0; i < 5; i++){
            digrafo.adicionarVertice();
            grafo.adicionarVertice();
        }

        grafo.adicionarAresta(0, 1);
        grafo.adicionarAresta(0, 2);

        grafo.adicionarAresta(1, 0);
        grafo.adicionarAresta(1, 1);
        grafo.adicionarAresta(1, 2);
        grafo.adicionarAresta(1, 3);
        grafo.adicionarAresta(1, 4);

        grafo.adicionarAresta(2, 0);
        grafo.adicionarAresta(2, 1);
        grafo.adicionarAresta(2, 3);

        grafo.adicionarAresta(3, 1);
        grafo.adicionarAresta(3, 2);
        grafo.adicionarAresta(3, 4);

        grafo.adicionarAresta(4, 1);
        grafo.adicionarAresta(4, 3);

        System.out.println("Grafo:\n" + grafo);

        digrafo.adicionarAresta(0, 1);
        digrafo.adicionarAresta(0, 2);

        digrafo.adicionarAresta(1, 1);
        digrafo.adicionarAresta(1, 3);

        digrafo.adicionarAresta(2, 0);
        digrafo.adicionarAresta(2, 1);
        digrafo.adicionarAresta(2, 3);

        digrafo.adicionarAresta(3, 4);

        digrafo.adicionarAresta(4, 1);

        System.out.println("Digrafo:\n" + digrafo);
    }
}