package classes;

public class Produto {
    private String nome;
    private String categoria;
    private double preco;
    private double desconto; // Multiplicador de porcentagem
    
    public Produto(){
        nome = "";
        categoria = "";
        preco = 0.0;
        desconto = 1;
    }
    
    public Produto(String n, String c, double p, double d) {
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
    
    public double getPreco() {
        return preco;
    }
    public void setPreco(int p) {
        preco = p;
    }

    public double getDesconto() {
        return desconto;
    }
    public void setDesconto(double d) {
        desconto = d;
    }

    public double getPrecoReal(){
        return preco * (1-desconto); 
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
        if (Double.doubleToLongBits(preco) != Double.doubleToLongBits(other.preco))
            return false;
        if (Double.doubleToLongBits(desconto) != Double.doubleToLongBits(other.desconto))
            return false;
        return true;
    }

    public String toString() {
        return "Nome: "+nome+
        "\nCategoria: "+categoria+
        String.format("\nPreco: R$%.2f", preco)+
        "\nDesconto: "+desconto+"%\n";
    }
}
