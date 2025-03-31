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
						SISTEMA DE RESERVA DE PASSAGENS AÉREAS - SIRPA
							
				1 - Fazer Reserva
				2 - Cadastrar nova Cidade
				3 - Cadastrar novo Cliente
				4 - Mostrar Reservas
				5 - Sair do SIRPA
				""");
			ans = Integer.parseInt(scan.nextLine());

			if(ans == 1){
				fazerReserva();
			}
			else if(ans == 2){
				cadastrarCidade();
			}
			else if(ans == 3){
				cadastrarCliente();
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

		for(int j=0; j < reserva.getNumCidades(); j++){
			if(reserva.getListaDeCidades()[j] != null){
				System.out.println(reserva.getListaDeCidades()[j].toString());
			}
		}


	}
	
	public static void cadastrarCidade() {
		Cidade cidade = new Cidade();

		System.out.printf("Digite o nome da cidade: ");
		cidade.setNome(scan.nextLine());
		System.out.printf("Digite o estado da cidade: ");
		cidade.setEstado(scan.nextLine());

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

		System.out.printf("Novo cliente cadastrado com sucesso.\n");
	}
	
	public static void mostrarReservas() {
		
	}
}
