package classes;

import java.util.Arrays;

public class Compra {
    private final int maxNumProdutos = 99;
    private Produto[] produtos = new Produto[maxNumProdutos];
    private double valorTotal;
    private double newCashback;
    private Cliente cliente;

    public Compra() {
        valorTotal = 0.0;
        newCashback = 0.0;
        cliente = new Cliente();
    }

    public Compra(Produto[] p, double v, double n, Cliente c) {
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

    public double getValorTotal() {
        return valorTotal;
    }
    public void setValorTotal(double v) {
        valorTotal = v;
    }

    public double getNewCashback() {
        return newCashback;
    }
    public void setNewCashback(double n) {
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
        if (Double.doubleToLongBits(valorTotal) != Double.doubleToLongBits(other.valorTotal))
            return false;
        if (Double.doubleToLongBits(newCashback) != Double.doubleToLongBits(other.newCashback))
            return false;
        if (cliente == null) {
            if (other.cliente != null)
                return false;
        } else if (!cliente.equals(other.cliente))
            return false;
        return true;
    }

    public String toString() {
        String prod = new String();
        for(Produto p : produtos){
            if(p != null){
                prod += p.toString()+'\n';
            }
        }

        return "Cliente:\n"+cliente+
        String.format("\nValor da compra: R$%.2f", valorTotal)+
        "\nProdutos:\n"+prod+
        String.format("Cashback (novo): R$%.2f\n", newCashback);
    }
}
