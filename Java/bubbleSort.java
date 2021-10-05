import java.util.*;
public class Bubble{
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int n=0,t=0,arr[];


        System.out.println("Enter size of array");
        n=sc.nextInt();
        arr=new int[n];

        // entering array elements
        System.out.println("Enter array elements");
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }

        // applying bubble sort
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    t=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=t;
                }
            }
        }

        // Printing sorted array
        System.out.println("The sorted array is:");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}