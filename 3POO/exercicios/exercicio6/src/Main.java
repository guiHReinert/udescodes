import dados.*;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println(Geradores.values().length);
        for(int g=0; g < Geradores.values().length; g++){
            Gerador gerador = Geradores.values()[g].getGerador();
            gerador.gerar(10);
            System.out.println(gerador.getClass().getName() + ": " + gerador.getSequencia());
        }

    }
}
