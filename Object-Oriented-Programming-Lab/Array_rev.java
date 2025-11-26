import java.util.*;
class Array_rev{
   public static void main(String args[]){
      System.out.println("Enter n: ");
      int n;
      Scanner sc=new Scanner(System.in);
      n=sc.nextInt();
      int [] arr= new int[n];
      System.out.println("Enter array elements: ");
      for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
      }
      System.out.println("The array is: ");
      for(int j=n-1;j>=0;j--){
            System.out.println(arr[j]);
      }
   }
}