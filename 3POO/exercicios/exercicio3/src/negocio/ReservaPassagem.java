package negocio;

import dados.Cidade;
import dados.Cliente;
import dados.Reserva;

public class ReservaPassagem {
	private Cidade[] listaDeCidades = new Cidade[9];
	private int numCidades = 0;
	private Cliente[] listaDeClientes = new Cliente[9];
	private int numClientes = 0;

	public Cidade[] mostrarCidades() {
		return listaDeCidades;
	}
	public void cadastrarCidade(Cidade cidade) {
		if(numCidades < listaDeCidades.length) {
			listaDeCidades[numCidades] = cidade;
			numCidades++;
		}
		else{
			System.out.println(" Limite de cidades atingido.");
		}
	}

	public int getNumCidades() {
		return numCidades;
	}
	public void setNumCidades(int numCidades) {
		this.numCidades = numCidades;
	}
	
	public Cliente[] mostrarClientes() {
		return listaDeClientes;
	}
	public void cadastrarCliente(Cliente cliente) {
		if(numClientes < listaDeClientes.length) {
			listaDeClientes[numClientes] = cliente;
			numClientes++;
		}
		else{
			System.out.println(" Limite de clientes atingido.");
		}		
	}

	public int getNumClientes() {
		return numClientes;
	}
	public void setNumClientes(int numClientes) {
		this.numClientes = numClientes;
	}

	public Reserva[] mostrarReservas(int cpfCliente) {
		for(int j=0; j<numClientes; j++){
			if(cpfCliente == listaDeClientes[j].getCpf()){
				return listaDeClientes[j].getReservas();
			}
		}
		return null;
	}

	public void reservarIda(Cliente cliente, Reserva reserva) {
		cliente.reservarIda(reserva);
	}
	public void reservarVolta(Cliente cliente, Reserva ida, Reserva volta){
		cliente.reservarVolta(ida, volta);
	}
}
