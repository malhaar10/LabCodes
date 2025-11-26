import java.util.*;
class Employee{
    String Ename;
    int Eid;
    double Basic,DA,Gross_pay,Net_pay,IT;
    Scanner sc=new Scanner(System.in);
    void read(){
        System.out.println("Enter employee name: ");
        Ename=sc.nextLine();
        System.out.println("Enter employee ID: ");
        Eid=sc.nextInt();
        System.out.println("Enter basic pay: ");
        Basic=sc.nextDouble();
    }
    void display(){
        System.out.println("\n\nEmployee name: "+Ename+"\nEmployee ID: "+Eid+"\nNet_pay= "+Net_pay);
        System.out.println("------------------------------------------------XX-----------------------------------------------");
    }
    void compute_net_sal(){
        DA = 0.52*Basic;
        Gross_pay=Basic+DA;
        IT=0.30*Gross_pay;
        Net_pay=Gross_pay-IT;
    }
    public static void main(String[] args) {
        Scanner sd=new Scanner(System.in);
        System.out.println("Enter the number of employees: ");
        int n=sd.nextInt();
        Employee[] obj=new Employee[n];
        for(int i=0;i<n;i++){
            obj[i] = new Employee();
            obj[i].read();
            obj[i].compute_net_sal();
        }
        for(int i=0;i<n;i++){
            obj[i].display();
        }
    }
}