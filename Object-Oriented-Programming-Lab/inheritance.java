import java.util.*;
class Parent{
    int i, j, k;
    Scanner sc= new Scanner(System.in);
    void input(){
        System.out.println("Enter i,j,k: ");
        i=sc.nextInt();
        j=sc.nextInt();
        k=sc.nextInt();
    }
    void print(){
        System.out.println("Nos: "+ i+","+ j+","+ k);
    }
    class Child extends Parent{
        int z;
        void sum(){
            z=i+j+k;
            System.out.println("Sum: "+z);
        }
    }
    public static void main(String[] args) {
        Parent obj1 = new Parent();
        Parent.Child obj2 = obj1.new Child();
        obj1.input();
        obj1.print();
        obj2.input();
        obj2.sum();
    }
}