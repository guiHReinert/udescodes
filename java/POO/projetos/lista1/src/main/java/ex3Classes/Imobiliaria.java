package ex3Classes;

import java.util.Arrays;

public class Imobiliaria {
    private String nome;
    private Imovel[] imoveis = new Imovel[99];

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public Imovel[] getImoveis() {
        return imoveis;
    }
    public void setImoveis(Imovel[] imoveis) {
        this.imoveis = imoveis;
    }

    public Imovel[] filtrarPorArea(float num){ // A FAZER O SORTING
        Imovel[] imoveisFiltrados = new Imovel[99];
        
        int pos=0;
        for(int j=0; j<99; j++){
            if(imoveis[j].getArea() >= num){
                imoveisFiltrados[pos++] = imoveis[j];
            }
        }
        return imoveisFiltrados;
    }

    public String toString() {
        return "Imobiliaria [nome=" + nome + ", imoveis=" + Arrays.toString(imoveis) + "]";
    }

    
}
