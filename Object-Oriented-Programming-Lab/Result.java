import java.util.Scanner;

interface Sports {
    void putGrade();
}

class Student4 {

    Scanner sc = new Scanner(System.in);
    int rollno, marks;

    void getNumber() {
        System.out.println("Enter roll number:");
        rollno = sc.nextInt();
    }

    void putNumber() {
        System.out.println("Roll number:" + rollno);
    }

    void getMarks() {
        System.out.println("Enter marks:");
        marks = sc.nextInt();
    }

    void putMarks() {
        System.out.println("Roll number:" + marks);
    }

}

public class Result implements Sports {

    Scanner sc = new Scanner(System.in);
    String grade;

    Result() {
        System.out.println("Enter grade in sports:");
        grade = sc.next();
    }

    public void putGrade() {
        System.out.println("Grade in sports is:" + grade);
    }

    public static void main(String[] args) {
        Student4 s = new Student4();
        s.getNumber();
        s.getMarks();
        Result r = new Result();
        s.putNumber();
        s.putMarks();
        r.putGrade();
    }

}
