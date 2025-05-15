package dados;

public class Abundantes extends Gerador{
    public void gerar(int quantidade){
        int c = 0, sum = 0;
        while(quantidade > 0){
            c = 2;
            while(true){
                sum = 0;
                for(int d=1; d < c && c % d == 0; d++){
                    sum += d;
                }
                if(c < sum){
                    this.sequencia.add((Integer)c);
                    break;
                }
                c++;
            }
            quantidade--;
        }
    }
}
