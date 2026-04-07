package aula18a.frame;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;

/*
Class JFrame

java.lang.Object
    java.awt.Component
        java.awt.Container
            java.awt.Window
                java.awt.Frame
                    javax.swing.JFrame 
*/
public class SimpleFrame extends JFrame{
    private static final int DEFAULT_WIDTH = 300;
    private static final int DEFAULT_HEIGHT = 200;

    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);

        JPanel pane1 = new JPanel();
        JPanel pane2 = new JPanel();

        frame.add(pane1, BorderLayout.NORTH);
        frame.add(pane2, BorderLayout.SOUTH);

        frame.setVisible(true);
    }
}
