package app;

import classes.Cliente;
import classes.Compra;
import classes.Endereco;
import classes.Funcionario;
import classes.Produto;

public class Main {
    public static void main(String[] args) {
        // EnderecoscasaCheiacasaCheia
        System.out.printf("\n     Enderecos\n");

        Endereco casaPlaceholder = new Endereco();
        Endereco porao = new Endereco(
            "Coronel Tenente Coronel", 13, "Eredin", "Rancho Incinerado",
            "Pararana", 13579124
        );
        Endereco casaCheia = new Endereco(
            "Ruanilda", 42, "Balthamos", "Stadtpolis",
            "Santa Catarina do Norte", 81726354
        );

        System.out.printf("\nCasa Placeholder:\n%s", casaPlaceholder.toString());
        System.out.printf("\nCasa ''com porao'':\n%s", porao.toString());
        System.out.printf("\nCasa Cheia:\n%s", casaCheia.toString());


        // Funcionarios
        System.out.printf("\n     Funcionarios\n");

        Funcionario descarregador = new Funcionario(
            24680135701L, "Ronaldo", "Descarregador", 1517.99, porao
        );
        Funcionario atendente = new Funcionario(
            52738452341L, "Elisa", "Atendente", 1518.00, casaPlaceholder
        );  
        Funcionario funcSecreto = new Funcionario();

        atendente.getEndereco().setRua("Vista Grossa");
        atendente.getEndereco().setNumero(89);
        atendente.getEndereco().setBairro("Ponta Bela");
        atendente.getEndereco().setCidade("Arroio de Fora");
        atendente.getEndereco().setEstado("Gaucho");
        atendente.getEndereco().setCEP(75742309);

        System.out.printf("\nDescarregador N.26:\n"+descarregador.toString());       
        System.out.printf("\nAtendente Caixa 2:\n"+atendente.toString());        
        System.out.printf("\nFuncionario 167-8:\n"+funcSecreto.toString());        

        // Clientes
        System.out.printf("\n     Clientes\n");

        Cliente cl1 = new Cliente(
            19128237301L, "Dagur Mannoroth", casaPlaceholder, 29.65 
        );
        Cliente cl2 = new Cliente(
            91982873702L, "Bagram Jahaelor", null, 130.73
        );
        cl2.setEndereco(casaCheia);
        
        System.out.printf("\nCliente 1:\n%s\n", cl1.toString());
        System.out.printf("\nCliente 2:\n%s\n", cl2.toString());


        // Produtos
        System.out.printf("\n     Produtos\n");

        Produto hotwheels1 = new Produto(
            "Drone Padrao Legacy Acceleracers", "Brinquedo", 21.99, 0.15
        );
        Produto hotwheels2 = new Produto(
            "Carroca Platinada Cool", "Brinquedo", 21.99, 0.15
        );
        Produto enxspada = new Produto(
            "Enxada de Guerra", "Ferramenta", 72.89, 0.12
        );
        Produto pastel = new Produto(
            "Pastel de Frango", "Comida", 4.99, 0.0
        );
        Produto cardo = new Produto(
            "Caldo de Cana", "Bebida", 6.99, 0.1
        );
        Produto[] objetos = {hotwheels1, hotwheels2, enxspada};
        Produto[] lanche = {pastel, cardo};

        System.out.printf("\nCarrinho 1:\n%s", hotwheels1.toString());
        System.out.printf("\nCarrinho 2:\n%s", hotwheels2.toString());
        System.out.printf("\nFerramenta:\n%s", enxspada.toString());
        System.out.printf("\nPastel (hummm):\n%s", pastel.toString());
        System.out.printf("\nCaldo de Cana:\n%s", cardo.toString());

        // Compras
        System.out.printf("\n     Compras\n");

        Compra compraAbandonada = new Compra();
        Compra compraObjetos = new Compra(
            objetos,
            hotwheels1.getPrecoReal() + hotwheels2.getPrecoReal() + enxspada.getPrecoReal(),
            0.1 * (hotwheels1.getPrecoReal() + hotwheels2.getPrecoReal() + enxspada.getPrecoReal()),
            cl1
        );
        Compra pastelCombo = new Compra(
            lanche,
            0.8* (pastel.getPreco() + cardo.getPreco()),
            0.0 * (0.8 * pastel.getPrecoReal() + cardo.getPrecoReal()),
            cl2
        );

        System.out.printf("\nCompra Incompleta:\n%s", compraAbandonada.toString());
        System.out.printf("\nCompra de Objetos:\n%s", compraObjetos.toString());
        System.out.printf("\nCombo Decente:\n%s", pastelCombo.toString());

    }
}
