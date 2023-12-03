import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {

	public static void main(String[] args) {
		int[] nums = new int[] {-1,0,1,2,-1,-4};
		threeSum(nums);
	}

	public static List<List<Integer>> threeSum(int[] nums) {
		// time complexity: O(n^2)
		// space complexity: O(1)
		
		List<List<Integer>> ans = new ArrayList<>();
		
		Arrays.sort(nums);
		
		for (int i = 0; i < nums.length - 1; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			
			int l = i + 1;
			int r = nums.length - 1;
			
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum > 0) {
					r--;
					while (l < r && nums[r] == nums[r + 1])
						r--;
				}
				else if (sum < 0 ){
					l++;
					while (l < r && nums[l] == nums[l - 1])
						l++;
				}
				else {
					ans.add(Arrays.asList(nums[i], nums[l], nums[r]));
					l++;
					while (l < r && nums[l] == nums[l - 1])
						l++;
				}
			}
		}
		
		return ans;
    }
}
