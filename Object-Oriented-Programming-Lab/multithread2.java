import java.util.*;
class NThread1 implements Runnable{
    public void run(){
        System.out.println("Running thread 1.");
    }
}
class NThread2 implements Runnable{
        public void run(){
        System.out.println("Running thread 2.");
    }
}
class Main{
    public static void main(String[] args) {
        NThread1 t1 = new NThread1();
        Thread ta = new Thread(t1);
        NThread2 t2 = new NThread2();
        Thread tb = new Thread(t2);
        ta.start();
        tb.start();
    
    }
}