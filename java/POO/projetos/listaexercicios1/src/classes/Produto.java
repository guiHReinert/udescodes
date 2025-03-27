package classes;

public class Produto {
    private String nome;
    private String categoria;
    private float preco;
    private int desconto; // Em porcentagem
    
    public Produto(){
        nome = "";
        categoria = "";
        preco = 0.0;
        desconto = 100;
    }
    
    public Produto(String n, String c, float p, int d) {
        nome = n;
        categoria = c;
        preco = p;
        desconto = d;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String n) {
        nome = n;
    }

    public String getCategoria() {
        return categoria;
    }
    public void setCategoria(String c) {
        categoria = c;
    }
    
    public float getPreco() {
        return preco;
    }
    public void setPreco(int p) {
        preco = p;
    }
    public float getDesconto() {
        return desconto;
    }
    public void setDesconto(int d) {
        desconto = d;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Produto other = (Produto) obj;
        if (nome == null) {
            if (other.nome != null)
                return false;
        } else if (!nome.equals(other.nome))
            return false;
        if (categoria == null) {
            if (other.categoria != null)
                return false;
        } else if (!categoria.equals(other.categoria))
            return false;
        if (Float.floatToIntBits(preco) != Float.floatToIntBits(other.preco))
            return false;
        if (Float.floatToIntBits(desconto) != Float.floatToIntBits(other.desconto))
            return false;
        return true;
    }

    public String toString() {
        return "Nome: "+nome+
        "\nCategoria: "+categoria+
        "\nPreco: R$"+preco+
        "\nDesconto: "+desconto+'%';
    }
}
