package ex2.classes;

import java.lang.Math;

public class TrianguloEquilatero extends FormaGeometrica {
    public TrianguloEquilatero(int lado) {
        this.medida1 = lado;
        this.medida2 = lado;
    }

    public void setLado(int lado){
        this.medida1 = lado;
        this.medida2 = lado;
    }

    public int getLado(){
        return medida1;
    }
    
    public int calcularArea() {
        return (int) Math.round((Math.sqrt(3) / 4) * medida1 * medida1);
    }

    public int calcularPerimetro() {
        return 3 * medida1;
    }

    @Override
    public String toString() {
        return "Triangulo Equilatero: " + medida1 + ", (Area: " + calcularArea() + ", Per: " + calcularPerimetro() + ")"; 
    }
}
