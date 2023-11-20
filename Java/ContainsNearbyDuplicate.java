import java.util.HashMap;

public class ContainsNearbyDuplicate {

	public static void main(String[] args) {

	}
	
	public static boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums.length < 2)
        	return false;
		
        HashMap<Integer, Integer> map = new HashMap<>();
		int i = 0;
		while (i < nums.length) {

			if (map.containsKey(nums[i]) && Math.abs(map.get(nums[i]) - i) <= k) {
					return true;
				}
			
			map.put(nums[i], i);
			i++;
		}
		return false;
    }

}
