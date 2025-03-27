package classes;

import java.util.Arrays;

public class Compra {
    private final int maxNumProdutos = 99;
    private Produto[] produtos = new Produto[maxNumProdutos];
    private float valorTotal;
    private float newCashback;
    private Cliente cliente;

    public Compra() {
        valorTotal = 0.0;
        newCashback = 0.0;
        cliente = new Cliente();
    }

    public Compra(Produto[] p, float v, float n, Cliente c) {
        produtos = p;
        valorTotal = v;
        newCashback = n;
        cliente = c;
    }

    public int getMaxNumProdutos() {
        return maxNumProdutos;
    }

    public Produto[] getProdutos() {
        return produtos;
    }
    public void setProdutos(Produto[] p) {
        produtos = p;
    }

    public float getValorTotal() {
        return valorTotal;
    }
    public void setValorTotal(float v) {
        valorTotal = v;
    }

    public float getNewCashback() {
        return newCashback;
    }
    public void setNewCashback(float n) {
        newCashback = n;
    }
    
    public Cliente getCliente() {
        return cliente;
    }
    public void setCliente(Cliente c) {
        cliente = c;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Compra other = (Compra) obj;
        if (maxNumProdutos != other.maxNumProdutos)
            return false;
        if (!Arrays.equals(produtos, other.produtos))
            return false;
        if (Float.floatToIntBits(valorTotal) != Float.floatToIntBits(other.valorTotal))
            return false;
        if (Float.floatToIntBits(newCashback) != Float.floatToIntBits(other.newCashback))
            return false;
        if (cliente == null) {
            if (other.cliente != null)
                return false;
        } else if (!cliente.equals(other.cliente))
            return false;
        return true;
    }

    public String toString() {
        return "Cliente:\n"+cliente+
        "\nProdutos:\n"+Array.produtos.toString()+
        "\nValor da compra: R$"+valorTotal+
        "\nCashback: R$"+newCashback;
    }
}
