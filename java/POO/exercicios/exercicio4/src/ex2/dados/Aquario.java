package ex2.dados;

public class Aquario extends Viveiro {
    private float altura;

    @Override
    public float calculaEspaco() {
        return comprimento * largura * altura;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!super.equals(obj))
            return false;
        if (getClass() != obj.getClass())
            return false;
        Aquario other = (Aquario) obj;
        if (Float.floatToIntBits(altura) != Float.floatToIntBits(other.altura))
            return false;
        return true;
    }
}
