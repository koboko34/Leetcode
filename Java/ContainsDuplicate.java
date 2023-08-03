import java.util.HashSet;

public class ContainsDuplicate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static boolean containsDuplicate(int[] nums) {
        HashSet<Integer> map = new HashSet<>();
        
        for (int i : nums) {
        	if (map.contains(i))
        		return true;
        	map.add(i);
        }
        
        return false;
    }
}
