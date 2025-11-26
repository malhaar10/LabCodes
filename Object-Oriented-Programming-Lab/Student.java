import java.util.*;
class Student {
    String name;
    Scanner sc = new Scanner(System.in);
    Student() {
        System.out.print("\nEnter student name: ");
        name = sc.nextLine();
        extractInitials();
        removeWhiteSpace();
    }
    void extractInitials() {
        String s1 = name.substring(0, 1);
        int pos = name.indexOf(" ");
        String s2 = name.substring(pos + 1, pos + 2);
        s1 = s1.toUpperCase();
        s2 = s2.toUpperCase();
        System.out.println("\nInitials: "+s1 + s2);
    }
    void removeWhiteSpace() {
        int pos1 = name.indexOf(" ");
        String s4 = name.substring(0, pos1);
        String s5 = name.substring(pos1 + 1);
        System.out.println("Names without white spaces: "+s4 + s5);
    }
    boolean findSubstring(String substring) {
        return name.contains(substring);
    }
    static void sortNames(String[] names) {
        Arrays.sort(names);
        System.out.println("\nSorted names:");
        for (String name : names) {
            System.out.println(name);
        }
    }
    public static void main(String args[]) {
        Scanner sd = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = sd.nextInt();
        Student[] obj = new Student[n];
        String[] studentNames = new String[n];
        for (int i = 0; i < n; i++) {
            obj[i] = new Student();
            studentNames[i] = obj[i].name;
            System.out.println("---------------------XXX------------------");
        }
        System.out.print("Enter the substring to search for: ");
        String searchSubstring = sd.next();
        System.out.println("Students containing the substring '" + searchSubstring + "':");
        for (Student student : obj) {
            if (student.findSubstring(searchSubstring)) {
                System.out.println(student.name);
            }
        }
        sortNames(studentNames);
    }
}
