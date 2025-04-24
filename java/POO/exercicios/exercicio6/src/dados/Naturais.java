package dados;

public class Naturais extends Gerador{
    public void gerar(int quantidade){
        for(int n=0; n < quantidade; n++){
            this.sequencia.add(n);
        }
    }
}
