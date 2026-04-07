package dados;

public class Perfeitos extends Gerador{
    public void gerar(int quantidade){
        int sum = 0;
        for(int n=1; n < quantidade; n++){
            sum = 0;
            for(int d=1; d < n && n % d == 0; d++){
                sum += d;
            }
            if(sum == n){
                this.sequencia.add(sum);
            }
        }
    }
}
