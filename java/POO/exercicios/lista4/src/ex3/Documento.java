package ex3;

public class Documento extends Arquivo{
    private String texto;

    public Documento(String nome, String texto) throws NomeInvalidoException{
        super(nome);
        this.extensao = "txt";
        this.texto = texto;
    }

    public String getTexto() {
        return texto;
    }
    
    public void setTexto(String texto) {
        this.texto = texto;
    }

    @Override
    public String toString() {
        return super.toString() + "\n\tTexto:\n\t\t" + texto;
    }
}
