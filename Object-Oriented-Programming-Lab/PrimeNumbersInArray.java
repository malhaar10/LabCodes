public class PrimeNumbersInArray {
    static boolean isPrime(int num) {
        if (num <= 1){
            return false;
        }
        for (int i = 2; i * i <= num; i++){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        int[] array = {2, 7, 15, 19, 23, 6, 13};
        System.out.println("Prime numbers in the array:");
        for (int num : array) {
            if (isPrime(num)) {
                System.out.println(num);
            }
        }
    }
}