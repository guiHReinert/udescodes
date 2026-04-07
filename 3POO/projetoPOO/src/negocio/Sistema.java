package negocio;

import dados.*;

import java.util.List;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.LinkedList;

import javazoom.jl.player.Player;
import javazoom.jl.decoder.JavaLayerException;

public class Sistema {
    private List<Artista> artistas = new ArrayList<>();
    private List<Usuario> usuarios = new ArrayList<>();
    private List<Musica> musicas = new LinkedList<>();
    private List<Playlist> playlists = new ArrayList<>();

    public Sistema() {}

    // Adicionar objetos nas listas
    public boolean adicionarArtista(Artista artista) {
        if(!artistas.contains(artista)){
            artistas.add(artista);
            return true;
        }
        return false;
    }
    
    public boolean adicionarUsuario(Usuario usuario) {
        if(!usuarios.contains(usuario)){
            usuarios.add(usuario);
            return true;
        }
        return false;
    }

    public boolean adicionarMusica(Musica musica) {
        if(!musicas.contains(musica)){
            musicas.add(musica);
            return true;
        }
        return false;
    }

    public boolean adicionarPlaylist(Playlist playlist) {
        if(!playlists.contains(playlist)){
            playlists.add(playlist);
            return true;
        }
        return false;
    }

    // Remover objetos das listas
    public boolean removerArtista(Artista artista){
        if(artistas.contains(artista)){
            artistas.remove(artista);
            return true;
        }
        return false;
    }

    public boolean removerUsuario(Usuario usuario){
        if(usuarios.contains(usuario)){
            usuarios.remove(usuario);
            return true;
        }
        return false;
    }

    public boolean removerMusica(Musica musica){
        if(musicas.contains(musica)){
            musicas.remove(musica);
            return true;
        }
        return false;
    }

    public boolean removerPlaylist(Playlist playlist){
        if(playlists.contains(playlist)){
            playlists.remove(playlist);
            return true;
        }
        return false;
    }

    // Importar musica
    public void importarMusica(String path) {
        try {
            FileInputStream fileInputStream = new FileInputStream("musica.mp3");
            Player player = new Player(fileInputStream);
            System.out.println("Song is playing...");
            player.play(300);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (JavaLayerException e) {
        }
    }

    // Getters e setters 
    public List<Artista> getArtistas() {
        return artistas;
    }

    public List<Usuario> getUsuarios() {
        return usuarios;
    }

    public List<Musica> getMusicas() {
        return musicas;
    }

    public List<Playlist> getPlaylists() {
        return playlists;
    }
}
