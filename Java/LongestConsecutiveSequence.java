import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class LongestConsecutiveSequence {

	public static void main(String[] args) {
		int[] nums = new int[] {0,3,7,2,5,8,4,6,0,1};
		longestConsecutive(nums);
	}

	public static int longestConsecutiveSorted(int[] nums) {
        // time complexity: O(n log n) due to sorting
		// space complexity: O(n)
		
		if (nums == null || nums.length == 0)
        	return 0;
        
        List<Integer> list = Arrays.stream(nums).boxed().collect(Collectors.toList());
        Collections.sort(list);
        
        int longest = 1;
        int length = 1;
        int val = nums[0];
        
        for (int i = 0; i < list.size(); i++) {
        	if (val == list.get(i))
        		continue;
        	
        	if ( list.get(i)== val + 1) {
        		val = list.get(i);
        		length++;
        		if (length > longest)
        			longest++;
        		continue;
        	}
        	
        	val = list.get(i);
        	length = 1;
        }
        
        return longest;
    }
	
	public static int longestConsecutive(int[] nums) {
		// time complexity: O(n)
		// space complexity: O(n)
		
		if (nums == null || nums.length == 0)
			return 0;
		
		int longest = 1;
		int length = 1;
		Set<Integer> set = Arrays.stream(nums).boxed().collect(Collectors.toSet());
		
		for (Integer i : set) {
			if (set.contains(i - 1))
				continue;
			
			length = 1;
			while (set.contains(i + length)) {
				length++;
				longest = Math.max(longest, length);
			}
			
		}
		
		return longest;
	}
}
