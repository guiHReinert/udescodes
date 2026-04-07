package ex4.app;

import java.util.Collections;
import java.util.ArrayList;
import ex4.pkg.*;

public class Main {
    public static void main(String[] args){
        // Turma de exemplo do enunciado
        Turma turma1 = new Turma();

        ArrayList<Double> arr1 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr1.add(9.7);
        }
        turma1.adicionarAluno(new Aluno("Julia", 16, arr1));

        ArrayList<Double> arr2 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr2.add(9.2);
        }
        turma1.adicionarAluno(new Aluno("Gabriela", 15, arr2));
        
        ArrayList<Double> arr3 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr3.add(8.7);
        }
        turma1.adicionarAluno(new Aluno("Matheus", 16, arr3));

        ArrayList<Double> arr4 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr4.add(8.4);
        }
        turma1.adicionarAluno(new Aluno("Isabela", 15, arr4));

        ArrayList<Double> arr5 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr5.add(7.8);
        }
        turma1.adicionarAluno(new Aluno("Lucas", 16, arr5));

        ArrayList<Double> arr6 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr6.add(7.5);
        }
        turma1.adicionarAluno(new Aluno("Marcos", 15, arr6));

        ArrayList<Double> arr7 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr7.add(7.2);
        }
        turma1.adicionarAluno(new Aluno("Leticia", 16, arr7));

        ArrayList<Double> arr8 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr8.add(6.6);
        }
        turma1.adicionarAluno(new Aluno("Beatriz", 15, arr8));

        ArrayList<Double> arr9 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr9.add(5.6);
        }
        turma1.adicionarAluno(new Aluno("Rafael", 45, arr9));

        ArrayList<Double> arr10 = new ArrayList<Double>();
        for(int n=0; n < 5; n++){
            arr10.add(4.7);
        }
        turma1.adicionarAluno(new Aluno("Gabriel", 28, arr10));

        // Reorganizar a turma
        Collections.shuffle(turma1.getAlunos());

        // "Resortar" a turma
        turma1.getAlunos().sort((a1, a2) -> a1.calcularMedia().compareTo(a2.calcularMedia()));
 
        // Printar alunos
        for(int i=0; i < turma1.getAlunos().size(); i++){
            System.out.printf("[%d] %s", i, turma1.getAlunos().get(i).toString());
        }

        // Printar as equipes formadas (2 de nota alta + 1 ou 2 de nota baixa)
        System.out.println("");
        ArrayList<Equipe<Aluno>> equipes = turma1.separarEmEquipes();
        for(int e=0; e < equipes.size(); e++){
            System.out.printf("Equipe %d:\n", e);
            for(Aluno aluno : equipes.get(e).getAlunos()){
                System.out.printf(" - %s, %d, %.1f\n", aluno.getNome(), aluno.getIdade(), aluno.calcularMedia());
            }
        }
    }
}
