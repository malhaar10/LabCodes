import java.util.*;

class Array_addition {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        // declare both matrices
        System.out.println("Enter the value of m and n: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] ArrA = new int[m][n];
        int[][] ArrB = new int[m][n];
        int i, j;

        // input matrix A
        System.out.println("Enter elements for matrix A:");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                ArrA[i][j] = sc.nextInt();
            }
        }

        // input matrix B
        System.out.println("Enter elements for matrix B:");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                ArrB[i][j] = sc.nextInt();
            }
        }

        // adding matrices and creating the result matrix
        int[][] ArrC = new int[m][n];
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                ArrC[i][j] = ArrA[i][j] + ArrB[i][j];
            }
        }

        // displaying the result matrix
        System.out.println("Resultant matrix:");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                System.out.print(ArrC[i][j] + " ");
            }
            System.out.println();
        }
    }
}
