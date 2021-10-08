import java.io.*;
import java.util.Scanner;

public class FactorialFinder {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        System.out.print("Enter Number: ");
        int num = s.nextInt();

        long factorialNum = 1;
        for(int i = 1; i <= num; ++i)
        {
            factorialNum *= i;
        }
        System.out.printf("Factorial of %d = %d", num, factorialNum);
    }
}
