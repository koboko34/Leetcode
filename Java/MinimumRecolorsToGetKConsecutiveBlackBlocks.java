
public class MinimumRecolorsToGetKConsecutiveBlackBlocks {

	public static void main(String[] args) {
		minimumRecolors("WBBWWBBWBW", 7);
	}

	public static int minimumRecolors(String blocks, int k) {
        // time complexity: O(n)
		// space complexity: O(1)
		
		int ans = Integer.MAX_VALUE;
        
        int l = 0, r = 0;
        int blacksInRange = 0;
        
        while (r < blocks.length()) {
        	if (r - l + 1 > k) {
        		if (blocks.charAt(l) == 'B')
        			blacksInRange--;
        		l++;
        	}
        	
        	if (blocks.charAt(r) == 'B') {
        		blacksInRange++;
        	}
        	
        	if (r - l + 1 == k) {
        		ans = Math.min(ans, k - blacksInRange);
        	}
        	r++;
        }
        
        return ans;
    }
}
