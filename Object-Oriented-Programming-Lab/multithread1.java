import java.util.*;
class Function1 extends Thread{
    public void run(){
        int i = 88 * 88;
        System.out.println("Thread1 running  "+i);
    }
}
class Function2 extends Thread{
    public void run(){
        int j = 99*99;
        System.out.println("Thread2 running  "+j);
    }
}
class Main{
    public static void main(String[] args) {
        Function1 f1 = new Function1();
        Function2 f2 = new Function2();
        f1.start();
        f2.start();
    }
}