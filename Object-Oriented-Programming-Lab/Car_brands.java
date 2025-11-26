import java.util.*;
class Cars{
    public static void main(String[] args){
        int ref_num;
        System.out.print("Enter Reference number: ");
        Scanner sc=new Scanner(System.in);       
        ref_num=sc.nextInt();
        if(ref_num==1){
            System.out.print("Hyundai");
        }
        else if(ref_num==2){
            System.out.print("Kia");
        }
        else if(ref_num==3){
            System.out.print("Morris Garage");
        }
        else if(ref_num==4){
            System.out.print("Volks Wagon");
        }
        else{
            System.out.print("List over");
        }
    }
}