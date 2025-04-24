package dados;

public class Fibonacci extends Gerador{
    public void gerar(int quantidade){
        int c;
        while(quantidade > 0){
            c = 0;
            while(true){
                for(int n=0; n < quantidade; n++){
                    if(quantidade == 0){
                        this.sequencia.add(0);
                    }
                    else if(quantidade == 1){
                        this.sequencia.add(1);
                    }
                    else{
                        this.sequencia.add(this.sequencia.get(n-1) + n);
                    }
                }
                c++;
            }
            quantidade--;
        }
    }
}  
