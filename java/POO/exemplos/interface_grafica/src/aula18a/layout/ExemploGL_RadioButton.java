package aula18a.layout;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

import java.awt.GridLayout;

public class ExemploGL_RadioButton extends JFrame{
    public static void main(String[] args){
        ExemploGL_RadioButton frame = new ExemploGL_RadioButton();
        frame.setTitle("GridLayoutDemo & RadioButton");
        frame.setSize(600, 100);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    public ExemploGL_RadioButton(){

        // Instancia os RadioButtons.
        JRadioButton yesButton = new JRadioButton("Yes" , true);
        JRadioButton noButton = new JRadioButton("No" , false);
        JRadioButton maybeButton = new JRadioButton("Maybe", false);
        
        // Cria um grupo de botoes e adiciona cada RadioButton a ele.
        ButtonGroup bgroup = new ButtonGroup();
        bgroup.add(yesButton);
        bgroup.add(noButton);
        bgroup.add(maybeButton);
        
        // Cria e organiza o painel contendo os botoes.
        JPanel radioPanel = new JPanel();
        radioPanel.setLayout(new GridLayout(3, 1));
        radioPanel.add(yesButton);
        radioPanel.add(noButton);
        radioPanel.add(maybeButton);

        // Define a borda do painel (tracada).
        radioPanel.setBorder(BorderFactory.createTitledBorder(
            BorderFactory.createEtchedBorder(), "Married?")
        );

        // Adiciona o painel ao frame ExemploGL_RadioButton.
        add(radioPanel);
    }
}
