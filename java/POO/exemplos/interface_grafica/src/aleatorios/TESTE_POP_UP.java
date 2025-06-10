package aleatorios;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

public class TESTE_POP_UP {

    private static final java.util.List<String> todosOsValores = new ArrayList<>();
    private static final DefaultListModel<String> modeloLista = new DefaultListModel<>();

    public static void main(String[] args) {
        // Preenche a lista externa com alguns valores possíveis
        todosOsValores.add("Valor A");
        todosOsValores.add("Valor B");
        todosOsValores.add("Valor C");
        todosOsValores.add("Valor D");

        // Frame principal com botão para abrir o popup
        JFrame frame = new JFrame("Janela Principal");
        JButton botaoAbrir = new JButton("Abrir Popup");
        botaoAbrir.addActionListener(e -> mostrarPopup(frame));
        frame.getContentPane().add(botaoAbrir);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    private static void mostrarPopup(JFrame parent) {
        JDialog dialog = new JDialog(parent, "Gerenciar Lista", true);
        dialog.setLayout(new BorderLayout());

        // JList com modelo de lista
        JList<String> lista = new JList<>(modeloLista);
        lista.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        JScrollPane scroll = new JScrollPane(lista);
        dialog.add(scroll, BorderLayout.CENTER);

        // Painel com botoes
        JPanel painelBotoes = new JPanel();
        JButton botaoAdicionar = new JButton("Adicionar");
        JButton botaoRemover = new JButton("Remover");

        botaoAdicionar.addActionListener(e -> {
            // Mostra os valores possíveis que ainda não foram adicionados
            java.util.List<String> restantes = new ArrayList<>(todosOsValores);
            for (int i = 0; i < modeloLista.getSize(); i++) {
                restantes.remove(modeloLista.getElementAt(i));
            }

            if (restantes.isEmpty()) {
                JOptionPane.showMessageDialog(dialog, "Nenhum valor restante para adicionar.");
                return;
            }

            String selecionado = (String) JOptionPane.showInputDialog(
                dialog,
                "Escolha um valor para adicionar:",
                "Adicionar Valor",
                JOptionPane.PLAIN_MESSAGE,
                null,
                restantes.toArray(),
                restantes.get(0)
            );

            if (selecionado != null && !modeloLista.contains(selecionado)) {
                modeloLista.addElement(selecionado);
            }
        });

        botaoRemover.addActionListener(e -> {
            String selecionado = lista.getSelectedValue();
            if (selecionado != null) {
                modeloLista.removeElement(selecionado);
            } else {
                JOptionPane.showMessageDialog(dialog, "Selecione um valor para remover.");
            }
        });

        painelBotoes.add(botaoAdicionar);
        painelBotoes.add(botaoRemover);
        dialog.add(painelBotoes, BorderLayout.SOUTH);

        dialog.setSize(300, 300);
        dialog.setLocationRelativeTo(parent);
        dialog.setVisible(true);
    }
}
