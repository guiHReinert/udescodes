package ex2.negocio;

import ex2.dados.Contato;
import ex2.persistencia.ContatoDAO;

import java.util.List;
import java.util.Map;

public class ListaTelefonica {
    private ContatoDAO contatoDAO = new ContatoDAO();

    public ListaTelefonica() {

    }

    public void adicionarContato(Contato contato) {
        contatoDAO.insert(contato);
    }

    public void removerContato(Contato contato) {
        contatoDAO.delete(contato);
    }

    public List<Contato> buscarContatos(char letra) {
        return contatoDAO.getAll().get(Character.toUpperCase(letra));
    }

    public Map<Character, List<Contato>> listarContatos() {
        return contatoDAO.getAll();
    }

    // Reduzi o antigo atributo <contatos> em um mapa para printar os contatos
    public String toString() {
        StringBuffer str = new StringBuffer();
        Map<Character, List<Contato>> contatos = contatoDAO.getAll();
        contatos.forEach((chave, valores) -> {
            str.append(chave + ":\n");
            valores.forEach((valor) -> {
                str.append(valor + ":\n");
            });
        });
        return "ListaTelefonica [contatos=" + contatos + "]";
    }
}
