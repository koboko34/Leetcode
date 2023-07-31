import java.util.Collection;
import java.util.HashMap;

public class SingleNumber {

	public static void main(String[] args) {

	}
	
	
	public static int singleNumber(int[] nums) {
		int solution = 0;
		
		for (int i : nums) {
			solution = solution ^ i;
		}
		
		return solution;
	}
	
	public static int singleNumberHashmap(int[] nums) {
        if (nums.length == 1) {
        	return nums[0];
        }
        
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
        	if (map.containsKey(i)) {
        		map.remove(i);
        		continue;
        	}
        	
        	map.put(i, i);
        }
        
        Collection<Integer> c = map.values();
        int solution = 0;
        for (int i : c) {
        	return i;
        }
        
        return solution;
    }

}
