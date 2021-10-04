package algorithmAssign;

/* n-Oueen's Problem : 
		The problem is to place n Queens on a nxn chessboard in such a manner that no
		two queens can attack each other.
		----------------------
		This algorithm prints all possible solutions
 */
import java.util.Scanner;

public class NQueens 
{
	static int k =1;
    public static void main(String[] args) 
    {
    	System.out.println("Enter the value of n: ");
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
        boolean[][] board = new boolean[n][n];
        if(nqueen(board,0)==false)
        {
        	System.out.println("Solution does not exist.");
        }
        sc.close();
    }
    //utility function
    public static boolean nqueen(boolean[][] board, int row)
    {
        if(row == board.length)
        {
            display(board);
            return true;
        }
        boolean res = false; 
        for (int col = 0; col <board.length ; col++) 
        {
            if(isSafe(board, row, col))
            {
                board[row][col]=true;
                res = nqueen(board, row+1) || res;		//make result true if placement is possible
                board[row][col]= false;
            }
        }
        return res;										//return false if no placement is possible
    }
    private static boolean isSafe(boolean[][] board, int row, int col) 
    {
        for (int i = 0; i <row ; i++) 
        {
            if(board[i][col])
            {
                return false;
            }
        }
        int left = Math.min(row,col);
        for (int i = 1; i <= left ; i++) 
        {
            if(board[row-i][col-i])
            {
                return false;
            }
        }
        int right = Math.min(row,board.length-col-1);
        for (int i = 1; i <=right ; i++) 
        {
            if(board[row-i][col+i])
            {
                return false;
            }
        }
        return true;
    }
    //print solution matrix
    private static void display(boolean[][] board) 			
    {	
    	System.out.printf("%d-\n", k++); 
        for (int i = 0; i <board.length ; i++) 
        {
            for (int j = 0; j <board[i].length ; j++) 
            {
                if(board[i][j])
                {
                    System.out.print("Q ");
                }
                else
                {
                    System.out.print("X ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
}