package aula18a.frame;

import javax.swing.JFrame;

/*
Class JFrame

java.lang.Object
    java.awt.Component
        java.awt.Container
            java.awt.Window
                java.awt.Frame
                    javax.swing.JFrame 
*/
public class SimpleFrame2 extends JFrame{
    public static void main(String[] args) {
        SimpleFrame frame = new SimpleFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    private static final int DEFAULT_WIDTH = 600;
    private static final int DEFAULT_HEIGHT = 400;

    public SimpleFrame2() {
        this.setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    }
}
