package ex3Classes;

import java.util.Arrays;

public class Imobiliaria {
    private String nome;
    private Imovel[] imoveis = new Imovel[99];
    private int numImoveis;

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public Imovel[] getImoveis() {
        return imoveis;
    }
    public void cadastrarImovel(Imovel vomel){
        imoveis[numImoveis++] = vomel;
    }

    public int getNumImoveis() {
        return numImoveis;
    }
    public void setNumImoveis(int numImoveis) {
        this.numImoveis = numImoveis;
    }

    public Imovel[] filtrarPorArea(float num){
        if(numImoveis > 1){
            // Gerar o vetor de areas 
            float[] areas = new float[numImoveis];
            for(int j=0; j < numImoveis; j++){
                areas[j] = imoveis[j].getArea();
            }

            // Fazer o sorting do vetor de imoveis pelo vetor de areas (CRESCENTE)
            float auxA;
            Imovel auxI;
            for(int l=0; l < numImoveis; l++){
                for(int p=0; p < numImoveis - 1; p++){
                    if(areas[p] > areas[p+1]){
                        auxA = areas[p];
                        auxI = imoveis[p];

                        areas[p] = areas[p+1];
                        imoveis[p] = imoveis[p+1];

                        areas[p+1] = auxA;  
                        imoveis[p+1] = auxI;
                    }
                }
            }

            // Vetor de imoveis filtrados por area
            Imovel[] imoveisFiltrados = new Imovel[numImoveis];
            int pos=0;
            for(int j=0; j < numImoveis; j++){
                if(imoveis[j].getArea() >= num){
                    imoveisFiltrados[pos++] = imoveis[j];
                }
            }
            return imoveisFiltrados;
        }
        return null;
    }

    public String toString() {
        return "Nome: "+nome+
        "\nImoveis:\n"+Arrays.toString(imoveis);
    }

    
}
