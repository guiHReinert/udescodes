package ex2;

import ex2.classes.*;

import java.util.List;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        List<FormaGeometrica> figuras = new LinkedList<>();

        figuras.add(new TrianguloEquilatero(1));
        figuras.add(new TrianguloEquilatero(3));

        figuras.add(new Losango(4, 2));
        figuras.add(new Losango(10, 5));

        figuras.add(new Circulo(1));
        figuras.add(new Circulo(4));

        figuras.forEach(figura -> {
            System.out.println(figura);
        });
    }
}
