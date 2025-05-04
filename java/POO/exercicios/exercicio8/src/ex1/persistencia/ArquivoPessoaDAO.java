package ex1.persistencia;

import ex1.dados.Pessoa;

import java.util.List;
import java.util.LinkedList;

public class ArquivoPessoaDAO {
    private final String path = "src/ex1/files/pessoas.csv";
    private static EditorTexto arquivo = new EditorTexto();

    // Converte uma pessoa em uma string no formato CSV
    private String toCSV(Pessoa pessoa) {
        String p = new String();

        p += pessoa.getNome() + ", ";
        p += pessoa.getIdade() + ", ";
        p += pessoa.getAltura() + ", ";
        p += pessoa.getMassa();

        return p;
    }

    // Converte uma string no formato CSV em uma pessoa
    private Pessoa fromCSV(String persona) {
        String[] atributos = persona.split(", ");

        Pessoa pessoa = new Pessoa();
        pessoa.setNome(atributos[0]);
        pessoa.setIdade(Integer.parseInt(atributos[1]));
        pessoa.setAltura(Float.parseFloat(atributos[2]));
        pessoa.setMassa(Float.parseFloat(atributos[3]));

        return pessoa;
    }

    // Converte uma lista de pessoas em uma lista de strings no formato CSV
    private List<String> listaPessoaToString(List<Pessoa> pessoas) {
        List<String> listaStr = new LinkedList<>();

        for (Pessoa pessoa : pessoas) {
            listaStr.add(toCSV(pessoa));
        }
        return listaStr;
    }

    // Converte uma lista de strings no formato CSV em uma lista de pessoas
    private List<Pessoa> stringToListaPessoa(List<String> arquivo) {
        List<Pessoa> listaPessoas = new LinkedList<>();

        for (String str : arquivo) {
            listaPessoas.add(fromCSV(str));
        }
        return listaPessoas;
    }

    // Converte a lista de strings no formato CSV (obtida no arquivo) em uma lista
    // de pessoas
    public List<Pessoa> lePessoasArquivo() {
        return stringToListaPessoa(arquivo.leTexto(path));
    }

    // Salva a lista de pessoas em uma lista de strings no formato CSV no arquivo
    public void salvaPessoasArquivo(List<Pessoa> pessoas) {
        arquivo.gravarTexto(path, listaPessoaToString(pessoas));
    }

    // Salva uma pessoa em uma string no formato CSV no arquivo
    public void salvaPessoaArquivo(Pessoa pessoa) {
        arquivo.gravarTexto(path, toCSV(pessoa));
    }
}
