import java.util.Arrays;
import java.util.HashMap;

public class MajorityElement {

	public static void main(String[] args) {

	}
	
	public static int majorityElement(int[] nums) {
		int ans = 0;
		int count = 0;
		
		for (int i : nums) {
			if (count == 0) {
				ans = i;
				count++;
				continue;
			}
			count += ans == i ? 1 : -1;
		}
		
		return ans;
	}
	
	public static int majorityElementSort(int[] nums) {
		Arrays.sort(nums);
		return nums[nums.length / 2];
	}
	
	public static int majorityElementHashmap(int[] nums) {
        if (nums.length == 1)
        	return nums[0];
		
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
        	if (map.containsKey(i)) {
        		map.replace(i, map.get(i) + 1);
        	}
        	else {
        		map.put(i, 1);
        	}
        	
        	if (map.get(i) > nums.length / 2) {
        		return i;
        	}
        }
        
        return -1;
    }

}
