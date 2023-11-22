import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class TopKFrequentElements {

	public static void main(String[] args) {
		int[] nums = new int[] {1, 1, 1, 2, 2, 3};
		topKFrequent(nums, 2);
	}
	
	public static int[] topKFrequent(int[] nums, int k) {
        if (nums.length == 0 || k == 0)
        	return null;
        
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        
        for (int i : nums) {
        	incrementMap(hashMap, i);
        }
        
        Map<Integer, Integer> sorted = hashMap.entrySet()
        		.stream()
        		.sorted(Map.Entry.comparingByValue())
        		.collect(Collectors.toMap(
        				Map.Entry::getKey,
        				Map.Entry::getValue,
        				(oldValue, newValue) -> oldValue, LinkedHashMap::new));
        
        Set<Integer> set = sorted.keySet();
        
        Integer[] setArray = set.toArray(new Integer[k]);
        Integer[] sizedArray = new Integer[k];
        int length = setArray.length;
        for (int i = 0; i < k; i++) {
        	sizedArray[i] = setArray[length - i - 1];
        }

        int[] result = Arrays.stream(sizedArray).mapToInt(Integer::intValue).toArray();
        
        return result;
    }
	
	private static void incrementMap(HashMap<Integer, Integer> map, int key) {
		if (map.containsKey(key)) {
			map.put(key, map.get(key) + 1);
		}
		else {
			map.put(key, 1);
		}
	}

}
