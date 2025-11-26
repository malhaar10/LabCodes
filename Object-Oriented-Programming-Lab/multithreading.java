class Multi extends Thread {
    double d2, a = 2, b = 2, c = 2;

    @Override
    public void run() {
        d2 = a * b;
        System.out.println("Result d2: " + d2);
    }
}

class Multi2 extends Thread {
    double d1, a = 2, b = 2, c = 2;

    @Override
    public void run() {
        d1 = a * b * c;
        System.out.println("Result d1: " + d1);
    }
}

public class MultithreadingExample {
    public static void main(String[] args) {
        Multi mul = new Multi();
        Multi2 mul1 = new Multi2();

        mul.start();
        mul1.start();

        // Wait for both threads to finish
        try {
            mul.join();
            mul1.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main method exiting.");
    }
}
