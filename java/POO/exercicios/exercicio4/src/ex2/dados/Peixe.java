package ex2.dados;

public class Peixe extends Animal {

    private float temperaturaIdeal;

    // public float calcularEspacoOcupado(){

    // }

    public float getTemperaturaIdeal() {
        return temperaturaIdeal;
    }

    public void setTemperaturaIdeal(float temperaturaIdeal) {
        this.temperaturaIdeal = temperaturaIdeal;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!super.equals(obj))
            return false;
        if (getClass() != obj.getClass())
            return false;
        Peixe other = (Peixe) obj;
        if (Float.floatToIntBits(temperaturaIdeal) != Float.floatToIntBits(other.temperaturaIdeal))
            return false;
        return true;
    }
}
