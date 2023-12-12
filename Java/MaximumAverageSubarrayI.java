public class MaximumAverageSubarrayI {

	public static void main(String[] args) {
		int[] nums = new int[] {-1};
		findMaxAverage(nums, 1);
	}

	public static double findMaxAverage(int[] nums, int k) {
		int ans = Integer.MIN_VALUE;
		int sum = 0;
		
		for (int i = 0; i < k; i++) {
			sum += nums[i];
		}
		ans = sum;
		
		for (int i = k; i < nums.length; i++) {
			sum += nums[i] - nums[i - k];
			ans = Math.max(ans, sum);
		}
		
		return (double)ans / k;
    }
}
