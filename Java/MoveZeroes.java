
public class MoveZeroes {

	public static void main(String[] args) {
		int nums[] = new int[] {4,2,4,0,0,3,0,5,1,0};
		moveZeroes(nums);
	}
	
	public static void moveZeroes(int[] nums) {
        if (nums.length == 1)
        	return;
		
        int left = 0;
        int right = 1;
		while (left != nums.length - 1) {
			if (nums[left] != 0) {
				left++;
				right = left + 1;
				continue;
			}
			
			while (right < nums.length) {
				if (nums[right] == 0) {
					right++;
					continue;
				}
				
				nums[left] = nums[right];
				nums[right] = 0;
				break;
			}
			
			left++;
		}
    }

}
