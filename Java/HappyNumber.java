import java.util.HashSet;

public class HappyNumber {

	public static void main(String[] args) {

	}
	
	public static boolean isHappy(int n) {
		// time complexity: O(n)
		// space complexity: O(1)
		
		int slow = n;
		int fast = digitSquareSum(n);
		
		while (true) {
			if (slow == 1 || fast == 1)
				return true;
			
			if (slow == fast)
				return false;
			
			slow = digitSquareSum(slow);
			fast = digitSquareSum(fast);
			fast = digitSquareSum(fast);
		}
	}
	
	public static boolean isHappyHashSet(int n) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		HashSet<Integer> set = new HashSet<>();
        
        while (!set.contains(n)) {
        	set.add(n);
        	
        	n = digitSquareSum(n);
        	if (n == 1)
        		return true;
        }
		
		return false;
    }
	
	private static int digitSquareSum(int n) {
		int sum = 0;
		while (n > 0) {
    		sum += Math.pow(n % 10, 2);
    		n /= 10;
    	}
		return sum;
	}

}
