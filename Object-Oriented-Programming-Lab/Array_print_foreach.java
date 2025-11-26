import java.util.*;
class Array_print_foreach{
   public static void main(String args[]){
      System.out.println("Enter n: ");
      Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      int [] arr= new int[n];
      System.out.println("Enter elements: ");
      for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
      }
      System.out.println("The array is: ");
      for(int elements: arr){
            System.out.println(elements);
      }
   }
}