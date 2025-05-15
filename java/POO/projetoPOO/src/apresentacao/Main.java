package apresentacao;

import negocio.Sistema;
import dados.Artista;
import dados.Musica;    
import dados.Playlist;
import dados.Usuario;

import java.util.Scanner;

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {
    private final Sistema sistema = new Sistema();
    private final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        
    }

    public void menu(){
        int ans = -1;
        System.out.println("    Projeto Orientado a Objetos - MUSICAS");
        System.out.println("Digite o indice respectivo a opcao desejada:");
        System.out.println("1 - Cadastrar usuario:");
        System.out.println("2 - Mudar o login");
        System.out.println("3 - Mostrar musicas");
        System.out.println("4 - Mostrar artistas");
        System.out.println("5 - Mostrar playlists");
        System.out.println("6 - MOdificar playlist");
        System.out.println("7 - Adicionar artista");
    }

    public void novoUsuario(){
        Usuario usuario = new Usuario();

        System.out.println("    CADASTRO DE USUARIO");
        System.out.println("Nome: ");
        String nome = scan.nextLine();
        usuario.setNome(scan.nextLine());
        System.out.println("Senha: ");
        usuario.setSenha(scan.nextLine());

        if(sistema.adicionarUsuario(usuario)){
            System.out.println("Novo usuario cadastrado.");
            return;
        }
        else{
            System.out.println("Usuario ja cadastrado.");
        }
    }

    // public boolean login(){
    //     Usuario usuario = new Usuario();
    //     System.out.println("    LOGIN DE USUARIO");
    //     System.out.println("Nome: ");
    //     usuario.setNome(scan.nextLine());
    //     for(Usuario user : sistema.getUsuarios()){
    //         if(usuario.getNome().equals(user.getNome())){
    //         }
    //     }
    //     System.out.println("Senha: ");
    //     if(scan.nextLine().equals(usuario.getSenha())){
    //     }
    // }
}
