package ex2.classes;

import java.lang.Math;

public class Circulo extends FormaGeometrica{
    public Circulo(int raio){
        this.medida1 = raio;
        this.medida2 = raio;
    }

    public void setRaio(int raio){
        this.medida1 = raio;
        this.medida2 = raio;
    }

    public int getRaio(){
        return medida1;
    }

    public int calcularArea(){
        return (int) Math.round((Math.PI * medida1 * medida1));
    }

    public int calcularPerimetro(){
        return (int) Math.round((2 * Math.PI * medida1));
    }

    @Override
    public String toString() {
        return "Circulo: %d, (Area: %d, Circunf: %d)".formatted(medida1, calcularArea(), calcularPerimetro()); 
    }
}
