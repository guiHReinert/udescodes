package dados;

public class Fibonacci extends Gerador{
    public void gerar(int quantidade){
        for(int n=0; n <= quantidade; n++){
            if(n == 0){
                this.sequencia.add(0);
            }
            else if(n == 1){
                this.sequencia.add(1);
            }
            else{
                this.sequencia.add(this.sequencia.get(n-1) + n+1);
            }
        }
    }
}  
