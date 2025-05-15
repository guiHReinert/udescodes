package dados;

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

public class Musica {
    private String titulo;
    private List<Artista> artistas = new ArrayList<>();
    // Geralmente uma musica possui possui 1 unico album, mas muitas
    // possuem singles e são contidas em albuns tambem
    private List<String> albuns = new LinkedList<>();
    private int duracao; // em segundos
    private List<String> generos = new ArrayList<>();
    private String letra;
    private String lancamento;

    public Musica() {}

    // Adicionar elementos nas listas
    public boolean adicionarArtista(Artista artista) {
        if (!artistas.contains(artista)) {
            artistas.add(artista);
            return true;
        }
        return false;
    }

    public boolean adicionarAlbum(String album) {
        if (!albuns.contains(album)) {
            albuns.add(album);
            return true;
        }
        return false;
    }

    public boolean adicionarGenero(String genero) {
        if (!generos.contains(genero)) {
            generos.add(genero);
            return true;
        }
        return false;
    }

    // Remover elementos das listas
    public boolean removerArtista(Artista artista) {
        if (artistas.contains(artista)) {
            artistas.remove(artista);
            return true;
        }
        return false;
    }
    public boolean removerAlbum(String album) {
        if (albuns.contains(album)) {
            albuns.remove(album);
            return true;
        }
        return false;
    }
    public boolean removerGenero(String genero) {
        if (generos.contains(genero)) {
            generos.remove(genero);
            return true;
        }
        return false;
    }

    // Sortar as listas
    public void sortArtistas(boolean reverse){
        artistas.sort((a1, a2) -> a1.getNome().compareTo(a2.getNome()));
        if(reverse){
            Collections.reverse(artistas);
        }
    }

    public void sortAlbuns(boolean reverse){
        albuns.sort((a1, a2) -> a1.compareTo(a2));
        if(reverse){
            Collections.reverse(albuns);
        }
    }

    public void sortGeneros(boolean reverse){
        generos.sort((g1, g2) -> g1.compareTo(g2));
        if(reverse){
            Collections.reverse(generos);
        }
    }

    // Getters e setters
    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public List<Artista> getArtistas() {
        return artistas;
    }

    public void setArtista(List<Artista> artistas) {
        this.artistas = artistas;
    }

    public List<String> getAlbuns() {
        return albuns;
    }

    public void setAlbuns(List<String> albuns) {
        this.albuns = albuns;
    }

    public int getDuracao() {
        return duracao;
    }

    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }

    public List<String> getGeneros() {
        return generos;
    }

    public void setGeneros(List<String> generos) {
        this.generos = generos;
    }

    public String getLetra() {
        return letra;
    }

    public void setLetra(String letra) {
        this.letra = letra;
    }

    public String getLancamento() {
        return lancamento;
    }

    public void setLancamento(String lancamento) {
        this.lancamento = lancamento;
    }

    // Equals e toString
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Musica other = (Musica) obj;
        if (titulo == null) {
            if (other.titulo != null)
                return false;
        } else if (!titulo.equals(other.titulo))
            return false;
        if (artistas == null) {
            if (other.artistas != null)
                return false;
        } else if (!artistas.equals(other.artistas))
            return false;
        if (albuns == null) {
            if (other.albuns != null)
                return false;
        } else if (!albuns.equals(other.albuns))
            return false;
        if (duracao != other.duracao)
            return false;
        if (generos == null) {
            if (other.generos != null)
                return false;
        } else if (!generos.equals(other.generos))
            return false;
        if (letra == null) {
            if (other.letra != null)
                return false;
        } else if (!letra.equals(other.letra))
            return false;
        if (lancamento == null) {
            if (other.lancamento != null)
                return false;
        } else if (!lancamento.equals(other.lancamento))
            return false;
        return true;
    }

    @Override
    public String toString() {
        StringBuffer str = new StringBuffer();
        str.append(titulo);
        str.append("\nArtista(s): ");
        artistas.forEach(artista -> {
            str.append(artista.getNome() + ", ");
        });
        str.append("\nAlbuns(s): ");
        albuns.forEach(album -> {
            str.append(album + ", ");
        });
        str.append("\nDuracao:" + duracao/3600 + ":" + (duracao%3600)/60 + ":" + duracao%60);
        str.append("\nGenero(s): "); 
        generos.forEach(genero -> {
            str.append(genero + ", ");
        });   
        str.append("Lancamento: " + lancamento + "\n");    

        return str.toString();
    }
}
