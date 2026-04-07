package dados;

public enum Geradores{
    ABUNDANTES(new Abundantes()),
    FATORIAIS(new Fatoriais()),
    FIBONACCI(new Fibonacci()),
    NATURAIS(new Naturais()),
    NUMEROSPRIMOS(new NumerosPrimos()),
    PERFEITOS(new Perfeitos()),
    QUADRADOS(new Quadrados());

    private Gerador gerador;

    private Geradores(Gerador gerador){
        this.gerador = gerador;
    }

    public Gerador getGerador(){
        return this.gerador;
    }
}
