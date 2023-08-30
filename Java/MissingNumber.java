import java.util.HashSet;
import java.util.stream.IntStream;

public class MissingNumber {

	public static void main(String[] args) {
		int nums[] = new int[] {3, 0, 1};
		missingNumber(nums);
	}
	
	public static int missingNumber(int[] nums) {
		// time complexity: O(n)
		// space complexity: O(1)
		
		int range[] = IntStream.rangeClosed(0, nums.length).toArray();
		int ans = 0;
		
		for (int i : nums) {
			ans = ans ^ i;
		}
		
		for (int i : range)
			ans = ans ^ i;
		
		return ans;
	}
	
	public static int missingNumberSum(int[] nums) {
		// time complexity: O(n)
		// space complexity: O(1)
		
		int numsSum = IntStream.of(nums).sum();
		int sum = IntStream.rangeClosed(0, nums.length).sum();
		
		return sum - numsSum;
	}
	
	public static int missingNumberHashSet(int[] nums) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		int max = Integer.MIN_VALUE;
		
        HashSet<Integer> set = new HashSet<>();
        
        for (int i : nums) {
        	if (i > max)
        		max = i;
        	set.add(i);
        }
        
        for (int i = 0; i <= max; i++) {
        	if (!set.contains(i))
        		return i;
        }
        
		return max + 1;
    }

}
