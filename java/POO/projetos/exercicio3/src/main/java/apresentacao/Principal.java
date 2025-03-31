package apresentacao;

import dados.*;
import negocio.*;

import java.util.Scanner;

public class Principal {
	private static Scanner scan = new Scanner(System.in);
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		ReservaPassagem reserva = new ReservaPassagem();

		int ans = 0;
		while(ans != 5){
			System.out.printf("""
						SISTEMA DE RESERVA DE PASSAGENS AÉREAS - SIRPA
							
				1 - Fazer Reserva
				2 - Cadastrar novo Cliente
				3 - Cadastrar nova Cidade
				4 - Mostrar Reservas
				5 - Sair do SIRPA
				""");
			ans = Integer.parseInt(scan.nextLine());

			if(ans == 1){
				fazerReserva();
			}
			else if(ans == 2){
				cadastrarCliente();
			}
			else if(ans == 3){
				cadastrarCidade();
			}
			else if(ans == 4){
				mostrarReservas();
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
		if(cliente.getNumReservas() < cliente.getReservas().length) {
			Scanner scanner = new Scanner(System.in);
			Cidade cidadeOrigem = new Cidade();

			System.out.println("Digite o numero da reserva: ");
			reserva.setNumReserva(Integer.parseInt(scanner.nextLine()));
			System.out.println("Digite a data do voo (dd/mm/aaaa): ");
			reserva.setDataVoo(scanner.nextLine());
			System.out.println("Digite a hora do voo (hh:mm): ");
			reserva.setHoraVoo(scanner.nextLine());
			System.out.println("Digite o preco da passagem: ");
			reserva.setPreco(Float.parseFloat(scanner.nextLine()));
			System.out.println("Digite a classe do voo (economica/executiva): ");
			reserva.setClasseVoo(scanner.nextLine());
			System.out.println("Digite o numero da poltrona: ");
			reserva.setPoltrona(Integer.parseInt(scanner.nextLine()));
			System.out.println("Digite o nome da cidade de origem: ");
			cidadeOrigem.setNome(scanner.nextLine());
			System.out.println("Digite o estado da cidade de origem: ");
			cidadeOrigem.setEstado(scanner.nextLine());
			reserva.setCidade(cidadeOrigem);

			System.out.println("Ida e volta? (true/false): ");
			reserva.setIdaEVolta(Boolean.parseBoolean(scanner.nextLine()));
			scanner.close();

			reserva.setVolta(false);
			cliente.reservaIda(reserva);
			System.out.printf("Reserva realizada com sucesso!\n");
		}
		else{
			System.out.println(" Limite de reservas atingido.");
		}
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

		System.out.printf("Novo cliente cadastrado com sucesso.\n");
	}
	
	public static void cadastrarCidade() {
		Cidade cidade = new Cidade();

		System.out.printf("Digite o nome da cidade: ");
		cidade.setNome(scan.nextLine());
		System.out.printf("Digite o estado da cidade: ");
		cidade.setEstado(scan.nextLine());

		System.out.printf("Nova cidade cadastrada com sucesso.\n");
	}
	
	public static void mostrarReservas() {
		
	}
}
