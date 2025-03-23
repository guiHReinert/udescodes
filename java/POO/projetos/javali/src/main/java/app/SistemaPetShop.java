package app;

import classes.*;
import java.util.Scanner;

/*
2. Faça um programa em Java, orientado a objetos que gerencie as informações de
uma pet-shop. Esse programa deve ser capaz de listar os animais atendidos pelos
veterinários com todas as informações relacionadas a eles, além de permitir o cadastro
de novos animais e donos. O aluno deve desenvolver esse programa como uma
aplicação em duas camadas, contendo uma camada com as classes de dados e outra
camada contendo a interface com o usuário. Todos os dados referentes ao pet-shop
deverão ser fornecidos por meio da interface com o usuário. Segue abaixo a lista de
classes que o programa deve conter, com seus respectivos atributos e métodos:"
*/

public class SistemaPetShop {
    private static Veterinario[] veterinarios = new Veterinario[50];
    private static int numVeterinarios;
    private static Scanner inputer = new Scanner(System.in);

    public static void main(String[] args){
        int ans;
        while(true){
            menu();
            ans = Integer.parseInt(inputer.nextLine());

            if(ans == 1){
                SistemaPetShop.cadastrarVeterinario();
            }
            else if (ans == 2) {
                SistemaPetShop.mostrarVeterinarios();
            }
            else if(ans == 3){
                SistemaPetShop.cadastrarEnderecoVeterinario();
            }
            else if(ans == 4){
                SistemaPetShop.cadastrarAnimal();
            }
            else if(ans == 5){
                SistemaPetShop.mostrarAnimais();
            }
            else if(ans == 6){
                SistemaPetShop.cadastrarDono();
            }
            else if(ans==7){
                break;
            }
            else{System.out.println(" Digite um indice adequado.");}
        }
    }

    public static void menu(){
        System.out.println("\n                    JAVALI                    \n");
        System.out.println("Digite o indice respectivo a opção do menu abaixo:");
        System.out.println("1 - Cadastrar novo veterinario.");
        System.out.println("2 - Mostrar os veterinarios registrados.");
        System.out.println("3 - Cadastrar endereco de veterinario.");
        System.out.println("4 - Cadastrar novo animal.");
        System.out.println("5 - Mostrar os animais registrados.");
        System.out.println("6 - Cadastrar novo dono de um animal.");
        System.out.println("7 - Sair do sistema.");
        System.out.printf(" >> ");
    }

    /*
    void cadastrarVeterinario(): esse método requisita ao usuário as informações
    relacionadas ao veterinario, sendo estas: nome e salário. O sistema então
    adiciona ao array de veterinarios e incremeta o atributo quantidadeVeterinarios.
     */
    public static void cadastrarVeterinario(){
        if(numVeterinarios < 50){
            veterinarios[numVeterinarios] = new Veterinario();

            System.out.printf("Nome do novo veterinario:\n >> ");
            veterinarios[numVeterinarios].setNome(inputer.nextLine());
            System.out.printf("Salario de %s:\n >> ", veterinarios[numVeterinarios].getNome());
            veterinarios[numVeterinarios].setSalario(Float.parseFloat(inputer.nextLine()));
            numVeterinarios++;
        }
        else{System.out.printf(" Quantidade maxima de veterinarios atingida.");}
    }

    /*
    mostrarVeterinarios(): esse método deve exibir todos os veterinarios
    cadastrados no sistema, cada um contendo um número que o identifique (a
    posição no vetor).
     */
    public static void mostrarVeterinarios(){
        if(numVeterinarios > 0){
            System.out.printf("\n");
            for(int j=0; j < numVeterinarios; j++){
                System.out.printf(j+":\n"+veterinarios[j].toString()+'\n');
            }
        }
        else{
            System.out.println(" Nao há veterinarios cadastrados.");
        }
    }

    public static Veterinario getVeterinario(){
        int id;
        while(true){
            id = Integer.parseInt(inputer.nextLine());

            if(0 <= id && id < numVeterinarios){
                return veterinarios[id];
            }
            else{
                System.out.println(" Digite um indice adequado.");
                continue;
            }
        }
    }

    /*
    void cadastrarEnderecoVeterinario(): esse método deve exibir os veterinarios
    ja cadastrados e o usuário deve escolher qual veterinario ele quer cadastrar o
    endereço. Após escolhido o veterinário, é requisitado ao usuário as informações
    referentes ao endereço: rua, numero, bairro, cidade, estado e cep. Após o usuário
    digitar essas informações, o endereço é cadastrado ao veterinário escolhido.
     */
    public static void cadastrarEnderecoVeterinario(){
        if(numVeterinarios > 0){
            Endereco endereco = new Endereco();

            mostrarVeterinarios();
            System.out.printf("\nDigite o indice do veterinario acima para cadastrar o seu endereco:\n >> ");
            Veterinario veterinario = getVeterinario();

            System.out.printf("Digite o nome da rua de %s: ", veterinario.getNome());
            endereco.setRua(inputer.nextLine());
            System.out.printf("Numero da casa/apartamento: ");
            endereco.setNumero(inputer.nextLine());
            System.out.printf("Bairro: ");
            endereco.setBairro(inputer.nextLine());
            System.out.printf("Cidade: ");
            endereco.setCidade(inputer.nextLine());
            System.out.printf("Estado: ");
            endereco.setEstado(inputer.nextLine());
            System.out.printf("CEP: ");
            endereco.setCEP(inputer.nextLine());

            veterinario.setEndereco(endereco);
            System.out.println(" Endereco cadastrado com sucesso.");
        }
        else{System.out.println(" Nao ha veterinarios cadastrados.");}
    }

    /*
    cadastrarAnimal(): esse método deve exibir os veterinarios ja cadastrados e o
    usuário deve escolher qual veterinario ele quer cadastrar um novo animal. Após
    escolhido o veterinário, é requisitado ao usuário as informações referentes ao
    animal: nome, especie e descrição. Após o usuário digitas essas informações, o
    animal é cadastrado ao funcionário escolhido e o atributo quantidadeAnimais é
    incrementado.
    */
    public static void cadastrarAnimal(){
        Animal animal = new Animal();

        if(numVeterinarios > 0){
            System.out.printf("\nDigite o indice do veterinario acima para cadastrar um novo animal aos seus cuidados:\n >> ");
            Veterinario veterinario = getVeterinario();

            if(veterinario.getNumAnimais() < Veterinario.getMaxAnimais()){
                System.out.printf("Digite o nome do animal: ");
                animal.setNome(inputer.nextLine());
                System.out.printf("Especie: ");
                animal.setEspecie(inputer.nextLine());
                System.out.printf("Descricao: ");
                animal.setDescricao(inputer.nextLine());

                veterinario.novoAnimal(animal);
                System.out.println(" Animal cadastrado com sucesso.");
            }
            else{System.out.println(" Quantidade maxima de animais atingida.");}
        }
        else{System.out.println(" Nao ha veterinarios cadastrados.");}
    }

    /*
    mostrarAnimais(): esse método deve exibir os veterinarios ja cadastrados e o
    usuário deve escolher qual veterinario ele deseja visualizar os animais atendidos
    por ele, cada um contendo um número que o identifique (a posição no vetor).
    */
    public static void mostrarAnimais(){
        if(numVeterinarios > 0){
            mostrarVeterinarios();
            System.out.printf("\nDigite o indice do veterinario acima para visualizar os animais sob seus cuidados:\n >> ");
            Veterinario veterinario = getVeterinario();

            if(veterinario.getNumAnimais() > 0){
                for(int a=0; a<veterinario.getNumAnimais(); a++){
                    System.out.printf(a+":\n"+veterinario.getAnimais()[a].toString()+'\n');
                }
            }
            else{
                    System.out.println(" Nao há animais cadastrados.");
            }
        }
        else{System.out.println(" Nao ha veterinarios cadastrados.");}
    }

    public static Animal getAnimal(Veterinario veterinario){
        int id;
        while(true){
            id = Integer.parseInt(inputer.nextLine());

            if(0 <= id && id < veterinario.getNumAnimais()){
                return veterinario.getAnimais()[id];
            }
            else{
                System.out.println(" Digite um indice adequado.");
                continue;
            }
        }
    }

    /*
    cadastrarDono(): esse método deve exibir os animais já cadastrados e o usuário
    deve escolher qual animal ele deseja cadastrar um dono. Após escolhido o
    animal, é requisitado ao usuário as informações referentes ao dono: nome e cpf.
    Após digitadas essas informações, o dono é cadastrado ao animal escolhido.
    */
    public static void cadastrarDono(){
        int id;
        Dono dono = new Dono();

        while(true){
            if(mostrarAnimais()){
                System.out.printf("\nDigite o indice do animal acima para cadastrar o seu dono:\n >> ");
                id = Integer.parseInt(inputer.nextLine());

                if(0 <= id && id < veterinarios[id].getNumAnimais()){
                    if(veterinarios[id]){
                        System.out.printf("Informacoes do dono:\n");
                        System.out.printf(veterinarios[id].getAnimais()[id].getDono().toString());
                    }
                    System.out.printf("Digite o nome do dono: ");
                    dono.setNome(inputer.nextLine());
                    System.out.printf("CPF: ");
                    dono.setCPF(inputer.nextLine());

                    veterinarios[id].getAnimais()[id].setDono(dono);
                    System.out.println(" Dono cadastrado com sucesso.");
                    break;
                }
                else{
                    System.out.println(" Digite um indice adequado.");
                    continue;
                }
            }
            else{break;}
        }
    }

    /*
    cadastrarEnderecoDono(): esse método deve exibir os animais cadastrados e o
    usuário deve escolher qual animal ele deseja cadastrar o endereço do dono. Após
    escolhido o animal, é exibido as informações referentes ao dono: nome e cpf, e
    requisitado as informações referentes ao endereço: rua, numero, bairro, cidade,
    estado e cep. Após o usuário digitar essas informações, o endereço é cadastrado
    ao dono do animal escolhido
    */
    public static void cadastrarEnderecoDono(){
        int id;

        while(true){
            if(mostrarAnimais()){
                System.out.printf("\nDigite o indice do animal acima para cadastrar o endereco do seu dono:\n >> ");
                id = Integer.parseInt(inputer.nextLine());

                if(0 <= id && id < veterinarios[id].getNumAnimais()){
                    System.out.printf("Informacoes do dono:\n");
                    System.out.printf(veterinarios[id].getAnimais()[id].getDono().toString());
    
                    System.out.printf("Digite o nome da rua de %s: ", veterinarios[id].getAnimais()[id].getDono().getNome());
                    veterinarios[id].getAnimais()[id].getDono().getEndereco().setRua(inputer.nextLine());
                    System.out.printf("Numero da casa/apartamento: ");
                    veterinarios[id].getAnimais()[id].getDono().getEndereco().setNumero(inputer.nextLine());
                    System.out.printf("Bairro: ");
                    veterinarios[id].getAnimais()[id].getDono().getEndereco().setBairro(inputer.nextLine());
                    System.out.printf("Cidade: ");
                    veterinarios[id].getAnimais()[id].getDono().getEndereco().setCidade(inputer.nextLine());
                    System.out.printf("Estado: ");
                    veterinarios[id].getAnimais()[id].getDono().getEndereco().setEstado(inputer.nextLine());
                    System.out.printf("CEP: ");
                    veterinarios[id].getAnimais()[id].getDono().getEndereco().setCEP(inputer.nextLine());

                    System.out.println(" Endereco cadastrado com sucesso.");
                    break;
                }
                else{
                    System.out.println(" Digite um indice adequado.");
                    continue;
                }
            }
            else{break;}
        }
    }
}
