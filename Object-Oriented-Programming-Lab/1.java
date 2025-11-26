import java.util.*;
class Operations{
    public static void main(String[] args){
       int i,j;
       System.out.println("Enter i and j:"); 
       Scanner sc=new Scanner(System.in);
       i=sc.nextInt();
       j=sc.nextInt();
       int sum=i+j;
       System.out.println(sum);
       int diff=i-j;
       System.out.println(diff);
       int product=i*j;
       System.out.println(product);
       int div=i/j;
       System.out.println(div);
    }
}