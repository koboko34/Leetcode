
public class Sqrt {

	public static void main(String[] args) {
		mySqrt(2147395599);
	}
	
	public static int mySqrt(int x) {
        // time complexity: O(log n)
		// space complexity: O(1)
		
		int left = 0;
        int right = x;
        int mid;
        int ans = 1;
        
        while (right >= left) {
        	mid = (right - left) / 2 + left;
        	
        	if (mid * mid == x)
        		return mid;
        	else if ((long) mid * mid < (long) x) {
        		left = mid + 1;
        		if (mid > ans)
        			ans = mid;
        	}
        	else
        		right = mid - 1;
        }
        
        return ans;
    }
}
