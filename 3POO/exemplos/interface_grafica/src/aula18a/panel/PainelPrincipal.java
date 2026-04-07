package aula18a.panel;

import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;

import java.awt.BorderLayout;
import java.awt.GridLayout;

public class PainelPrincipal extends JPanel{

    private JTextField textFieldOrigem = new JTextField(40);
    private JTextField textFieldDestino = new JTextField(40);
    private JButton buttonCopia = new JButton("Copiar");
    private JButton buttonSair = new JButton("Sair");

    public PainelPrincipal() {

        /*
            BorderLayout(int hgap, int vgap):
            Constructs a border layout with the specified gaps between
            components.
        */
        super(new BorderLayout(5, 5));

        JPanel nomes = new JPanel(new GridLayout(0, 1));
        nomes.add(new JLabel("Origem:"));
        nomes.add(new JLabel("Destino:"));

        JPanel conteudos = new JPanel(new GridLayout(0, 1));
        conteudos.add(textFieldOrigem);
        conteudos.add(textFieldDestino);

        // new Label() serve como um espaco vertical entre componentes.
        JPanel botoes = new JPanel(new GridLayout(1, 0));
        botoes.add(new JLabel());
        botoes.add(buttonCopia);
        botoes.add(new JLabel());
        botoes.add(buttonSair);
        botoes.add(new JLabel());

        add(botoes, BorderLayout.SOUTH);
        add(conteudos, BorderLayout.CENTER);
        add(nomes, BorderLayout.WEST); }
}
