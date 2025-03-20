package ex2.semana2.questao1;

/*
1. Uma pessoa possui nome, idade (em anos), altura (em metros) e massa (em
kilogramas). Implemente em Java duas classes, uma que representa a Pessoa, com
seus devidos atríbutos e outra que representa um Grupo de pessoas. A classe Grupo
possui um número fixo de pessoas (fica a seu cargo escolher). Além do mais, a classe
Pessoa deve possuir um método para calcular o IMC (indíce de massa corporal), que é
calculado pela seguinte fórmula:

IMC = massa/altura2

A classe Grupo também deve possuir um método que exibe as pessoas em ordem
decrescente de IMC.
*/

public class Pessoa{

    private String name;
    private int age;
    private float height;
    private float mass;
    private float imc;

    public void setName(String name){
        this.name = name;
    }
    public String getName(){
        return name;
    }

    public void setAge(int age){
        this.age = age;
    }
    public int getAge(){
        return age;
    }

    public void setHeight(float height){
        this.height = height;
    }
    public float getHeight(){
        return height;
    }

    public void setMass(float mass){
        this.mass = mass;
    }
    public float getMass(){
        return mass;
    }

    public float getIMC(){
        this.imc = this.mass / (this.height * this.height);
        return this.imc;
    }
}