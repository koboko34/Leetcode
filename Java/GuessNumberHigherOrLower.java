
public class GuessNumberHigherOrLower {

	public static void main(String[] args) {

	}
	
	/** 
	 * Forward declaration of guess API.
	 * @param  num   your guess
	 * @return 	     -1 if num is higher than the picked number
	 *			      1 if num is lower than the picked number
	 *               otherwise return 0
	 * int guess(int num);
	 */

	public class Solution extends GuessGame {
	    
		public Solution(int number) {
			super(number);
		}

		public int guessNumber(int n) {
	        // time complexity: O(log n)
			// space complexity: O(1)
			
			int left = 1;
	        int right = n;
	        int mid;
	        
	        while (left <= right) {
	        	mid = left + (right - left) / 2;
	        	int guess = guess(mid);
	        	
	        	if (guess == 0)
	        		return mid;
	        	else if (guess == 1)
	        		left = mid + 1;
	        	else
	        		right = mid - 1;
	        }
	        
	        return -1;
	    }
	    
	    
	}

}
