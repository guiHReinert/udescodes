package ex3;

public class Musica extends Arquivo{
    // Duracao em segundos.
    private int duracao;

    public Musica(String nome, int duracao) throws NomeInvalidoException{
        super(nome);
        this.extensao = "mp3";
    }

    public int getDuracao() {
        return duracao;
    }
    
    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }
    
    @Override
    public String toString() {
        return super.toString() + "\n\tDuracao: " + duracao + "s";
    }
}
