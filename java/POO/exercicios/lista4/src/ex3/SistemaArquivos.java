package ex3;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class SistemaArquivos {
    private Map<String,List<Arquivo>> diretorios = new HashMap<>();
    
    public SistemaArquivos(){}

    public void criarDocumento(String nome, String diretorio, String texto) throws NomeInvalidoException{
        Documento documento = new Documento(nome, texto);

        if(!diretorios.containsKey(diretorio)){
            diretorios.put(diretorio, new ArrayList<Arquivo>());
        }

        diretorios.get(diretorio).add(documento);
    }

    public void criarMusica(String nome, String diretorio, int duracao) throws NomeInvalidoException{
        Musica musica = new Musica(nome, duracao);
        
        if(!diretorios.containsKey(diretorio)){
            diretorios.put(diretorio, new ArrayList<Arquivo>());
        }

        diretorios.get(diretorio).add(musica);
    }

    public void criarVideo(String nome, String diretorio, Qualidade qualidade) throws NomeInvalidoException{
        Video video = new Video(nome, qualidade);

        if(!diretorios.containsKey(diretorio)){
            diretorios.put(diretorio, new ArrayList<Arquivo>());
        }

        diretorios.get(diretorio).add(video);
    }

    public Map<String, List<Arquivo>> getDiretorios() {
        return diretorios;
    }

    public void setDiretorios(Map<String, List<Arquivo>> diretorios) {
        this.diretorios = diretorios;
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();

        diretorios.forEach((diretorio, arquivos) -> {
            buffer.append("\n" + diretorio + ":\n");
            arquivos.forEach(arquivo ->
                buffer.append("\n\t" + arquivo.toString() + "\n"));
        });

        return buffer.toString();
    }
}
