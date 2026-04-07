package ex2;

public class Main {
    public static void main(String[] args) {
        Matriz<Integer> matrix = new Matriz<Integer>(5, 5);
        matrix.set(50, 0, 0);
        matrix.set(43, 0, 1);
        matrix.set(19, 0, 2);
        matrix.set(19, 0, 3);
        matrix.set(41, 0, 4);

        matrix.set(11, 1, 0);
        matrix.set(24, 1, 1);
        matrix.set(72, 1, 2);
        matrix.set(23, 1, 3);
        matrix.set(63, 1, 4);

        matrix.set(26, 2, 0);
        matrix.set(92, 2, 1);
        matrix.set(84, 2, 2);
        matrix.set(49, 2, 3);
        matrix.set(64, 2, 4);

        matrix.set(46, 3, 0);
        matrix.set(52, 3, 1);
        matrix.set(73, 3, 2);
        matrix.set(53, 3, 3);
        matrix.set(91, 3, 4);

        matrix.set(64, 4, 0);
        matrix.set(11, 4, 1);
        matrix.set(93, 4, 2);
        matrix.set(62, 4, 3);
        matrix.set(15, 4, 4);

        System.out.printf("Quadrante 1: %s\n", matrix.getElementosQuadrante(Matriz.Quadrante.PRIMEIRO).toString());
        System.out.printf("Quadrante 2: %s\n", matrix.getElementosQuadrante(Matriz.Quadrante.SEGUNDO).toString());
        System.out.printf("Quadrante 3: %s\n", matrix.getElementosQuadrante(Matriz.Quadrante.TERCEIRO).toString());
        System.out.printf("Quadrante 4: %s\n", matrix.getElementosQuadrante(Matriz.Quadrante.QUARTO).toString());

    }
}
