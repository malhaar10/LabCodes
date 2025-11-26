import java.util.*;
class Marks{
    public static void main(String[] args){
        int math,sans,eng,sst,sci;
        System.out.println("Enter marks:");
        Scanner marks=new Scanner(System.in);
        math=marks.nextInt();
        sans=marks.nextInt();
        sst=marks.nextInt();
        eng=marks.nextInt();
        sci=marks.nextInt();
        System.out.println("Marks in math: "+math+"/ 100 \n sans: "+sans+"/100\n sst: "+sst+"/100\n eng: "+eng+"/100\n sci: "+sci+"/100");
    }
}