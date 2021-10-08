/*
    Time complexity : O(9 ^ K)
    Space complexity : O(K)

    where 'K' denotes the number of empty cells in the matrix.
*/

public class Solution {

    static private boolean isValid(int matrix[][]) {

        int n = matrix.length;
        int[][] row = new int[n][n + 1];
        int[][] column = new int[n][n + 1];
        int[][][] subMatrix = new int[3][3][n + 1];

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                row[r][matrix[r][c]] += 1;
                column[c][matrix[r][c]] += 1;
                subMatrix[r / 3][c / 3][matrix[r][c]] += 1;

                if (subMatrix[r / 3][c / 3][matrix[r][c]] > 1 || column[c][matrix[r][c]] > 1 ||
                        row[r][matrix[r][c]] > 1) {
                    return false;
                }
            }
        }
        return true;
    }

    static private boolean solve(int matrix[][], int i, int j) {
        int n = matrix.length;
        if (i == n - 1 && j == n) {
            return isValid(matrix);
        }

        if (j == n) {
            i++;
            j = 0;
        }

        if (matrix[i][j] != 0) {
            return solve(matrix, i, j + 1);
        }

        for (int digit = 1; digit <= n; digit++) {
            matrix[i][j] = digit;
            if (solve(matrix, i, j + 1)) {
                return true;
            }
            matrix[i][j] = 0;
        }
        return false;
    }

    public static boolean isItSudoku(int matrix[][]) {

        return solve(matrix, 0, 0);
    }
}
