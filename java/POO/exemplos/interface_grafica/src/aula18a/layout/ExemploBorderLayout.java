package aula18a.layout;

import javax.swing.JButton;
import javax.swing.JFrame;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;

/*
    Border Layout organiza a janela divindo-a em 5 regioes: norte, sul,
    oeste, leste e centro. Cada regiao se expande para a sua borda
    respectiva, bem como pode ser ancorada sobre ela.
*/
public class ExemploBorderLayout extends JFrame{
    public static void main(String[] args){
        ExemploBorderLayout frame = new ExemploBorderLayout();
        frame.setTitle("BorderLayoutDemo");
        frame.setSize(600, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Centraliza a janela.
        frame.setLocationRelativeTo(null);
        
        frame.setVisible(true);
    }

    public ExemploBorderLayout(){
        Container pane = this.getContentPane();

        JButton button = new JButton("Button 1 (PAGE_START)");
        pane.add(button, BorderLayout.NORTH);

        // Faz o componente central maior...
        button = new JButton("Button 2 (CENTER)");
        button.setPreferredSize(new Dimension(200, 100));
        pane.add(button, BorderLayout.CENTER);

        button = new JButton("Button 3 (LINE_START)");
        pane.add(button, BorderLayout.WEST);

        button = new JButton("Long-Named Button 4 (PAGE_END)");
        pane.add(button, BorderLayout.SOUTH);

        button = new JButton("5 (LINE_END)");
        pane.add(button, BorderLayout.EAST);
    }
}
