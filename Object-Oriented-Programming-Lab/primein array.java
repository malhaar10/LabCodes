import java.util.*;
class Prime_in_array{
    public static void main(Straing args[]){
      System.out.println("Enter n: ");
      int n;
      Scanner sc=new Scanner(System.in);
      n=sc.nextInt();
      int [] arr= new int[n];
      System.out.println("Enter elements: ");
      for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
      }
      System.out.println("The array is: ");
      for(int elements: arr){
            System.out.println(elements);
      }
      for(int j=0;j<n;j++){
        for(int k=0;k<=arr[j];k++){
            if(arr[j]%j!=0){
                System.out.println(arr[j]);
            }
        }
      }
    }
}
