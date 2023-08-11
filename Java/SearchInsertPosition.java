
public class SearchInsertPosition {

	public static void main(String[] args) {

	}
	
	public static int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid = left + (right - left) / 2;
        
        while (left <= right) {
        	mid = left + (right - left) / 2;
        	
        	if (nums[mid] == target)
        		return mid;
        	else if (nums[mid] < target)
        		left = mid + 1;
        	else
        		right = mid - 1;
        }
        
        if (nums[mid] > target)
        	return mid;
        
        return mid + 1;
    }

}
