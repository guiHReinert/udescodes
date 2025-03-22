package classes;

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
    private Veterinario[] veterinarios = new Veterinario[50];
    private int numVeterinarios;

    public void cadastrarVeterinario(String nome, float sal){
        if(numVeterinarios < 50){
            veterinarios[numVeterinarios] = new Veterinario();
            veterinarios[numVeterinarios].setNome(nome);
            veterinarios[numVeterinarios].setSalario(sal);
            numVeterinarios++;
        }
    }

    public void mostrarVeterinarios(){
        for(int j=0; j < numVeterinarios; j++){
            System.out.println("%d: %s\n", j, veterinarios[j]);
        }
    }

    // public void cadastrarEnderecoVeterinario(){

    // }

    // public void cadastrarAnimal(){

    // }

    // public String mostrarAnimais(){

    // }

    // public void cadastrarDono(){

    // }

    // public void cadastrarEnderecoDono(){

    // }
}
