package ex2;

import java.util.ArrayList;

import java.lang.Math;

public class Matriz<T> {
    private ArrayList<ArrayList<T>> matriz;
    private int numLinhas;
    private int numColunas;

    public enum Quadrante {
        PRIMEIRO, SEGUNDO, TERCEIRO, QUARTO
    }

    public Matriz(int n, int m) {
        this.numLinhas = n;
        this.numColunas = m;
        this.matriz = new ArrayList<>();
        for (int i = 0; i < numLinhas; i++) {
            ArrayList<T> linha = new ArrayList<T>();
            for (int j = 0; j < numColunas; j++) {
                linha.add(null);
            }
            matriz.add(linha);
        }
    }

    public boolean set(T item, int i, int j) {
        if (i >= 0 && i < numLinhas && j >= 0 && j < numColunas) {
            matriz.get(i).set(j, item);
            return true;
        } else {
            return false;
        }
    }

    public T get(int i, int j) {
        if (i >= 0 && i < numLinhas && j >= 0 && j < numColunas) {
            return matriz.get(i).get(j);
        } else {
            return null;
        }
    }

    public ArrayList<T> getLinha(int i) {
        if (i >= 0 && i < numLinhas) {
            return matriz.get(i);
        } else {
            return null;
        }
    }

    public ArrayList<T> getColuna(int j) {
        if (j >= 0 && j < numColunas) {
            ArrayList<T> coluna = new ArrayList<>();
            for (int i = 0; i < numLinhas; i++) {
                if (matriz.get(i).get(j) != null) {
                    coluna.add(matriz.get(i).get(j));
                }
            }
            return coluna;
        } else {
            return null;
        }
    }

    public ArrayList<T> getElementosQuadrante(Quadrante quadrante) {
        ArrayList<T> elementos = new ArrayList<T>();
        int metLin = (int) Math.ceil(numLinhas / 2.0);
        int metCol = (int) Math.ceil(numColunas / 2.0);
        switch (quadrante) {
            case PRIMEIRO:
                for (int i = 0; i < metLin; i++) {
                    for (int j = 0; j < metCol; j++) {
                        if (matriz.get(i).get(j) != null) {
                            elementos.add(matriz.get(i).get(j));
                        }
                    }
                }
                break;
            case SEGUNDO:
                for (int i = 0; i < metLin; i++) {
                    for (int j = metCol; j < numColunas; j++) {
                        if (matriz.get(i).get(j) != null) {
                            elementos.add(matriz.get(i).get(j));
                        }
                    }
                }
                break;
            case TERCEIRO:
                for (int i = metLin; i < numLinhas; i++) {
                    for (int j = 0; j < metCol; j++) {
                        if (matriz.get(i).get(j) != null) {
                            elementos.add(matriz.get(i).get(j));
                        }
                    }
                }
                break;
            case QUARTO:
                for (int i = metLin; i < numLinhas; i++) {
                    for (int j = metCol; j < numColunas; j++) {
                        if (matriz.get(i).get(j) != null) {
                            elementos.add(matriz.get(i).get(j));
                        }
                    }
                }
                break;
        }
        return elementos;
    }

    public int getNumLinhas() {
        return numLinhas;
    }

    public void setNumLinhas(int numLinhas) {
        this.numLinhas = numLinhas;
    }

    public int getNumColunas() {
        return numColunas;
    }

    public void setNumColunas(int numColunas) {
        this.numColunas = numColunas;
    }

}
