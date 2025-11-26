import java.util.*;
class Max{
    public static void main(String[] args){
        int x,y,z;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter x, y and z: ");
        x=sc.nextInt();
        y=sc.nextInt();
        z=sc.nextInt();
        if(x>y && x>z){
            System.out.print("X is greatest.");
        }
        else if(y>x && y>z){
            System.out.print("y is greatest.");
        }
        else if(z>x && z>y){
            System.out.print("z is greatest.");
        }
    }    
}