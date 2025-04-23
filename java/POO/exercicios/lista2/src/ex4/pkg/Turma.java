package ex4.pkg;

import java.util.ArrayList;

public class Turma {
    private ArrayList<Aluno> alunos = new ArrayList<Aluno>();
    
    public void adicionarAluno(Aluno aluno){
        alunos.add(aluno);
    }

    private void ordenaAlunosPorMedia(){
        alunos.sort((a1, a2) -> a1.calcularMedia().compareTo(a2.calcularMedia()));
    }

    public ArrayList<Equipe<Aluno>> separarEmEquipes(){
        ArrayList<Equipe<Aluno>> equipes = new ArrayList<Equipe<Aluno>>(); 
        if(alunos.size() >= 3){
            ordenaAlunosPorMedia();
            ArrayList<Aluno> selecao = new ArrayList<Aluno>(alunos);
            // Quantidade de alunos com medias baixas por equipe
            int quantidadeBaixos = 1;
            for(int e=0; e < alunos.size() / 3; e++){
                Equipe<Aluno> equipe = new Equipe<Aluno>();
                // Se resto 1: 3 + 1 = uma equipe de 4
                // Se resto 2: 3 + 3 + 2 = duas equipes de 4
                // Equipes formadas + 4 ou 8 pessoas restando
                if(selecao.size() == 4 || selecao.size() == 8){
                    quantidadeBaixos = 2;
                }
                // 1 ou 2 alunos de media baixa
                for(int i=0; i < quantidadeBaixos; i++){
                    equipe.adicionarAluno(selecao.get(0));
                    selecao.remove(0);
                }
                // 2 alunos de media alta
                for(int f=0; f < 2; f++){
                    equipe.adicionarAluno(selecao.get(selecao.size()-1));
                    selecao.remove(selecao.size()-1);
                }
                equipe.getAlunos().sort((a1, a2) -> a1.calcularMedia().compareTo(a2.calcularMedia()));
                equipes.add(equipe);
            }
        }
        else{
            System.out.printf(" Nao ha alunos suficientes para formar equipes.\n");
        }
        return equipes;
    }

    public ArrayList<Aluno> getAlunos() {
        return alunos;
    }

}
