
public class MaximumProductOfThreeNumbers {

	public static void main(String[] args) {
		int[] nums = new int[] { -1, -2, -3, -4 };
		maximumProduct(nums);
	}
	
	public static int maximumProduct(int[] nums) {
        int first = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;
        int third = Integer.MIN_VALUE;
        
        int firstLast = Integer.MAX_VALUE;
        int secondLast = Integer.MAX_VALUE;
        
        for (int i : nums) {
        	if (i >= first) {
        		third = second;
        		second = first;
        		first = i;
        	}
        	else if (i >= second) {
        		third = second;
        		second = i;
        	}
        	else if (i > third)
        		third = i;
        	
        	if (i <= firstLast) {
        		secondLast = firstLast;
        		firstLast = i;
        	}
        	else if (i <= secondLast)
        		secondLast = i;
        }
        
        if (first < 0)
        	return first * second * third;
        
        if (firstLast < 0 && secondLast < 0) {
        	int minSum = firstLast * secondLast;
        	int maxSum = second * third;
        	if (minSum > maxSum)
        		return first * minSum;
        }
        return first * second * third;
    }

}
