import java.util.*;
class Marks{
    public static void main(String[] args){
        int math,sans,eng,sst,sci;
        Scanner marks=new Scanner(System.in);
        math=marks.nextInt();
        sans=marks.nextInt();
        sst=marks.nextInt();
        eng=marks.nextInt();
        sci=marks.nextInt();
        System.out.println("Marks in math: "+math+"\n sans: "+sans+"\n sst: "+sst+"\n eng: "+eng+"\n sci: "+sci);
    }
}