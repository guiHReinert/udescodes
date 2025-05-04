package ex2.persistencia;

import ex2.dados.Contato;

import java.util.Map;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class ContatoDAO {
    private ArquivoContatoDAO arquivoContatoDAO = new ArquivoContatoDAO();

    public void insert(Contato contato) {
        arquivoContatoDAO.salvaContatoArquivo(contato);
    }

    public void delete(Contato contato) {
        List<Contato> contatos = arquivoContatoDAO.leContatosArquivo();
        contatos.remove(contato);
        arquivoContatoDAO.salvaContatosArquivo(contatos);
    }

    // Cria e retorna o Map<Character, List<Contato>> com os contatos mapeados
    // pelas letras
    public Map<Character, List<Contato>> getAll() {
        Map<Character, List<Contato>> contatos = new HashMap<Character, List<Contato>>();
        // Cria um novo mapa vazio com as chaves de A a Z
        for (char c = 'A'; c <= 'Z'; c++) {
            contatos.put(c, new LinkedList<Contato>());
        }

        // Para cada letra-chave do mapa, adiciona os contatos que começarem por ela
        contatos.forEach((key, list) -> {
            for (Contato contato : arquivoContatoDAO.leContatosArquivo()) {
                if (contato.getNome().toUpperCase().charAt(0) == key) {
                    list.add(contato);
                }
            }
        });
        return contatos;
    }
}
