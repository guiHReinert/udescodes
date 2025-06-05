package ex3;

public class Video extends Arquivo{
    private Qualidade qualidade;

    public Video(String nome, Qualidade qualidade) throws NomeInvalidoException{
        super(nome);
        this.qualidade = qualidade;
        this.extensao = "mp4";
    }

    public Qualidade getQualidade() {
        return qualidade;
    }
    
    public void setQualidade(Qualidade qualidade) {
        this.qualidade = qualidade;
    }

    @Override
    public String toString() {
        return  super.toString() + "\n\tQualidade: " + qualidade.getQualidade() + "p";
    }
}
