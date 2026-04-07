package pkg;

public class Complexo {
    private int real;
    private int complexa;

    public Complexo(){
        this.real = 0;
        this.complexa = 0;
    }

    public Complexo(int real, int complexa){
        this.real = real;
        this.complexa = complexa;
    }

    public String toString(){
        if(this.complexa < 0){
            return this.real + " - " + this.complexa + "i";
        }
        else if(this.complexa == 0){
            return String.valueOf(this.real);
        }
        else{
            return this.real + " + " + this.complexa + "i";
        }
    }
}
