package dados;

public class Fatoriais extends Gerador{
    public void gerar(int quantidade){
        int c = 1, produto = 1;
        while(quantidade > 0){
            produto = 1;
            for(int x=1; x <= c; x++){
                produto *= x;
            }
            this.sequencia.add(produto);
            quantidade--;
        }
    }
}
