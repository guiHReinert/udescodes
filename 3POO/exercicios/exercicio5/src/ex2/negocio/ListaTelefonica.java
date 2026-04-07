package ex2.negocio;

import ex2.dados.Contato;
import java.util.Collections;
import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;

public class ListaTelefonica {
    private Map<Character, List<Contato>> contatos;

    public ListaTelefonica() {
        contatos = new HashMap<Character, List<Contato>>();
        for (char c = 'A'; c <= 'Z'; c++) {
            contatos.put(c, new LinkedList<Contato>());
        }
    }

    public void adicionarContato(Contato contato) {
        char inicial = contato.getNome().toUpperCase().charAt(0);
        List<Contato> lista = contatos.get(inicial);
        lista.add(contato);
        Collections.sort(lista, (c1, c2) -> c1.getNome().compareTo(c2.getNome()));
    }

    public void removerContato(Contato contato) {
        char inicial = contato.getNome().toUpperCase().charAt(0);
        List<Contato> lista = contatos.get(inicial);
        lista.remove(contato);
    }

    public List<Contato> buscarContatos(char letra) {
        return contatos.get(Character.toUpperCase(letra));
    }

    public Map<Character, List<Contato>> buscarContatos() {
        return contatos;
    }

    public String toString() {
        StringBuffer str = new StringBuffer();
        contatos.forEach((chave, valores) -> {
            str.append(chave + ":\n");
            valores.forEach((valor) -> {
                str.append(valor + ":\n");
            });
        });
        return "ListaTelefonica [contatos=" + contatos + "]";
    }
}
