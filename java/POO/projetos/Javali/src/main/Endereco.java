package main;

public class Endereco{
    private String rua;
    private String numero;
    private String bairro;
    private String cidade;
    private String estado;
    private String cep;

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

    public String getCEP(){
        return cep;
    }
    public void setCEP(String c){
        cep = c;
    }
}