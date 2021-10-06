import java.util.Scanner;
public class Fibonacci {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();                 //taking input from user
        int a = 0;                            //initializing a with 0
        int b = 1;                            //initializing b with 1
        int count = 1;                   //initializing count with 1 because 1st digit i.e 0 will already be printed before entering while loop
        System.out.print(a + " ");          //this will print 0 before we enter the while loop

        while(count<=n-1){                
            int counter = b;
            b = b + a;
            a = counter;
            count++;
            System.out.print(a + " ");
        }
    }
}
