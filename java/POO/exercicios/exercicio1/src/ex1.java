package src;

import java.util.Scanner;

public class ex1 {
    public static void main(String[] args) {
        Scanner inputer = new Scanner(System.in);

        float sum = 0;
        int[] nums = new int[5];

        System.out.println("Digite 5 numeros para calcular a media entre eles:");
        for (int j = 0; j < 5; j++) {
            nums[j] = inputer.nextInt();
            sum += nums[j];
        }
        System.out.println("Media = " + sum / 5);
    }
}