
public class BinarySearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid;
        
        while (left <= right) {
        	mid = left + (right - left) / 2;
        	
        	if (nums[mid] == target)
        		return mid;
        	else if (nums[mid] < target)
        		left = mid + 1;
        	else
        		right = mid - 1;
        }
        
        return -1;
    }

}
