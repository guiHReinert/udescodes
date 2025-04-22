package ex4.pkg;

import java.util.ArrayList;

public class Turma {
    private static ArrayList<Aluno> alunos;
    
    public void adicionarAluno(Aluno aluno){
        alunos.add(aluno);
    }

    private static void ordenaAlunosPorMedia(){
        alunos.sort((a1, a2) -> a1.calcularMedia().compareTo(a2.calcularMedia()));
    }

    public ArrayList<Equipe<Aluno>> separarEmEquipes(){
        ordenaAlunosPorMedia();
        ArrayList<Aluno> selecao = (ArrayList<Aluno>)alunos.clone();
        int quantidade = 0;
        ArrayList<Equipe<Aluno>> equipes = new ArrayList<Equipe<Aluno>>(); 

        for(int e=0; e < alunos.size() / 4; e++){
            Equipe<Aluno> equipe = new Equipe<Aluno>();
            for(int i=0; i < 2; i++){
                if(selecao.size() > 0){
                    equipe.adicionarAluno(selecao.get(i));
                    selecao.remove(i);
                }
            }
            equipe.adicionarAluno(alunos.get(selecao.size()));
            selecao.remove(selecao.size()-1);
            
            equipes.add(equipe);

        }
        

    }
}
