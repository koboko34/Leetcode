
public class MaximumSubarray {

	public static void main(String[] args) {

	}
	
	public static int maxSubArray(int[] nums) {
        // time complexity: O(n)
		// space complexity: O(1)
		
		int maxSub = nums[0];
        int curSub = 0;
        
        for (int right = 0; right < nums.length; right++) {
        	if (curSub < 0)
        		curSub = nums[right];
        	else
        		curSub += nums[right];
        	
        	if (curSub > maxSub)
        		maxSub = curSub;
        }
        
        return maxSub;
    }

}
