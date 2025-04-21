package ex2.negocio;

import ex2.dados.*;
import java.util.Scanner;
import java.util.ArrayList;

public class Zoologico {
    private static ArrayList<Animal> animais = new ArrayList<Animal>();
    private static ArrayList<Viveiro> viveiros = new ArrayList<Viveiro>();

    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int ans=0;
        while(true){
            ans = menu();
            if(ans == 1){
                boolean ehPeixe;
                
                System.out.printf("Este animal eh um animal marinho?(false/true) ");
                ehPeixe = Boolean.parseBoolean(scan.nextLine());
                if(ehPeixe){
                    Peixe peixe = new Peixe();
                    System.out.printf("Escreva o nome do novo animal marinho: ");
                    peixe.setNome(scan.nextLine());
                    System.out.printf("Cor: ");
                    peixe.setCor(scan.nextLine());
                    System.out.printf("Especie: ");
                    peixe.setEspecie(scan.nextLine());
                    System.out.printf("Idade: ");
                    peixe.setIdade(Integer.parseInt(scan.nextLine()));
                    System.out.printf("Largura (em metros): ");
                    peixe.setLargura(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Comprimento (em metros): ");
                    peixe.setComprimento(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Altura: ");
                    peixe.setAltura(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Temperatura ideal da agua: ");
                    peixe.setTemperaturaIdeal(Float.parseFloat(scan.nextLine()));

                    cadastrarAnimal(peixe);
                }
                else{
                    Animal animal = new Animal();
                    System.out.printf("Escreva o nome do novo animal: ");
                    animal.setNome(scan.nextLine());
                    System.out.printf("Cor: ");
                    animal.setCor(scan.nextLine());
                    System.out.printf("Especie: ");
                    animal.setEspecie(scan.nextLine());
                    System.out.printf("Idade: ");
                    animal.setIdade(Integer.parseInt(scan.nextLine()));
                    System.out.printf("Largura (em metros): ");
                    animal.setLargura(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Comprimento (em metros): ");
                    animal.setComprimento(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Altura: ");
                    animal.setAltura(Float.parseFloat(scan.nextLine()));

                    cadastrarAnimal(animal);
                }
            }
            else if(ans == 2){
                boolean ehAquario;
                
                System.out.printf("Este viveiro eh um aquario?(false/true) ");
                ehAquario = Boolean.parseBoolean(scan.nextLine());
                if(ehAquario){
                    Aquario aquario = new Aquario();

                    System.out.printf("Digite o nome do novo aquario: ");
                    aquario.setNome(scan.nextLine());
                    System.out.printf("Comprimento: ");
                    aquario.setComprimento(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Largura: ");
                    aquario.setLargura(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Altura: ");
                    aquario.setAltura(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Temperatura media da agua: ");
                    aquario.setTemperatura(Float.parseFloat(scan.nextLine()));
                    
                    cadastrarViveiro(aquario);
                }
                else{
                    Viveiro viveiro = new Viveiro();

                    System.out.printf("Digite o nome do novo viveiro: ");
                    viveiro.setNome(scan.nextLine());
                    System.out.printf("Comprimento: ");
                    viveiro.setComprimento(Float.parseFloat(scan.nextLine()));
                    System.out.printf("Largura: ");
                    viveiro.setLargura(Float.parseFloat(scan.nextLine()));
                    
                    cadastrarViveiro(viveiro);
                }
            }
            else if(ans == 3){
                if(exibirAnimais()){
                    int id1;
                    System.out.printf("Digite o indice respectivo ao animal a ser realocado: ");
                    while(true){
                        id1 = Integer.parseInt(scan.nextLine());
                        if(id1 >= 0 && id1 < animais.size()){
                            if(animais.get(id1) instanceof Peixe){
                                if(exibirAquarios()){
                                    int id2;
                                    System.out.printf("Digite o indice respectivo ao aquario escolhido: ");
                                    while(true){
                                        id2 = Integer.parseInt(scan.nextLine());
                                        if(id2 >= 0 && id2 < getSoAquarios().size()){
                                            alocarAnimal(animais.get(id1), getSoAquarios().get(id2)); 
                                        }
                                        else{
                                            System.out.printf(" Digite um indice correto. ");
                                        }
                                    }
                                }
                            }
                            else{
                                if(exibirViveiros()){
                                    int id2;
                                    System.out.printf("Digite o indice respectivo ao viveiro escolhido: ");
                                    while(true){
                                        id2 = Integer.parseInt(scan.nextLine());
                                        if(id2 >= 0 && id2 < getSoViveiros().size()){
                                            alocarAnimal(animais.get(id1), getSoViveiros().get(id2)); 
                                        }
                                        else{
                                            System.out.printf(" Digite um indice correto. ");
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            System.out.printf(" Digite um indice correto. ");
                        }
                    }
                }
            }
            else if(ans == 4){
                exibirViveiros();
            }
            else if(ans == 5){
                exibirAnimais();
            }
            else if(ans == 6){
            System.out.printf(" Volte sempre!\n");
                break;
            }
            else{
                System.out.printf(" Digite um indice adequado.\n");
                continue;
            }
        }
    }

    public static void cadastrarViveiro(Viveiro viveiro) {
        viveiros.add(viveiro);
        System.out.printf("Viveiro registrado com sucesso.\n");
    }

    public static void cadastrarAnimal(Animal animal) {
        animais.add(animal);
        System.out.printf("Animal registrado com sucesso.\n");
    }

    public static boolean alocarAnimal(Animal animal, Viveiro viveiro){
        if(viveiro.adicionarAnimal(animal)){
            System.out.printf("Animal alocado com sucesso.\n");
            animais.remove(animal);
            return true;
        }
        else{
            System.out.printf(" Nao foi possivel alocar o animal.\n");
            return false;
        }
    }

    public static ArrayList<Aquario> getSoAquarios(){
        ArrayList<Aquario> aquarios = new ArrayList<Aquario>();
        for(Viveiro viveiro : viveiros){
            if(viveiro instanceof Aquario){
                aquarios.add((Aquario) viveiro);
            }
        }
        return aquarios;
    }

    public static ArrayList<Viveiro> getSoViveiros(){
        ArrayList<Viveiro> viveirosOnly = new ArrayList<Viveiro>();
        for(Viveiro viveiro : viveiros){
            if(viveiro instanceof Aquario){
                viveirosOnly.add(viveiro);
            }
        }
        return viveirosOnly;
    }

    public static boolean exibirAquarios(){
        if(!getSoAquarios().isEmpty()){
            System.out.println("");
            for(int c=0; c < getSoAquarios().size(); c++){
                System.out.printf("[" + c + "] " + getSoAquarios().get(c).toString() + '\n');
            }
            return true;
        }
        else{
            System.out.printf(" Nao ha aquarios registrados.\n");
            return false;
        }
    }

    public static boolean exibirViveiros(){
        if(!getSoViveiros().isEmpty()){
            System.out.println("");
            for(int c=0; c < getSoViveiros().size(); c++){
                System.out.printf("[" + c + "] " + getSoViveiros().get(c).toString() + '\n');
            }
            return true;
        }
        else{
            System.out.printf(" Nao ha viveiros ou aquarios registrados.\n");
            return false;
        }
    }

    public static boolean exibirAnimais(){
        if(!animais.isEmpty()){
            System.out.println("");
            for(int c=0; c < animais.size(); c++){
                System.out.printf("[" + c + "] " + animais.get(c).toString() + '\n');
            }
            return true;
        }
        else{
            System.out.printf(" Nao ha animais registrados.\n");
            return false;
        }
    }

    public static int menu() {
        System.out.println("\n          ZOO - Zologico Orientado a Objeto");
        System.out.println(" Selecione abaixo o indice referente a opcao desejada:");
        System.out.println("1 - Adicionar novo animal");
        System.out.println("2 - Adicionar novo viveiro/aquario");
        System.out.println("3 - Alocar animal para um viveiro/aquario");
        System.out.println("4 - Exibir viveiros e aquarios");
        System.out.println("5 - Exibir animais");
        System.out.println("6 - Sair do sistema");
        return Integer.parseInt(scan.nextLine());
    }
}