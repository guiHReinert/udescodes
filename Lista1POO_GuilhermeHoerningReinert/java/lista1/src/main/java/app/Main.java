package app;

import classes.Cliente;
import classes.Compra;
import classes.Endereco;
import classes.Funcionario;
import classes.Produto;

import ex3Classes.*;

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

        // Imobiliaria imobiliaria = new Imobiliaria();
        // Imovel im1 = new Imovel(); im1.setComprimento(20); im1.setLargura(30); im1.setPreco(972418);
        // Imovel im2 = new Imovel(); im2.setComprimento(30); im2.setLargura(20); im2.setPreco(853947);
        // Imovel im3 = new Imovel(); im3.setComprimento(80); im3.setLargura(50); im3.setPreco(782347);
        // Imovel im4 = new Imovel(); im4.setComprimento(50); im4.setLargura(80); im4.setPreco(619732);
        // Imovel im5 = new Imovel(); im5.setComprimento(42); im5.setLargura(89); im5.setPreco(317729);

        // imobiliaria.cadastrarImovel(im1);
        // imobiliaria.cadastrarImovel(im2);
        // imobiliaria.cadastrarImovel(im3);
        // imobiliaria.cadastrarImovel(im4);
        // imobiliaria.cadastrarImovel(im5);

        // Imovel[] filtered1 = imobiliaria.filtrarPorArea(590);
        // Imovel[] filtered2 = imobiliaria.filtrarPorArea(610);

        // System.out.println(imobiliaria.toString());
        // System.out.println("\nImoveis maiores que 590m²");
        // for(Imovel imv : filtered1){
        //     if(imv != null){
        //         System.out.println(imv.toString());
        //     }
        // }
        // System.out.println("\nImoveis maiores que 610m²");
        // for(Imovel imv : filtered2){
        //     if(imv != null){
        //         System.out.println(imv.toString());
        //     }
        // }
    }
}
