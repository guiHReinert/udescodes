package dados;

import java.lang.Math;

public class NumerosPrimos extends Gerador{
    boolean ehPrimo;
    public void gerar(int quantidade){
        for(int n=1; n < quantidade; n++){
            ehPrimo = true;
            for(int d=2; d < Math.sqrt(n); d++){
                if(n % d == 0){
                    ehPrimo = false;
                }
            }
            if(ehPrimo){
                this.sequencia.add(n);
            }
        }
    }
}
