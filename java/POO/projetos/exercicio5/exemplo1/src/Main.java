package exemplo1;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class Main {

    public static void main(String[] args){
        Map<Integer, List<Integer>> tabuadas = new HashMap<Integer, List<Integer>>();

        for(int j=1; j < 11; j++){
            tabuadas.put(j, tabuada(j));
        }

        tabuadas.forEach((key, tauba) -> {
            System.out.printf("\nTabuada de "+key+": ");
            for(Integer num : tauba){
                System.out.printf(num + " ");
            }
        });
        
    System.out.println("");
    }

    public static ArrayList<Integer> tabuada(int num){
        ArrayList<Integer> tauba = new ArrayList<Integer>();
        for(int c=1; c < 11; c++){
            tauba.add(c * num);
        }
        return tauba;
    } 
}