import java.util.*;
class Pallindrome{
    public static void main(String [] args){
        int remainder, reverse=0, n;
        int j;
        System.out.println("Enter number: ");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        n=j;
        remainder=n%10;
        reverse=(reverse*10)+remainder;
        n/=10;
        if(reverse==j){
            System.out.println("This is a palindrome.");
        }
        else{
            System.out.println("Not a palindrome.");
        }
    }
}