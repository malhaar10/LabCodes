class Student {
    protected String Name;
    protected int Id;
    public Student(String name, int id) {
        Name = name;
        Id = id;
    }
}
class Sports extends Student {
    protected int s_grade;
    public Sports(String name, int id, int s_grade) {
        super(name, id);
        this.s_grade = s_grade;
    }
}
class Exam extends Student {
    protected int e_grade;
    public Exam(String name, int id, int e_grade) {
        super(name, id);
        this.e_grade = e_grade;
    }
}
class Results extends Sports {
    private int e_grade;
    private String finalResult;
    public Results(String name, int id, int s_grade, int e_grade, String finalResult) {
        super(name, id, s_grade);
        this.e_grade = e_grade;
        this.finalResult = finalResult;
    }
    public void display() {
        System.out.println("Student Name: " + Name);
        System.out.println("Student Id: " + Id);
        System.out.println("Sports Grade: " + s_grade);
        System.out.println("Exam Grade: " + e_grade);
        System.out.println("Final Result: " + finalResult);
    }
}
class Main2 {
    public static void main(String[] args) {
        Results studentResult = new Results("Malhaar", 123, 97, 92, "Pass");
        studentResult.display();
    }
}


