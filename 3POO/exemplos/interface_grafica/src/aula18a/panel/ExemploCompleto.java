package aula18a.panel;

import javax.swing.JFrame;

/*
    Separa o painel de uma janela em varios paineis, cada um com o seu proprio
    layout/
*/
public class ExemploCompleto extends JFrame{
    public ExemploCompleto() {
        super("Exemplo");
        
        // Adiciona o painel com subpaineis para o frame pincipal.
        add(new PainelPrincipal());
        
        /*
            Redimensiona a janela para comportar o tamanho minimo ocupado pelos
            seus componentes.
        */
        pack();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setResizable(false);
        setVisible(true);
    }
    public static void main(String[] args) {
        new ExemploCompleto();  
    }
}
