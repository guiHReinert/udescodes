package ex1.negocio;

import ex1.dados.Pessoa;
import ex1.persistencia.PessoaDAO;

import java.util.List;

public class Sistema {
    private PessoaDAO pessoaDAO = new PessoaDAO();

    public void adicionarPessoa(Pessoa pessoa) {
        pessoaDAO.insert(pessoa);
    }

    public void removerPessoa(Pessoa pessoa) {
        pessoaDAO.delete(pessoa);
    }

    public List<Pessoa> getList() {
        return pessoaDAO.getAll();
    }
}
