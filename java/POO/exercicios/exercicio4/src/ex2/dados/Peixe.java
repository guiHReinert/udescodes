package ex2.dados;

public class Peixe extends Animal {
    private float temperaturaIdeal;

    public Peixe(){
    }
    public Peixe(String no, String cor, String es, int id,
    float la, float com, float al, float te){
        super(no, cor, es, id, la, com, al);
        temperaturaIdeal = te;
    }

    public float calcularEspacoOcupado(){
        return largura * comprimento * altura;
    }

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

    @Override
    public String toString() {
        return super.toString() + "Temperatura ideal: " + temperaturaIdeal + '\n';
    }
}
