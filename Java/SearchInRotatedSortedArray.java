
public class SearchInRotatedSortedArray {

	public static void main(String[] args) {
		int[] nums = new int[] {5,1,2,3,4};
		search(nums, 1);
	}
	
	public static int search(int[] nums, int target) {
        // time complexity: O(log n)
		// space complexity: O(1)
		
		if (nums.length == 1)
        	return nums[0] == target ? 0 : -1;
        
        int l = 0;
        int r = nums.length - 1;
        int mid;
        
        while (l <= r) {
        	mid = (l + r) / 2;
        	
        	if (nums[mid] == target)
        		return mid;
        	
        	if (nums[l] < nums[r]) {
        		if (nums[mid] > target) {
        			r = mid - 1;
        		}
        		else {
        			l = mid + 1;
        		}
        		continue;
        	}
        	
        	if (nums[mid] < target) {
        		if (nums[r] >= target || nums[r] < nums[mid]) {
        			l = mid + 1;
        		}
        		else {
        			r = mid - 1;
        		}
        		continue;
        	}	
        	
        	if (nums[mid] > target) {
        		if (nums[l] <= target || nums[l] > nums[mid]) {
        			r = mid - 1;
        		}
        		else {
        			l = mid + 1;
        		}
        		continue;
        	}
        	
        }
		
		return -1;
    }

}
