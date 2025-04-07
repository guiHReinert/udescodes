package ex4Classes;

public class Pessoa {
    private String nome;
    private int idade;
    private String genero;
    private String signo; // (piada)

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getGenero() {
        return genero;
    }
    public void setGenero(String genero) {
        this.genero = genero;
    }

    public String getSigno() {
        return signo;
    }
    public void setSigno(String signo) {
        this.signo = signo;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Pessoa other = (Pessoa) obj;
        if (nome == null) {
            if (other.nome != null)
                return false;
        } else if (!nome.equals(other.nome))
            return false;
        if (idade != other.idade)
            return false;
        if (genero == null) {
            if (other.genero != null)
                return false;
        } else if (!genero.equals(other.genero))
            return false;
        if (signo == null) {
            if (other.signo != null)
                return false;
        } else if (!signo.equals(other.signo))
            return false;
        return true;
    }
    public String toString() {
        return "Nome: "+nome+
        "\nIdade: "+idade+
        "\nGenero: "+genero+
        "\nCavalheiro do Zodiaco: "+signo;
    }
}
