import java.util.*;
class Record{
    int RegNo, i=0;
    String name,shortyear;
    String DOJ;
    Short Sem;
    float GPA1,GPA2,CGPA;
    Scanner sc = new Scanner (System.in);
    void joining(){
        System.out.print("Enter student name: ");
        name = sc.nextLine();
        System.out.print("Enter date of joining(): ");
        DOJ = sc.nextLine();
        System.out.print("Enter GPA1 and GPA2: ");
        GPA1 = sc.nextFloat();
        GPA2 = sc.nextFloat();
        System.out.print("Enter semester: ");
        Sem = sc.nextShort();
        i++;
        //System.out.println(i);
    }
    void calculate(){
        CGPA = (GPA1+GPA2)/2;
        System.out.print("CGPA: "+CGPA);
        shortyear = DOJ.substring(8);
    }
    void display(){
    }
    public static void main(String args[]){
        Record obj = new Record();
        obj.joining();
        obj.calculate();
        obj.display();
    }
}