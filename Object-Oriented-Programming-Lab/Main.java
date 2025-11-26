class Student {
    protected String name;
    protected int rollNumber;
    protected double totalMarks;
    protected double averageMarks;

    public Student(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
    }

    public void compute() {
        // To be implemented in subclasses
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Total Marks: " + totalMarks);
        System.out.println("Average Marks: " + averageMarks);
    }
}

class ScienceStudent extends Student {
    private int practicalMarks;

    public ScienceStudent(String name, int rollNumber, int practicalMarks) {
        super(name, rollNumber);
        this.practicalMarks = practicalMarks;
    }

    @Override
    public void compute() {
        totalMarks = practicalMarks;
        averageMarks = totalMarks;
    }

    public void displayPracticalMarks() {
        System.out.println("Practical Marks: " + practicalMarks);
    }
}

class ArtsStudent extends Student {
    private String electiveSubject;

    public ArtsStudent(String name, int rollNumber, String electiveSubject) {
        super(name, rollNumber);
        this.electiveSubject = electiveSubject;
    }

    @Override
    public void compute() {
        totalMarks = 0;
        averageMarks = 0;
    }

    public void displayElectiveSubject() {
        System.out.println("Elective Subject: " + electiveSubject);
    }
}

public class Main {
    public static void main(String[] args) {
        Student student1 = new ScienceStudent("Malhaar", 1, 95);
        Student student2 = new ArtsStudent("Abcde", 2, "Chemistry");

        student1.compute();
        student2.compute();

        student1.displayInfo();
        ((ScienceStudent) student1).displayPracticalMarks();

        System.out.println();

        student2.displayInfo();
        ((ArtsStudent) student2).displayElectiveSubject();
    }
}
