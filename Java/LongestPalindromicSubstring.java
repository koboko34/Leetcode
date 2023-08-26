
public class LongestPalindromicSubstring {

	public static void main(String[] args) {
		longestPalindrome("babad");
	}
	
	public static String longestPalindrome(String s) {
        // time complexity: O(n^2)
		// space complexity: O(1)
		
		String ans = "";
        int len = 0;
        
        for (int i = 0; i < s.length(); i++) {
        	// check odd
        	int l = i;
        	int r = i;
        	while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
        		if (r - l + 1 > len) {
        			len = r - l + 1;
        			ans = s.substring(l, r + 1);
        		}
        		l--;
        		r++;
        	}
        	
        	// check even
        	l = i;
        	r = i + 1;
        	while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
        		if (r - l + 1 > len) {
        			len = r - l + 1;
        			ans = s.substring(l, r + 1);
        		}
        		l--;
        		r++;
        	}	
        }
        
        return ans;
    }

}
