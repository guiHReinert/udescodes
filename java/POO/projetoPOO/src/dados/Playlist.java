package dados;

import java.util.List;
import java.util.ArrayList;

public class Playlist {
    private String nome;
    private String descricao;
    private List<Musica> musicas = new ArrayList<>();
    private int duracao; // em segundos

    public Playlist() {}

    public void adicionarMusica(Musica musica) {
        if (!musicas.contains(musica)) {
            musicas.add(musica);
            duracao += musica.getDuracao();
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public List<Musica> getMusicas() {
        return musicas;
    }

    public void setMusicas(List<Musica> musicas) {
        this.musicas = musicas;
    }

    public int getDuracao() {
        return duracao;
    }

    public void setDuracao(int duracao) {
        this.duracao = duracao;
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
        Playlist other = (Playlist) obj;
        if (nome == null) {
            if (other.nome != null)
                return false;
        } else if (!nome.equals(other.nome))
            return false;
        if (descricao == null) {
            if (other.descricao != null)
                return false;
        } else if (!descricao.equals(other.descricao))
            return false;
        if (musicas == null) {
            if (other.musicas != null)
                return false;
        } else if (!musicas.equals(other.musicas))
            return false;
        if (duracao != other.duracao)
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Playlist [nome=" + nome + ", descricao=" + descricao + ", musicas=" + musicas + ", duracao=" + duracao
                + "]";
    }
}
