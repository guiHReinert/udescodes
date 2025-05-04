package ex1.persistencia;

import java.util.List;

import ex1.dados.Pessoa;

public class PessoaDAO {
    private ArquivoPessoaDAO arquivoPessoaDAO = new ArquivoPessoaDAO();

    public void insert(Pessoa pessoa) {
        arquivoPessoaDAO.salvaPessoaArquivo(pessoa);
    }

    public void delete(Pessoa pessoa) {
        List<Pessoa> pessoas = arquivoPessoaDAO.lePessoasArquivo();
        pessoas.remove(pessoa);
        arquivoPessoaDAO.salvaPessoasArquivo(pessoas);
    }

    public List<Pessoa> getAll() {
        return arquivoPessoaDAO.lePessoasArquivo();
    }
}
