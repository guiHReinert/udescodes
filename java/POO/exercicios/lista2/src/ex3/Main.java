package ex3;

import ex2.Matriz;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Matriz<Integer> matrix = new Matriz<Integer>(5, 5);
        int ans = 0, i = 0, j = 0;
        while (i < 5) {
            System.out.printf("Digite um número inteiro para a posicao (%d,%d): ", i, j);
            ans = Integer.parseInt(scan.nextLine());
            if (ans == -1) {
                break;
            } else {
                matrix.set(ans, i, j);
            }

            j++;
            if (j % 5 == 0) {
                j = 0;
                i++;
            }
        }
        scan.close();

        System.out.printf("Menor valor da matriz: " + menorElemento(matrix) + "\n");
    }

    // Para matrizes formadas com inteiros
    public static int menorElemento(Matriz<Integer> matrix) {
        int menor = 0;
        for (Matriz.Quadrante quadrante : Matriz.Quadrante.values()) {
            ArrayList<Integer> elementos = matrix.getElementosQuadrante(quadrante);
            if (quadrante == Matriz.Quadrante.PRIMEIRO) {
                menor = elementos.get(0);
            }
            for (int i = 0; i < elementos.size(); i++) {
                if (elementos.get(i) != null) {
                    if (elementos.get(i) < menor) {
                        menor = elementos.get(i);
                    }
                } else {
                    return menor;
                }
            }
        }
        return menor;
    }
}