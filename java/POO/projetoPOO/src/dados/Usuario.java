package dados;

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

public class Usuario extends Pessoa{
    private int idade;
    private String email;
    private String senha;
    private List<Musica> favoritas = new ArrayList<>();

    public Usuario(){}

    public Usuario(String nome, int idade, String email, String senha){
        super(nome);
        this.idade = idade;
        this.email = email;
        this.senha = senha;
    }

    // Adicionar elementos nas listas
    public boolean adicionarMusicaFavoritada(Musica musica) {
        if (!favoritas.contains(musica)) {
            favoritas.add(musica);
            return true;
        }
        return false;
    }

    // Remover elementos das listas
    public boolean removerMusicaFavoritada(Musica musica) {
        if (favoritas.contains(musica)) {
            favoritas.remove(musica);
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

    public void sortFavoritas(CategoriaSort categoria, boolean reverse){
        switch (categoria) {
            case NOME_MUSICA:
                favoritas.sort((m1, m2) -> m1.getTitulo().compareTo(m2.getTitulo()));
                break;
            /*
            Os sorts abaixo se baseiam nas listas de cada musica. Portanto,
            estah se comparando cada elemento de uma lista de uma musica
            convertida em uma unica string para sortar
            */
            case NOME_ARTISTA:
                favoritas.sort((m1, m2) -> {
                    List<String> str1 = new LinkedList<String>();
                    List<String> str2 = new LinkedList<String>();
                    m1.getArtistas().forEach(artista -> str1.add(artista.getNome()));
                    m2.getArtistas().forEach(artista -> str2.add(artista.getNome()));

                    return listToString(str1).compareTo(listToString(str2));
                });
                break;
            case NOME_ALBUM:
                favoritas.sort((m1, m2) -> {
                    List<String> str1 = new LinkedList<String>();
                    List<String> str2 = new LinkedList<String>();
                    m1.getAlbuns().forEach(album -> str1.add(album));
                    m2.getAlbuns().forEach(album -> str2.add(album));

                    return listToString(str1).compareTo(listToString(str2));
                });
                break;
            case DURACAO:
                favoritas.sort((m1, m2) -> m1.getDuracao() <= m2.getDuracao() ? 1 : 0);
                break;
            case GENERO:
                favoritas.sort((m1, m2) -> {
                    List<String> str1 = new LinkedList<String>();
                    List<String> str2 = new LinkedList<String>();
                    m1.getGeneros().forEach(genero -> str1.add(genero));
                    m2.getGeneros().forEach(genero -> str2.add(genero));

                    return listToString(str1).compareTo(listToString(str2));
                });
            case LANCAMENTO:
                favoritas.sort((m1, m2) -> m1.getDuracao() <= m2.getDuracao() ? 1 : 0);
            default:
                break;

        }
        if(reverse){
            Collections.reverse(favoritas);
        }

    }

    // Getters e setters
    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public List<Musica> getFavoritadas() {
        return favoritas;
    }

    public List<Musica> getFavoritas() {
        return favoritas;
    }
    
    // Equals e toString
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!super.equals(obj))
            return false;
        if (getClass() != obj.getClass())
            return false;
        Usuario other = (Usuario) obj;
        if (idade != other.idade)
            return false;
        if (email == null) {
            if (other.email != null)
                return false;
        } else if (!email.equals(other.email))
            return false;
        if (senha == null) {
            if (other.senha != null)
                return false;
        } else if (!senha.equals(other.senha))
            return false;
        if (favoritas == null) {
            if (other.favoritas != null)
                return false;
        } else if (!favoritas.equals(other.favoritas))
            return false;
        return true;
    }

    
    
}
