import java.util.HashMap;

public class LongestHarmoniousSequence {

	public static void main(String[] args) {

	}
	
	public static int findLHS(int[] nums) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		HashMap<Integer, Integer> map = new HashMap<>();
		
		for (int i : nums) {
        	if (map.containsKey(i)) {
        		map.put(i, map.get(i) + 1);
        		continue;
        	}
        	map.put(i, 1);
        }
		
		int lhs = 0;
		
		for (HashMap.Entry<Integer, Integer> set : map.entrySet()) {
			if (map.containsKey(set.getKey() + 1))
				lhs = Math.max(lhs, set.getValue() + map.get(set.getKey() + 1));
		}
		return lhs;
    }

}
