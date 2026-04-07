package ex2;

public class Main {
    
    private static final SistemaProcessos sistema = new SistemaProcessos();
    
    public static void main(String[] args) throws Exception {

        sistema.cadastrarJuiz(new Juiz("Dredd", 5));
        sistema.cadastrarJuiz(new Juiz("Saul Goodman", 5));
        sistema.cadastrarJuiz(new Juiz("Marco D. Scalso", 5));

        for(int i=0; i < 18; i++){
            sistema.cadastrarProcesso(
                new Processo(91827364 + ((20 + 7) * i), "Processo " + (i + 1)));
        }

        System.out.println("Juizes: ");
        sistema.getJuizes().forEach(juiz -> System.out.println("\t" + juiz.getNome()));

        System.out.println("\nProcessos: ");
        sistema.getProcessos().forEach(processo -> System.out.println("\t" + processo.getNome()));

        sistema.distribuirProcessos();
        System.out.println("(processos distribuidos)");

        System.out.println("\nJuizes e seus processos: ");
        sistema.getJuizes().forEach(juiz ->{
            System.out.println("\nJuiz: " + juiz.getNome());
            juiz.getProcessos().getElementos().forEach(processo -> System.out.println("\t" + processo.getNome()));
        });
    }
    
}
