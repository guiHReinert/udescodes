package dados;

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

public class Artista extends Pessoa {
    private List<Musica> musicas = new ArrayList<>();
    private List<String> albuns = new LinkedList<>();

    public Artista() {}

    // Adicionar elementos nas listas
    public boolean adicionarMusica(Musica musica) {
        if (!musicas.contains(musica)) {
            musicas.add(musica);
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

    // Remover elementos das listas
    public boolean removerMusica(Musica musica) {
        if (musicas.contains(musica)) {
            musicas.remove(musica);
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

    // Sortar as listas
    // Funcao necessaria para sortMusicas(CategoriaSort)
    private String listToString(List<?> list) {
        StringBuffer sb = new StringBuffer();
        for (Object elemento : list) {
            sb.append(elemento.toString()).append(", ");
        }
        return sb.toString();
    }

    public void sortMusicas(CategoriaSort categoria, boolean reverse) {
        switch (categoria) {
            case NOME_MUSICA:
                musicas.sort((m1, m2) -> m1.getTitulo().compareTo(m2.getTitulo()));
                break;
            /*
            Os sorts abaixo se baseiam nas listas de cada musica. Portanto,
            estah se comparando cada elemento de uma lista de uma musica
            convertida em uma unica string para sortar
            */
            case NOME_ARTISTA:
                musicas.sort((m1, m2) -> {
                    List<String> str1 = new LinkedList<String>();
                    List<String> str2 = new LinkedList<String>();
                    m1.getArtistas().forEach(artista -> str1.add(artista.getNome()));
                    m2.getArtistas().forEach(artista -> str2.add(artista.getNome()));

                    return listToString(str1).compareTo(listToString(str2));
                });
                break;
            case NOME_ALBUM:
                musicas.sort((m1, m2) -> {
                    List<String> str1 = new LinkedList<String>();
                    List<String> str2 = new LinkedList<String>();
                    m1.getAlbuns().forEach(album -> str1.add(album));
                    m2.getAlbuns().forEach(album -> str2.add(album));

                    return listToString(str1).compareTo(listToString(str2));
                });
                break;
            case DURACAO:
                musicas.sort((m1, m2) -> m1.getDuracao() <= m2.getDuracao() ? 1 : 0);
                break;
            case GENERO:
                musicas.sort((m1, m2) -> {
                    List<String> str1 = new LinkedList<String>();
                    List<String> str2 = new LinkedList<String>();
                    m1.getGeneros().forEach(genero -> str1.add(genero));
                    m2.getGeneros().forEach(genero -> str2.add(genero));

                    return listToString(str1).compareTo(listToString(str2));
                });
            case LANCAMENTO:
                musicas.sort((m1, m2) -> m1.getDuracao() <= m2.getDuracao() ? 1 : 0);
            default:
                break;

        }
        if(reverse){
            Collections.reverse(musicas);
        }
    }

    public void sortAlbuns(boolean reverse) {
        albuns.sort((a1, a2) -> a1.compareTo(a2));
        if(reverse){
            Collections.reverse(albuns);
        }
    }

    // Getters e setters
    public List<Musica> getMusicas() {
        return musicas;
    }

    public void setMusicas(List<Musica> musicas) {
        this.musicas = musicas;
    }

    public List<String> getAlbuns() {
        return albuns;
    }

    public void setAlbuns(List<String> albuns) {
        this.albuns = albuns;
    }
}
