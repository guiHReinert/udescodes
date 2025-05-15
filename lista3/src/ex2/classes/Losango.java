package ex2.classes;

import java.lang.Math;

public class Losango extends FormaGeometrica{
    public Losango(int daigM, int diagm){
        this.medida1 = daigM;
        this.medida2 = diagm;
    }

    // Diagonal maior
    public void setD(int valor){
        this.medida1 = valor;
    }

    public int getD(){
        return medida1;
    }

    // Diagonal menor
    public void setd(int valor){
        this.medida2 = valor;
    }

    public int getd(){
        return medida2;
    }

    public int calcularArea(){
        return (medida1 * medida2) / 2;
    }

    public int calcularPerimetro(){
        return 4 * (int) Math.round(Math.sqrt((medida1 * medida1)/4 + (medida2 * medida2)/4));
    }

    @Override
    public String toString() {
        return "Losango: " + medida1 + ", " + medida2 + " (Area: " + calcularArea() + ", Per: " + calcularPerimetro() + ")"; 
    }
}
