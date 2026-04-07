package dados;

public class Cliente {
	private int cpf;
	private String nome;
	private String endereco;
	private int telefone;
	private Reserva[] reservas = new Reserva[9];
	private int numReservas = 0;
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getTelefone() {
		return telefone;
	}
	public void setTelefone(int telefone) {
		this.telefone = telefone;
	}
	public String getEndereco() {
		return endereco;
	}
	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	public int getCpf() {
		return cpf;
	}
	public void setCpf(int cpf) {
		this.cpf = cpf;
	}
	
	public void reservarIda(Reserva ida) {
		reservas[numReservas] = ida;
		numReservas++;
	}
	public void reservarVolta(Reserva ida, Reserva volta) {
		volta.setIdaEVolta(true);
		volta.setVolta(true);
		// Mesmo numero de reserva
		volta.setNumReserva(ida.getNumReserva());
		// Alternar as cidades de origem e de destino 
		volta.setCidadeOrigem(ida.getCidadeDestino());
		volta.setCidadeDestino(ida.getCidadeOrigem());
		ida.setReservaVolta(volta);
	}

	public Reserva[] getReservas() {
		return reservas;
	}

	public int getNumReservas() {
		return numReservas;
	}
	public void setNumReservas(int r) {
		numReservas = r;
	}

	public String toString() {
		return "CPF: "+cpf+
		"\nNome: "+nome+
		"\nEndereco: "+endereco+
		"\nTelefone: "+telefone+
		"\nReservas realizadas: "+numReservas+'\n';
	}
}
