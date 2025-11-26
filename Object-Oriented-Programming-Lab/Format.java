import java.util.*;

import javax.sound.sampled.SourceDataLine;
class Employee{
    Scanner sc=new Scanner(System.in);
    String name;
    char[] ename;
    Employee(){
        System.out.println("Enter employee name: ");
        name=sc.nextLine();
        ename=name.toCharArray();
    }
    void formatEmployeeName(){
        if(ename[0]>='a' && ename[0]<='z'){
            ename[0]=(char)(ename[0]-32);
        }
        int pos1=name.indexOf(" ");
        if(ename[pos1+1]>='a' && ename[pos1+1]<='z'){
            ename[pos1+1]=(char)(ename[pos1+1]-32);
            System.out.println("\n"+new String(ename));
        }
    }
    void generateEmail(){
        if(ename[0]>='A' && ename[0]<='Z'){
            ename[0]=(char)(ename[0]+32);
        }
        String s1 = name.substring(0, 1);
        s1 = s1.toLowerCase();
        int pos=name.indexOf(" ");
        String s2 = name.substring(pos+1);
        //System.out.println(s2);
        System.out.println("\n\nEmail ID: "+s1+s2+"@gmail.com\n\n");
    }
    public static void main(String[] args) {
        Employee obj=new Employee();
        obj.formatEmployeeName();
        obj.generateEmail();
    }
}