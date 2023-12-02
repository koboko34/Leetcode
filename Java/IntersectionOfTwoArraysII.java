import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class IntersectionOfTwoArraysII {

	public static void main(String[] args) {
		
	}
	
	public static int[] intersect(int[] nums1, int[] nums2) {
		// time complexity: O(n log n)
		// space complexity: O(1)
		
		int length1 = nums1.length;
		int length2 = nums2.length;
		Arrays.sort(nums1);
		Arrays.sort(nums2);
		int i = 0, j = 0, k = 0;
		
		while (i < length1 && j < length2) {
			if (nums1[i] < nums2[j]) {
				i++;
			}
			else if (nums1[i] > nums2[j]) {
				j++;
			}
			else {
				nums1[k++] = nums1[i++];
				j++;
			}
		}
		
		return Arrays.copyOfRange(nums1, 0, k);
	}
	
	public static int[] intersectHashmap(int[] nums1, int[] nums2) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		HashMap<Integer, Integer> map = new HashMap<>();
		
        for (int i : nums1) {
        	if (map.containsKey(i)) {
        		map.put(i, map.get(i) + 1);
        	}
        	else {
        		map.put(i, 1);
        	}
        }
        
        ArrayList<Integer> list = new ArrayList<>();
        
        for (int i : nums2) {
        	if (map.containsKey(i) && map.get(i) > 0) {
        		map.put(i, map.get(i) - 1);
        		list.add(i);
        	}
        }
        
		int[] ans = list.stream().mapToInt(i -> i).toArray();
        
        return ans;
    }

}
