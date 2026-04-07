package ex1;
import java.lang.Math;

public class MDC implements OperacaoInteira{
    public int executar(int valor1, int valor2){
        int div = 1;
        for(int i=2; i <= Math.sqrt(valor1); i++){
            if(valor1 % i == 0 && valor2 % i == 0){
                div = i;
            }
        }
        return div;
    }
}
