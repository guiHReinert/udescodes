package ex2;

public class Juiz{
    private String nome;
    private Pilha<Processo> processos;
    
    public Juiz(int limite){
        processos = new Pilha<Processo>(limite);
    }

    public Juiz(String nome, int limite){
        this.nome = nome;
        processos = new Pilha<Processo>(limite);
    }

    public void cadastrarProcesso(Processo processo) throws PilhaCheiaException{
        processos.inserir(processo);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Pilha<Processo> getProcessos() {
        return processos;
    }

    public void setProcessos(Pilha<Processo> processos) {
        this.processos = processos;
    }
}
