
public class ProductOfArrayExceptSelf {

	public static void main(String[] args) {
		int[] nums = new int[] {1, 2, 3, 4};
		productExceptSelf(nums);
	}
	
	public static int[] productExceptSelf(int[] nums) {		
		// time complexity: O(n)
		// space complexity: O(n)
		
		int[] ans = new int[nums.length];
        
        ans[0] = 1;
        int i = 1;
        while (i < nums.length) {
        ans[i] = ans[i - 1] * nums[i - 1];
        	i++;
        }
        
        i = nums.length - 2;
        int postfix = 1;
        while (i >= 0) {
        	postfix *= nums[i + 1];
        	ans[i] *= postfix;
        	i--;
        }

		return ans;
    }

}
