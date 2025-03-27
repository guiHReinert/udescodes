package classes;

public class Funcionario {
    private String cpf;
    private String nome;
    private String funcao;
    private float salario;
    private Endereco endereco;
    
    public Funcionario() {
        cpf = 0;
        nome = "";
        funcao = "";
        salario = 0.0;
        endereco = new Endereco();
    }

    public Funcionario(String c, String n, String f, float s, Endereco e) {
        cpf = c;
        nome = n;
        funcao = f;
        salario = s;
        endereco = e;
    }

    public String getCpf() {
        return cpf;
    }
    public void setCpf(String c) {
        cpf = c;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String n) {
        nome = n;
    }

    public String getFuncao() {
        return funcao;
    }
    public void setFuncao(String f) {
        funcao = f;
    }

    public float getSalario() {
        return salario;
    }
    public void setSalario(float s) {
        salario = s;
    }

    public Endereco getEndereco() {
        return endereco;
    }
    public void setEndereco(Endereco e) {
        endereco = e;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Funcionario other = (Funcionario) obj;
        if (cpf == null) {
            if (other.cpf != null)
                return false;
        } else if (!cpf.equals(other.cpf))
            return false;
        if (nome == null) {
            if (other.nome != null)
                return false;
        } else if (!nome.equals(other.nome))
            return false;
        if (funcao == null) {
            if (other.funcao != null)
                return false;
        } else if (!funcao.equals(other.funcao))
            return false;
        if (Float.floatToIntBits(salario) != Float.floatToIntBits(other.salario))
            return false;
        if (endereco == null) {
            if (other.endereco != null)
                return false;
        } else if (!endereco.equals(other.endereco))
            return false;
        return true;
    }

    public String toString() {
        return "CPF: "+cpf+
        "\nNome: "+nome+
        "\nFuncao: "+funcao+
        "\nSalario: R$"+salario+
        "\nEndereco: "+endereco;
    }
}
