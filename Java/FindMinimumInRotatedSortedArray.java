
public class FindMinimumInRotatedSortedArray {

	public static void main(String[] args) {
		int[] nums = new int[] {4,5,6,7,0,1,2};
		findMin(nums);
	}
	
	public static int findMin(int[] nums) {
        if (nums.length == 1)
        	return nums[0];
		
		int l = 0;
        int r = nums.length - 1;
        int mid;
        int lowest = Math.min(nums[l], nums[r]);
        
        while (l <= r) {
        	if (nums[l] < nums[r])
        		return nums[l];
        	
        	mid = (l + r) / 2;
        	
        	if (nums[mid] < nums[l]) {
        		r = mid;
        		lowest = Math.min(nums[mid], lowest);
        		continue;
        	}

        	l = mid;
        	
        	if (r - l == 1)
        		return Math.min(Math.min(nums[l], nums[r]), lowest);
        	
        }
        
        return lowest;
    }

}
