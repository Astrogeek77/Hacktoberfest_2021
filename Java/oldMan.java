import java.util.*;
//Creating a class help 
class help
{
    int NoOfSweets,NoOfChildren;
    //Constructor of help
    help(int NoOfSweets, int NoOfChildren)
    {
        this.NoOfSweets = NoOfSweets;
        this.NoOfChildren = NoOfChildren;
    }
    //Exception
    int perchild(int X, int Y)
    {
        //Try/Catch
    try {
        int NoSweet = X/Y;
        return NoSweet;
    } catch (Exception e) {
        System.out.println("Exception - " +e);
    }
    return 0;
    }
}

public class oldMan{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Number of Sweets : ");
        int X = scanner.nextInt();
        System.out.print("Enter Number of Children : ");
        int Y = scanner.nextInt();
        help object = new help(Y,X);
        int PerChildren = object.perchild(X,Y);
        System.out.print("Number of Sweets received per Children :  " + PerChildren);
    }
}