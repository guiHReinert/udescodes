package ex1;

public class Mod implements OperacaoInteira{
    public int executar(int valor1, int valor2){
        if(valor1 != 0){
            return valor1 / valor2;
        }
        else{
            return 0;
        }
    }
}
