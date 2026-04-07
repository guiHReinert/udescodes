package ex2.persistencia;

import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;

public class EditorTexto {
    public void sortarTexto(String path) {
        try {
            FileReader arqR = new FileReader(path);
            Scanner scan = new Scanner(arqR);
            List<String> dados = new LinkedList<String>();

            while (scan.hasNextLine()) {
                String linha = scan.nextLine();
                dados.add(linha);
            }
            dados.sort((c1, c2) -> {
                String[] s1 = c1.split(", ");
                String[] s2 = c2.split(", ");
                return s1[0].compareTo(s2[0]);
            });
            scan.close();
            arqR.close();

            FileWriter arqW = new FileWriter(path, false);
            for (String linha : dados) {
                arqW.write(linha + "\n");
            }
            arqW.close();

        } catch (Exception e) {
            System.err.println(" Erro ao sortar o arquivo");
            System.exit(0);
        }
    }

    public void gravarTexto(String path, List<String> dados) {
        FileWriter arq;

        try {
            arq = new FileWriter(path, false);
            for (String linha : dados) {
                arq.write(linha + "\n");
            }
            arq.close();
        } catch (Exception e) {
            System.err.println("Erro ao escrever o arquivo");
            System.exit(0);
        }
    }

    public void gravarTexto(String path, String linha) {
        try {
            FileWriter arq = new FileWriter(path, true);
            arq.write(linha + "\n");
            arq.close();
        } catch (Exception e) {
            System.err.println("Erro ao escrever o arquivo");
            System.exit(0);
        }
    }

    public List<String> leTexto(String path) {
        List<String> dados = new LinkedList<String>();

        try {
            FileReader arq = new FileReader(path);
            Scanner scan = new Scanner(arq);
            while (scan.hasNextLine()) {
                String linha = scan.nextLine();
                dados.add(linha);
            }
            scan.close();
            return dados;
        } catch (Exception e) {
            System.err.println("Erro ao ler o arquivo");
            System.exit(0);
            return null;
        }
    }
}
