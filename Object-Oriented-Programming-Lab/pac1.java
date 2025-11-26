//package com.course.structure;
import com.course.structure.Building;
import com.course.structure.House;
import com.course.structure.School;
import java.util.*;

public class Building {
	private int floors;
	private float sqfoots;
	public Building(float area, int floor) {
		floors=floor;
		sqfoots=area;
	}
	public float getArea() {
		return sqfoots;
	}
	public int getFloors() {
		return floors;
	}
}

public class House extends Building {
	private int bedroom, bathroom;
	public House(int bed, int bath, float area, int floor) {
		super(area, floor);
		bedroom = bed;
		bathroom = bath;
	}
	public void display() {
		System.out.println("\n\t-----HOUSE----- ");
		System.out.println("\t"+bedroom+" bedroom");
		System.out.println("\t"+bathroom+" bathroom");
        System.out.println("\t" + getArea()+" square ft.");
        System.out.println("\t" + getFloors()+" floors");
	}
}

public class School extends Building {
	private int classroom;
	private String level;
	public School(int classes, String grade, float area, int floor) {		
		super(area, floor);
		classroom = classes;
		level=grade;
	}
	public void display() {
		System.out.println("\n\t-----SCHOOL------ ");
		System.out.println("\t"+classroom+" classes");
		System.out.println("\t"+level+" level");
        System.out.println("\t" + getArea()+" square ft.");
        System.out.println("\t" + getFloors()+" floors");
	}
}

public class BuildingTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("\tHOUSE");
		System.out.println("Number of bedrooms and bathrooms : ");
		int bed = sc.nextInt();
		int bath = sc.nextInt();
		System.out.println("Area in square foots : ");
		float a1 = sc.nextFloat();
		System.out.println("Number of floors : ");
		int f1 = sc.nextInt();
		House h = new House(bed, bath, a1, f1);
		System.out.println("\n\tSCHOOL");
		System.out.println("Number of Classroom : ");
		int classes = sc.nextInt();
		System.out.println("Grade : ");
		sc.nextLine();
		String grade = sc.nextLine();
		System.out.println("Area in square foots : ");
		float a2 = sc.nextFloat();
		System.out.println("Number of floors : ");
		int f2 = sc.nextInt();
		School s = new School(classes, grade, a2, f2);
		h.display();
		s.display();
	}
}
