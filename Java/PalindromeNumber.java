import java.util.ArrayList;

public class PalindromeNumber {

	public static void main(String[] args) {

	}
	
	public static boolean isPalindrome(int x) {
        if (x < 0)
        	return false;
        
        if (x == 0)
        	return true;
        
        ArrayList<Integer> nums = new ArrayList<>();
        while (x != 0)
        {
        	int r = x % 10;
        	nums.add(r);
        	x /= 10;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
        	if (nums.get(left) != nums.get(right))
        		return false;
        	
        	left++;
        	right--;
        }
		
		return true;
    }

}
