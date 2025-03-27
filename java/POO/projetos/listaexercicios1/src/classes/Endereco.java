package classes;

public class Endereco{
    private String rua;
    private int numero;
    private String bairro;
    private String cidade;
    private String estado;
    private int cep;

    public Endereco(){
        rua = "";
        numero = 0;
        bairro = "";
        cidade = "";
        estado = "";
        cep = 0;
    }

    public Endereco(String r, int n, String b, String c, String e, int ce) {
        rua = r;
        numero = n;
        bairro = b;
        cidade = c;
        estado = e;
        cep = ce;
    }

    public String getRua(){
        return rua;
    }
    public void setRua(String r){
        rua = r;
    }

    public String getNumero(){
        return numero;
    }
    public void setNumero(String n){
        numero = n;
    }

    public String getBairro(){
        return bairro;
    }
    public void setBairro(String b){
        bairro = b;
    }

    public String getCidade(){
        return cidade;
    }
    public void setCidade(String c){
        cidade = c;
    }

    public String getEstado(){
        return estado;
    }
    public void setEstado(String e){
        estado = e;
    }

    public int getCEP(){
        return cep;
    }
    public void setCEP(int c){
        cep = c;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Endereco other = (Endereco) obj;
        if (rua == null) {
            if (other.rua != null)
                return false;
        } else if (!rua.equals(other.rua))
            return false;
        if (numero != other.numero)
            return false;
        if (bairro == null) {
            if (other.bairro != null)
                return false;
        } else if (!bairro.equals(other.bairro))
            return false;
        if (cidade == null) {
            if (other.cidade != null)
                return false;
        } else if (!cidade.equals(other.cidade))
            return false;
        if (estado == null) {
            if (other.estado != null)
                return false;
        } else if (!estado.equals(other.estado))
            return false;
        if (cep != other.cep)
            return false;
        return true;
    }

    public String toString(){
        return rua+", "+numero+", "+bairro+". "+cidade+", "+estado+
        ".\nCEP: "+cep;
    }

}