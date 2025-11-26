import java.util.*;
class Operations{
    public static void main(String[] args){
       int i,j;
       System.out.print("Enter i and j:"); 
       Scanner sc=new Scanner(System.in);
       i=sc.nextInt();
       j=sc.nextInt();
       int sum=i+j;
       System.out.println("sum= "+sum);
       int diff=i-j;
       System.out.println("diff= "+diff);
       int product=i*j;
       System.out.println("product= "+product);
       float div=i/j;
       System.out.println("div= "+div);
    }
}