//package MT;

class Threading extends Thread{
	@Override
	public void run() {
		System.out.println("Thread 1 running.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class Threading2 extends Thread{
	public void run() {
		System.out.println("Thread 2 running.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
class Threading3 extends Thread{
	public void run() {
		System.out.println("Thread 3 running.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
class Threading4 extends Thread{
	public void run() {
		System.out.println("Thread 4 running.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
class Threading5 extends Thread{
	public void run() {
		System.out.println("Thread 5 running.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
class Threading6 extends Thread{
	public void run() {
		System.out.println("Thread 6 running.");
		try {
			Thread.sleep(200);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
class Threading7 extends Thread{
	public void run() {
		System.out.println("Thread 7 running.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
class Threading8 extends Thread{
	public void run() {
		System.out.println("Thread 8 running.");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

public class MultithreadingExample {
	public static void main(String args[]) {
		Threading t1 = new Threading();
		Threading2 t2 = new Threading2();
		Threading3 t3 = new Threading3();
		Threading4 t4 = new Threading4();
		Threading5 t5 = new Threading5();
		Threading6 t6 = new Threading6();
		Threading7 t7 = new Threading7();
		Threading8 t8 = new Threading8();
		
		t1.start();
		try {
			t1.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		t2.start();
		try {
			t2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		t3.start();
		try {
			t3.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		t4.start();
		try {
			t4.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		t5.start();
		try {
			t5.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		t6.start();
		try {
			t6.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		t7.start();
		try {
			t7.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		t8.start();
		try {
			t8.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.print("Threading process over.");
	}
}
