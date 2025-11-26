import java.util.*;
class Vehicle{
    public static void main(String[] args){
        int wheel_count;
        System.out.print("Enter the number of wheels: ");
        Scanner sc=new Scanner(System.in);       
        wheel_count=sc.nextInt();
        if(wheel_count==1){
            System.out.print("Doesn't exist");
        }
        if(wheel_count==2){
            System.out.print("Motorcycle/bicycle");
        }
        else if(wheel_count==3){
            System.out.print("Auto-rickshaw");
        }
        else if(wheel_count==4){
            System.out.print("Car/Semi-truck");
        }
        else if(wheel_count>=4){
            System.out.print("Truck");
        }
        else{
            System.out.print("List over");
        }
    }
}