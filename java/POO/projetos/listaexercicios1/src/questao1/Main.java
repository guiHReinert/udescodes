package questao1;

import java.beans.PropertyEditorSupport;

public class Main {
    public static void main(String[] args) {
        Endereco casaPlaceholder = new Endereco();
        Endereco casaCheia = new Endereco(
            "Ruanilda", 42, "Balthamos", "Stadtopolis",
            "Santa Catarina do Norte", 81726354
        );
        
        Cliente cl1 = new Cliente();
        Cliente cl2 = new Cliente(
            19128237301L, "Dagur Mannoroth", casaPlaceholder, 29.65 
        );
        Cliente cl3 = new Cliente(
            919828737002L, "Bagram Jahaleor", casaCheia, 130.73
        );

        Produto produtoHolder = new Produto();
        Produto hotwheels1 = new Produto(
            "Drone Padrao Legacy Acceleracers", "Artefato", 21.99,
            0.15
        );
        Produto enxspada = new Produto(
            "Enxspada de Guerra Laboral", "Armerramenta", 72.89,
            0.12
        );
        Produto pastel = new Pastel(
            "Pastel de Frango", "Comida", 4.99, 0.0
        );
        Produto cardo = new Produto(
            "Caldo de Cana", "Bebida", 6.99, 0.1
        );

        

    }
}
