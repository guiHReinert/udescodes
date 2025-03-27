package classes;

public class Cliente {
    private long cpf;
    private String nome;
    private Endereco endereco;
    private float cashback;

    public Cliente()	{
    	cpf = 0; // 11 digitos
    	nome = "";
        endereco = new Endereco();
        cashback = 0.0;
    }

    public Cliente(long c, String n, Endereco e, float ca) {
        cpf = c;
        nome = n;
        endereco = e;
        cashback = ca;
    }

    public long getCpf() {
        return cpf;
    }
    public void setCpf(long c) {
        cpf = c;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String n) {
        nome = n;
    }

    public Endereco getEndereco() {
        return endereco;
    }
    public void setEndereco(Endereco e) {
        endereco = e;
    }

    public float getCashback() {
        return cashback;
    }
    public void setCashback(float c) {
        cashback = c;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Cliente other = (Cliente) obj;
        if (cpf != other.cpf)
            return false;
        if (nome == null) {
            if (other.nome != null)
                return false;
        } else if (!nome.equals(other.nome))
            return false;
        if (endereco == null) {
            if (other.endereco != null)
                return false;
        } else if (!endereco.equals(other.endereco))
            return false;
        if (Float.floatTolongBits(cashback) != Float.floatTolongBits(other.cashback))
            return false;
        return true;
    }

    public String toString() {
        return "Nome: "+nome+"\nCPF: "+cpf+"\nEndereco: "+endereco.toString()+"\nCashback: R$"+cashback;
    }
    
}
