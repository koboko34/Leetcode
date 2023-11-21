
public class RemoveElement {

	public static void main(String[] args) {
		int[] nums = new int[] {0, 1, 2, 2, 3, 0, 4, 2};
		removeElement(nums, 2);
	}
	
	public static int removeElement(int[] nums, int val) {
        if (nums == null || nums.length == 0)
        	return 0;
        
        if (nums.length == 1)
        	return nums[0] == val ? 0 : 1;
		
		int l = 0;
        int r = nums.length - 1;
        
        while (r >= 0 && nums[r] == val) {
        	r--;
        }
        
        while (l < r) {
        	if (nums[l] == val) {
        		nums[l] = nums[r];
        		nums[r] = val;
        	}
    		l++;
        	
        	while (r >= 0 && nums[r] == val && r > l) {
        		r--;
        	}
        }
        
        if (r < 0)
        	return 0;
        
        if (r == 0)
        	return nums[0] == val ? 0 : 1;

       	return nums[r] == val ? r : r + 1;
    }

}
