class Person {
    private String name;
    private String birthDate;
    public Person(String name, String birthDate) {
        this.name = name;
        this.birthDate = birthDate;
    }
    public String getName() {
        return name;
    }
    public String getBirthDate() {
        return birthDate;
    }
}
class CollegeGraduate extends Person {
    private double gpa;
    private int graduationYear;
    public CollegeGraduate(String name, String birthDate, double gpa, int graduationYear) {
        super(name, birthDate);
        this.gpa = gpa;
        this.graduationYear = graduationYear;
    }
    public double getGPA() {
        return gpa;
    }
    public int getGraduationYear() {
        return graduationYear;
    }
}
class Person_life{
    public static void main(String[] args) {
        Person person = new Person("Malhaar", "10-09-2004");
        CollegeGraduate graduate = new CollegeGraduate("Malhaar", "10-09-2004", 9.0, 2026);
        System.out.println("Person Details:");
        System.out.println("Name: " + person.getName());
        System.out.println("Birth Date: " + person.getBirthDate());
        System.out.println("\nCollege Graduate Details:");
        System.out.println("Name: " + graduate.getName());
        System.out.println("Birth Date: " + graduate.getBirthDate());
        System.out.println("GPA: " + graduate.getGPA());
        System.out.println("Graduation Year: " + graduate.getGraduationYear());
    }
}
