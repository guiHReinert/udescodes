package ex3;

public enum Qualidade {
    Q240(240),
    Q360(360),
    Q720(720),
    Q1024(1024);

    public int qualidade;

    Qualidade(int qualidade){
        this.qualidade = qualidade;
    }

    public int getQualidade(){
        return qualidade;
    }
}
