package negocio;

import dados.Cidade;
import dados.Cliente;
import dados.Reserva;

import java.util.Scanner;

public class ReservaPassagem {
	private Cidade[] listaDeCidades = new Cidade[10];
	private int numCidades = 0;
	private Cliente[] listaDeClientes = new Cliente[10];
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

	}
	public void reservarVolta(Cliente cliente, Reserva ida, Reserva volta){
		if(cliente.getNumReservas() < cliente.getReservas().length) {
			if(ida.isIdaEVolta()){
				Scanner scanner = new Scanner(System.in);
				Cidade cidadeDestino = new Cidade();
				volta.setVolta(true);

				// Numero da reserva de volta eh o mesmo que o de ida
				volta.setNumReserva(ida.getNumReserva());
				System.out.println("Digite a data do voo (dd/mm/aaaa): ");
				volta.setDataVoo(scanner.nextLine());
				System.out.println("Digite a hora do voo (hh:mm): ");
				volta.setHoraVoo(scanner.nextLine());
				System.out.println("Digite o preco da passagem: ");
				volta.setPreco(Float.parseFloat(scanner.nextLine()));
				System.out.println("Digite a classe do voo (economica/executiva): ");
				volta.setClasseVoo(scanner.nextLine());
				System.out.println("Digite o numero da poltrona: ");
				volta.setPoltrona(Integer.parseInt(scanner.nextLine()));
				
				System.out.println("Digite o nome da cidade de origem: ");
				cidadeDestino.setNome(scanner.nextLine());
				System.out.println("Digite o estado da cidade de origem: ");
				cidadeDestino.setEstado(scanner.nextLine());
				volta.setCidade(cidadeDestino);

				scanner.close();
				cliente.reservarVolta(ida, volta);
				System.out.printf("Reserva realizada com sucesso!\n");
			}
			else{
				System.out.println(" Nao foi confirmada a opcao de volta para esta reserva.");
			}
		}
		else{
			System.out.println(" Limite de reservas atingido.");
		}


	}
}
