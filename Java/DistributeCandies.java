import java.util.HashSet;

public class DistributeCandies {

	public static void main(String[] args) {
		int[] nums = new int[] { 1, 1, 2, 2, 3, 4 };
		distributeCandies(nums);
	}

	public static int distributeCandies(int[] candyType) {
        HashSet<Integer> types = new HashSet<>();
        int halfSize = candyType.length / 2;
        
        for (int i : candyType) {
        	types.add(i);
        	if (types.size() >= halfSize)
        		return halfSize;
        }
        
        return Integer.min(halfSize, types.size());
    }
}
