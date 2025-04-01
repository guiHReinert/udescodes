package apresentacao;

import dados.*;
import negocio.*;

import java.util.Scanner;

public class Principal {
	private static Scanner scan = new Scanner(System.in);
	private static ReservaPassagem reserva = new ReservaPassagem();
	
	public static void main(String[] args) {
		int ans = 0;
		while(ans != 5){
			System.out.printf("""
				\n		SISTEMA DE RESERVA DE PASSAGENS AÉREAS - SIRPA
							
				1 - Fazer Reserva
				2 - Cadastrar nova Cidade
				3 - Cadastrar novo Cliente
				4 - Mostrar Reservas
				5 - Sair do SIRPA
				 >>""");
			ans = Integer.parseInt(scan.nextLine());
			System.out.println("");

			if(ans == 1){
				if(reserva.getNumCidades() > 0){
					if(reserva.getNumClientes() > 0){
						fazerReserva();
					}
					else{System.out.println(" Nao ha clientes cadastrados.");}
				}
				else{System.out.println(" Nao ha cidades cadastradas.");}
			}
			else if(ans == 2){
				cadastrarCidade();
			}
			else if(ans == 3){
				cadastrarCliente();
			}
			else if(ans == 4){
				if(reserva.getNumClientes() > 0){
					mostrarReservas();
				}
				else{System.out.println(" Nao ha clientes cadastrados.");}
			}
			else if(ans == 5){
				System.out.println(" Volte sempre!");
				scan.close();
			}
			else{
				System.out.println(" Digite uma opcao valida.");
			}
		}
	}
	
	public static void fazerReserva() {
		Reserva ida = new Reserva();
		Cliente cliente = new Cliente();

		int ans=0;
		// Escolher cliente
		for(int j=0; j < reserva.getNumClientes(); j++){
			if(reserva.mostrarClientes()[j] != null){
				System.out.printf("[%d] ", j+1);
				System.out.println(reserva.mostrarClientes()[j].toString());
			}
		}
		while(true){
			System.out.printf("\nDigite o indice do cliente registrado acima: ");
			ans = Integer.parseInt(scan.nextLine());
			if(ans > 0 && ans <= reserva.getNumClientes()+1){
				cliente = reserva.mostrarClientes()[ans-1];
				break;
			}
			else{
				System.out.println(" Digite uma opcao valida.");
				continue;
			}
		}
		// Cria a reserva, caso ha espaço disponivel
		if(cliente.getNumReservas() < cliente.getReservas().length) {
			Cidade origem = new Cidade();
			Cidade destino = new Cidade();

			ans = 0;
			System.out.println("");
			for(int j=0; j < reserva.getNumCidades(); j++){
				if(reserva.mostrarCidades()[j] != null){
					System.out.printf("[%d] ", j+1);
					System.out.println(reserva.mostrarCidades()[j].toString());
				}
			}
			while(true){ // Escolher cidade de origem
				System.out.printf("\nDigite o indice da cidade de ORIGEM acima: ");
				ans = Integer.parseInt(scan.nextLine());
				if(ans > 0 && ans <= reserva.getNumCidades()+1){
					origem = reserva.mostrarCidades()[ans-1];
					ida.setCidadeOrigem(origem);
					break;
				}
				else{
					System.out.println(" Digite uma opcao valida.");
					continue;
				}
			}
			while(true){ // Escolher cidade de Destino
				System.out.printf("Digite o indice da cidade de DESTINO acima: ");
				ans = Integer.parseInt(scan.nextLine());
				if(ans > 0 && ans <= reserva.getNumCidades()+1){
					destino = reserva.mostrarCidades()[ans-1];
					ida.setCidadeDestino(destino);
					break;
				}
				else{
					System.out.println(" Digite uma opcao valida.");
					continue;
				}
			}
			System.out.println("Digite o numero da reserva: ");
			ida.setNumReserva(Integer.parseInt(scan.nextLine()));
			System.out.println("Digite a data do voo (dd/mm/aaaa): ");
			ida.setDataVoo(scan.nextLine());
			System.out.println("Digite a hora do voo (hh:mm): ");
			ida.setHoraVoo(scan.nextLine());
			System.out.println("Digite o preco da passagem: ");
			ida.setPreco(Float.parseFloat(scan.nextLine()));
			System.out.println("Digite a classe do voo (economica/executiva): ");
			ida.setClasseVoo(scan.nextLine());
			System.out.println("Digite o numero da poltrona: ");
			ida.setPoltrona(Integer.parseInt(scan.nextLine()));

			System.out.println("Ida e volta? (true/false): ");
			ida.setIdaEVolta(Boolean.parseBoolean(scan.nextLine()));
			if(ida.isIdaEVolta()){
				Reserva volta = new Reserva();

				System.out.println("\n Cadastro da reserva de volta:\n");
				System.out.println("Digite a data do voo (dd/mm/aaaa): ");
				volta.setDataVoo(scan.nextLine());
				System.out.println("Digite a hora do voo (hh:mm): ");
				volta.setHoraVoo(scan.nextLine());
				System.out.println("Digite o preco da passagem: ");
				volta.setPreco(Float.parseFloat(scan.nextLine()));
				System.out.println("Digite a classe do voo (economica/executiva): ");
				volta.setClasseVoo(scan.nextLine());
				System.out.println("Digite o numero da poltrona: ");
				volta.setPoltrona(Integer.parseInt(scan.nextLine()));

				reserva.reservarVolta(cliente, ida, volta);
			}
			reserva.reservarIda(cliente, ida);
			System.out.printf("Reserva realizada com sucesso!\n");
		}
		else{
			System.out.printf(" Limite de reservas atingido para %s.\n", cliente.getNome());
		}


	}
	
	public static void cadastrarCidade() {
		Cidade cidade = new Cidade();

		System.out.printf("Digite o nome da cidade: ");
		cidade.setNome(scan.nextLine());
		System.out.printf("Digite o estado da cidade: ");
		cidade.setEstado(scan.nextLine());
		reserva.cadastrarCidade(cidade);

		System.out.printf("Nova cidade cadastrada com sucesso.\n");
	}

	public static void cadastrarCliente() {
		Cliente cliente = new Cliente();

		System.out.printf("Digite o nome do cliente: ");
		cliente.setNome(scan.nextLine());
		System.out.printf("Digite o CPF do cliente: ");
		cliente.setCpf(Integer.parseInt(scan.nextLine()));
		System.out.printf("Digite o endereco do cliente: ");
		cliente.setEndereco(scan.nextLine());
		System.out.printf("Digite o telefone do cliente: ");
		cliente.setTelefone(Integer.parseInt(scan.nextLine()));
		reserva.cadastrarCliente(cliente);

		System.out.printf("Novo cliente cadastrado com sucesso.\n");
	}
	
	public static void mostrarReservas() {
		Cliente cliente = new Cliente();

		int ans=0;
		// Escolher cliente
		for(int j=0; j < reserva.getNumClientes(); j++){
			if(reserva.mostrarClientes()[j] != null){
				System.out.printf("[%d] ", j+1);
				System.out.println(reserva.mostrarClientes()[j].toString());
			}
		}
		while(true){
			System.out.printf("\nDigite o indice do cliente registrado acima: ");
			ans = Integer.parseInt(scan.nextLine());
			if(ans > 0 && ans <= reserva.getNumClientes()+1){
				cliente = reserva.mostrarClientes()[ans-1];
				break;
			}
			else{
				System.out.println(" Digite uma opcao valida.");
				continue;
			}
		}
		System.out.println("");
		if(cliente.getNumReservas() > 0){
			for(int j=0; j < cliente.getNumReservas(); j++){
				Reserva[] reservas = reserva.mostrarReservas(cliente.getCpf());
				if(reservas[j] != null){
					System.out.printf("[%d] ", j+1);
					System.out.println(reservas[j].toString());
				}
			}
		}
		else{
			System.out.println(" Nao ha reservas cadastradas para o cliente.");
		}
	}
}
