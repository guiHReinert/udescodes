package dados;

import java.util.Arrays;

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
	
	public void reservaIda(Reserva reserva) {
		reservas[numReservas] = reserva;
		numReservas++;
	}
	public void reservarVolta(Reserva ida, Reserva volta) {
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

	@Override
	public String toString() {
		return "Cliente [cpf=" + cpf + ", nome=" + nome + ", endereco=" + endereco + ", telefone=" + telefone
				+ ", reservas=" + Arrays.toString(reservas) + ", numReservas=" + numReservas + "]";
	}
}
