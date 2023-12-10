
public class SubstringsOfSizeThreeWithDistinctCharacters {

	public static void main(String[] args) {
		
	}
	
	public static int countGoodSubstrings(String s) {
        if (s.length() < 3)
        	return 0;
		
		int ans = 0;
        
        for (int l = 0; l + 2 < s.length(); l++) {
        	if (s.charAt(l) != s.charAt(l + 1) && s.charAt(l) != s.charAt(l + 2) &&
        		s.charAt(l + 1) != s.charAt(l + 2)) {
        		ans++;
        	}
        }
        
        return ans;
    }

}
