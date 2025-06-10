package aula18b;

import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleFrameTest {
    public static void main(String[] args) {
        ActionListener listener = new MyListener();
        JButton button = new JButton("Ok");
        button.addActionListener(listener);
    }
}

class MyListener implements ActionListener {
    public void actionPerformed(ActionEvent event){
        // Reacao ao clique do botao.
    }
}

