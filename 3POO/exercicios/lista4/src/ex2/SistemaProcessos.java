package ex2;

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class SistemaProcessos {
    private List<Juiz> juizes = new ArrayList<>();
    private List<Processo> processos = new ArrayList<>();

    public void cadastrarProcesso(Processo processo){
        processos.add(processo);
    }

    public void cadastrarJuiz(Juiz juiz){
        juizes.add(juiz);
    }

    public void distribuirProcessos() throws ProcessoSemJuizException{

        // Copiar as listas para nao alterar as originais;
        List<Processo> randProcessos = new ArrayList<>(processos);
        List<Juiz> randJuizes = new ArrayList<>(juizes);

        // Aleatorizar a(s) lista(s).
        Collections.shuffle(randProcessos);
        System.out.println("\nProcessos aleatorizados:");
        randProcessos.forEach(processo -> System.out.println("\t" + processo.getNome()));

        /*
            Distibuir os processos de maneira aleatoria, sem que as pilhas dos
            juizes estourem.
        */
        System.out.println("\nDistribuicao dos processos:\n");
        while(!randJuizes.isEmpty() && !randProcessos.isEmpty()){
            Collections.shuffle(randJuizes);
            Processo processo = randProcessos.get(0);
            Juiz juiz = randJuizes.get(0);

            try{
                juiz.cadastrarProcesso(processo);
                randProcessos.remove(0);
            }
            catch(PilhaCheiaException pc){

                System.out.printf("Juiz cheio: %s (%d)\n\n", juiz.getNome(), juiz.getProcessos().getSize());
                // Remove este juiz caso a sua pilha de processos estiver cheia.
                randJuizes.remove(0);
            }
        }
        
        /*
            Caso sobrarem processos mesmo apos distribuir eles para todos os
            juizes, raise ProcessoSemJuizException().
        */  
        if(randProcessos.size() > 0){
            throw new ProcessoSemJuizException("\n\n\tJuizes no limite: " + randProcessos.size() + " processos sobrando.\n");
        }
    }

    public List<Juiz> getJuizes() {
        return juizes;
    }

    public void setJuizes(List<Juiz> juizes) {
        this.juizes = juizes;
    }

    public List<Processo> getProcessos() {
        return processos;
    }

    public void setProcessos(List<Processo> processos) {
        this.processos = processos;
    }

    
}
