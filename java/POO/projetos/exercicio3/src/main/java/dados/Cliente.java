package dados;

public class Cliente {
	private int cpf;
	private String nome;
	private String endereco;
	private int telefone;
	
	private String getNome() {
		return nome;
	}
	private void setNome(String nome) {
		this.nome = nome;
	}
	private int getTelefone() {
		return telefone;
	}
	private void setTelefone(int telefone) {
		this.telefone = telefone;
	}
	private String getEndereco() {
		return endereco;
	}
	private void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	private int getCpf() {
		return cpf;
	}
	private void setCpf(int cpf) {
		this.cpf = cpf;
	}
	
	public String toString() {
		return "CPF: "+cpf+
				"\nNome: "+nome+
				"\nEndereco: "+endereco+
				"\nTelefone: "+telefone;
	}
	
	public void reservaIda(Reserva reserva) {
		
	}
	
	public void reservarVolta(Reserva ida, Reserva volta) {
		
	}
}
