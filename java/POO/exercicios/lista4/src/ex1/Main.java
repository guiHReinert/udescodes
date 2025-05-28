package ex1;

import java.util.List;
import java.util.ArrayList;

import java.util.Random;

public class Main {
    public static void main(String[] args) throws Exception {
        Random random = new Random();

        List<Integer> lista1 = new ArrayList<>();
        List<Integer> lista2 = new ArrayList<>();

        System.out.printf("\nIndices:\t");
        for(int i=0; i < 10; i++){
            System.out.printf("[%d]\t", i);
            lista1.add(random.nextInt(100));
            lista2.add(random.nextInt(100));
        }

        System.out.printf("\nLista 1:\t");
        lista1.forEach(num -> System.out.printf(num + "\t"));

        System.out.printf("\nLista 2:\t");
        lista2.forEach(num -> System.out.printf(num + "\t"));

        Soma soma = new Soma();
        Multiplicacao multiplicacao = new Multiplicacao();
        MDC mdc = new MDC();
        Mod mod = new Mod();

        System.out.println("\n\nIndice\tSoma\tMultiplicacao\tMDC\tMod");
        for(int i=0; i < 10; i++){
            System.out.printf("[%d]\t%d\t%d\t\t%d\t%d\n",
            i,
            soma.executar(lista1.get(i), lista2.get(i)),
            multiplicacao.executar(lista1.get(i), lista2.get(i)),
            mdc.executar(lista1.get(i), lista2.get(i)),
            mod.executar(lista1.get(i), lista2.get(i))
            );
        }
    }
}
