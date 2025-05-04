package ex2.persistencia;

import ex2.dados.Contato;

import java.util.List;
import java.util.LinkedList;

public class ArquivoContatoDAO {
    private final String path = "src/ex2/files/contatos.csv";
    private static EditorTexto arquivo = new EditorTexto();

    // Converte um contato em uma string no formato CSV
    private String toCSV(Contato contato) {
        String p = new String();

        p += contato.getNome() + ", ";
        p += contato.getTelefone();

        return p;
    }

    // Converte uma string no formato CSV em um contato
    private Contato fromCSV(String c) {
        String[] atributos = c.split(", ");

        Contato contato = new Contato();
        contato.setNome(atributos[0]);
        contato.setTelefone(Integer.parseInt(atributos[1]));

        return contato;
    }

    // Converte uma lista de contatos em uma lista de strings no formato CSV
    private List<String> listaContatoToString(List<Contato> contatos) {
        List<String> listaStr = new LinkedList<>();

        for (Contato contato : contatos) {
            listaStr.add(toCSV(contato));
        }
        return listaStr;
    }

    // Converte uma lista de strings no formato CSV em uma lista de contatos
    private List<Contato> stringToListaContato(List<String> arquivo) {
        List<Contato> listaContatos = new LinkedList<>();

        for (String str : arquivo) {
            listaContatos.add(fromCSV(str));
        }
        return listaContatos;
    }

    // Converte a lista de strings no formato CSV (obtida no arquivo) em uma lista
    // de contatos
    public List<Contato> leContatosArquivo() {
        return stringToListaContato(arquivo.leTexto(path));
    }

    // Salva a lista de contatos em uma lista de strings no formato CSV no arquivo
    public void salvaContatosArquivo(List<Contato> contatos) {
        arquivo.gravarTexto(path, listaContatoToString(contatos));
        arquivo.sortarTexto(path);
    }

    // Salva um contato em uma string no formato CSV no arquivo
    public void salvaContatoArquivo(Contato contato) {
        arquivo.gravarTexto(path, toCSV(contato));
        arquivo.sortarTexto(path);
    }
}
