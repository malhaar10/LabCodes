import java.util.*;
import java.util.Scanner;
class Linear{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);

		System.out.println("Enter array size : ");
		int n=sc.nextInt();

		int[] a=new int[n];

		System.out.println("Enter "+n+" elements : ");
		for(int i=0;i<a.length;i++)
			a[i]=sc.nextInt();

		System.out.print("Enter element to be found : ");
		int ele=sc.nextInt();

		int pos=-1;
		for(int i=0;i<n;i++)
			if(a[i]==ele){
				pos=i;
				break;
			}
		if(pos==-1)
			System.out.println("Element not in array");
		else
			System.out.println("Element found at index "+pos);
	}
}
