package ex2.dados;

public class Aquario extends Viveiro {
    private float altura;
    private float temperatura;

    @Override
    public float calculaEspaco() {
        return comprimento * largura * altura;
    }

    private float espacoOcupado() {
        float sum = 0;
        for (Animal a : animais) {
            sum += a.calculaEspacoOcupado() * a.getAltura();
        }
        return sum;
    }

    @Override
    public float espacoDisponivel() {
        return calculaEspaco() - espacoOcupado();
    }

    @Override
    public boolean adicionarAnimal(Animal animal) {
        if(animal instanceof Peixe){
            Peixe peixe = (Peixe) animal;
            if (espacoOcupado() / calculaEspaco() <= 0.7
            && (temperatura >= peixe.getTemperaturaIdeal() - 3
            || temperatura <= peixe.getTemperaturaIdeal() + 3
            )){ // Pelo menos 30% da capacidade livre
                animais.add(peixe);
                return true;
            }
            else{
                return false;
            }
        } else {
            return false;
        }
    }

    public float getAltura() {
        return altura;
    }
    
    public void setAltura(float altura) {
        this.altura = altura;
    }

    public float getTemperatura() {
        return temperatura;
    }
    
    public void setTemperatura(float temperatura) {
        this.temperatura = temperatura;
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

    @Override
    public String toString(){
        String animaisStr = new String();
        for(Animal animal : animais){
            animaisStr += '\n' + animal.toString();
        }
        return "Nome: " + nome +
        "\nComprimento: " + comprimento +
        "\nLargura: " + largura +
        "\nAltura: " + altura +
        "\nTemperatura: " + temperatura +
        animaisStr +'\n';
    }
}
