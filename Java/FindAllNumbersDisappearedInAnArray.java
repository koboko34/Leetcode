import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class FindAllNumbersDisappearedInAnArray {

	public static void main(String[] args) {
		int nums[] = new int[] { 1, 2, 3 };		
		findDisappearedNumbers(nums);
	}
	
	public static List<Integer> findDisappearedNumbers(int[] nums) {
        // time complexity: O(n)
		// space complexity: O(n)
		HashSet<Integer> set = new HashSet<>();
        
        Collection<Integer> allNums = IntStream.rangeClosed(1, nums.length).boxed().collect(Collectors.toList());
        
        set.addAll(allNums);
        
        for (int i : nums) {
        	set.remove(i);
        }
        
        return set.stream().toList();
    }

}
