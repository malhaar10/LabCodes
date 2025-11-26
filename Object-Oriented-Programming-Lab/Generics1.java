//package Division;

import java.util.*;

public class Generics1{
	void Division(double a, double b){;
		try {
			double c = a / b;
			System.out.println("Quotiont: "+c);
		}catch (ArithmeticException e){
			System.out.println("The code worked, also you can't divide by 0 idiot.");
		}finally {
			System.out.println("Random bullshit go.");
		}
	}
	public static void main(String [] args) {
		Scanner sc = new Scanner (System.in);
		Generics1 div = new Generics1();
		System.out.println("Enter numbers to divide: ");
		double a =sc.nextDouble();
		double b = sc.nextDouble();
		div.Division(a, b);
	}
}
