
	public class GenericLargest {

		public static <T extends Comparable<T>> T findLargest(T x, T y, T z) {
			T largest = x;
	
			if (y.compareTo(largest) > 0) {
				largest = y;
			}
	
			if (z.compareTo(largest) > 0) {
				largest = z;
			}
	
			return largest;
		}
	
		public static void main(String[] args) {
			// Example usage
			Integer intResult = findLargest(5, 10, 3);
			System.out.println("Largest integer: " + intResult);
	
			Double doubleResult = findLargest(2.5, 1.0, 3.8);
			System.out.println("Largest double: " + doubleResult);
	
			String strResult = findLargest("apple", "orange", "banana");
			System.out.println("Largest string: " + strResult);
		}
	}

