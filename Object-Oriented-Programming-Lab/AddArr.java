import java.util.*;
class ArrAdd
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter the array size required: ");
int n = sc.nextInt();
int a[][] = new int[n][n];
int b[][] = new int[n][n];
System.out.println("Please input first Matrix: ");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
a[i][j]=sc.nextInt();
}
}
System.out.println("Please input second Matrix: ");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
b[i][j]=sc.nextInt();
}
}
System.out.println("Added Matrix: ");
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
System.out.print((a[i][j]+b[i][j])+" ");
}
System.out.println();
}

}
}
