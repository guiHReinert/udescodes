package ex3;

public class Main {
    private static final SistemaArquivos sistema = new SistemaArquivos();

    public static void main(String[] args) throws Exception {
    
        // Diretorios.
        String dir1 = "Downloads";
        String dir2 = "Documentos";
        String dir3 = ".minecraft";

        // Arquivos.
        sistema.criarDocumento("TxtDeTesteDeTexto", dir1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
        sistema.criarMusica("New Land - Avatar", dir2, 271);
        sistema.criarVideo("Avengers Endgame - Naruto Opening", dir3,  Qualidade.Q360 );
        sistema.criarDocumento("Receita de bolo", dir2, "socooorro");
        sistema.criarMusica("Flying Whales - Gojira", dir3, 464);

        // sistema.criarDocumento("Metalinguagem em um Enunciado e suas Aplicacoes \"isto eh uma excecao?\"", dir2,
        //     "O\n" + //
        //     "construtor dessas classes pode vir a lançar uma exceção do tipo NomeInvalidoException.\n" + //
        //     "O nome de um arquivo deve seguir as regras a seguir:\n" + //
        //     "• Não pode possuir quebras de linhas;\n" + //
        //     "• Não pode possuir colchetes ou parênteses;\n" + //
        //     "• Nem pode possuir aspas simples ou duplas;\n" + //
        //     "• Deve possuir no mı́nimo 10 caracteres e no máximo 256.");

        // sistema.criarMusica("x = -b[(b)² -4ac]^(1/2)/2a", dir3, 314);

        sistema.criarVideo("Gabriel, O Quebrador (de codigos)", dir2 , Qualidade.Q240);
        
        System.out.printf(sistema.toString());
    }
 
}
