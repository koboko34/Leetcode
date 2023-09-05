
public class HouseRobber {

	public static void main(String[] args) {
		
	}
	
	public static int rob(int[] nums) {
        int rob1 = 0;
        int rob2 = 0;
        
        for (int i = 0; i < nums.length; i++) {
        	int sum = Math.max(nums[i] + rob1, rob2);
        	rob1 = rob2;
        	rob2 = sum;
        }
        
        return rob2;
    }

}
