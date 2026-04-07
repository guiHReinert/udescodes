package ex1;

import ex1.classes.Animal;
import ex1.classes.Cavalo;
import ex1.classes.Cobra;
import ex1.classes.Sapo;

import java.util.List;
import java.util.LinkedList;

public class Main {
   public static void main(String[] args) {
        List<Animal> animais = new LinkedList<>();

        animais.add(new Cavalo("Agro"));
        animais.add(new Cavalo("Carpeado"));

        animais.add(new Cobra("Solid"));
        animais.add(new Cobra("Raiden"));

        animais.add(new Sapo("Rubens"));
        animais.add(new Sapo("Diavolo"));

        for (Animal animal : animais) {
            System.out.println(animal);
        }
   } 
}
