package ex2.dados;

public class Aquario extends Viveiro{
    private float altura;
    
    @Override
    public float calculaEspaco(){
        return comprimento *largura*altura;
    }

    public float getAltura() {
        return altura;
    }
    public void setAltura(float altura) {
        this.altura = altura;
    }
}
