package dados;

import java.lang.Math;

public class NumerosPrimos extends Gerador{
    public void gerar(int quantidade){
        int num=1;
        while(true){
            for(int d=2; d <= Math.sqrt(num); d++){
                if(num % d == 0){
                    this.sequencia.add(num);
                    quantidade--;
                    break;
                }
            }
            num++;
            if(quantidade == 0){
                break;
            }
        }
    }
}
