package ex3;

public abstract class Arquivo {
    protected String nome;
    protected String extensao;

    public Arquivo(String nome) throws NomeInvalidoException{
        for(int i=0; i < nome.length(); i++){
            char nomeChar = nome.charAt(i);

            if(nomeChar=='\n' || nomeChar== '(' || nomeChar==')'
            || nomeChar=='[' || nomeChar== ']' || nomeChar=='\''
            || nomeChar=='\"')
            {
                throw new NomeInvalidoException("\n\nNome de arquivo invalido: \"" + nome + "\" contem " + "\"" + nomeChar + "\".\n");
            }
            else{
                this.nome = nome;
            }
        }
    };

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getExtensao() {
        return extensao;
    }

    public void setExtensao(String extensao) {
        this.extensao = extensao;
    }

    @Override
    public String toString() {
        return nome + "." + extensao;
    }
}
