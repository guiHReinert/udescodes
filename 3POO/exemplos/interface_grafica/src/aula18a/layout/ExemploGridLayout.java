package aula18a.layout;

import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.Container;
import java.awt.GridLayout;

/*
    Grid Layout organiza a janela dividindo-a em uma grade com indices, seguindo
    a logica matricial de linhas e colunas.
*/
public class ExemploGridLayout extends JFrame{
    public static void main(String[] args){
        ExemploGridLayout frame = new ExemploGridLayout();
        frame.setTitle("GridLayoutDemo");
        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    public ExemploGridLayout(){
        Container pane = this.getContentPane();

        GridLayout experimentLayout = new GridLayout(0,2);
        pane.setLayout(experimentLayout);

        pane.add(new JButton("Button 1"));
        pane.add(new JButton("Button 2"));
        pane.add(new JButton("Button 3"));
        pane.add(new JButton("Long-Named Button 4"));
        pane.add(new JButton("5"));
    }
}
