import java.util.Scanner;

interface Series {

    int getNext(int start);

    int reset(int start);

    int setStart();
}

class ByTwos implements Series {

    public int setStart() {
        //@SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number to start the series:");
        int num = sc.nextInt();
        return num;
    }

    public int getNext(int start) {
        start = start + 2;
        return start;
    }

    public int reset(int start) {
        start = 0;
        return start;
    }
}

public class ExecuteSeries {

    public static void main(String[] args) {
        int start = 0;
        //@SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        ByTwos b = new ByTwos();
        System.out.println("1.Set start\n2.Get next\n3.Reset\n4.Exit");
        while (true) {

            System.out.println("\nEnter choice");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    start = b.setStart();
                    break;
                case 2:
                    start = b.getNext(start);
                    System.out.println("Next element is:" + start);
                    break;
                case 3:
                    start = b.reset(start);
                    System.out.println("The series is reset");
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice");

            }
        }
    }
}
