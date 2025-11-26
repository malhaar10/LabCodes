import java.util.*;
class Methods{
    int x,y;
    void meth1(){
        System.out.println("Enter x and y: ");
        Scanner sc= new Scanner(System.in);
        x=sc.nextInt();
        y=sc.nextInt();
        int z=x+y;
        System.out.println(z);
    }
    void meth1(int a){
        System.out.println("nigga "+a);
    }
    public static void main(String[] args) {
        Methods obj=new Methods();
        obj.meth1();
        obj.meth1(69);
    }
}
/*class Methods2{
    public static void main(String[] args) {
        System.out.println("youre a");
    }
}*/