import java.util.HashMap;

public class LongestRepeatingCharacterReplacement {

	public static void main(String[] args) {
		
	}
	
	public static int characterReplacement(String s, int k) {
        int ans = 0;
        int l = 0, r = 0;
        int len;
        int maxf = 1;
        
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c = 'A'; c <= 'Z'; c++) {
        	map.put(c, 0);
        }
        
        map.put(s.charAt(0), 1);
        
        while (l <= r) {
        	len = r - l + 1;
        	
        	if (len - maxf <= k) {
        		ans = Math.max(ans, len);
        		r++;
        		if (r >= s.length())
        			break;
        		
    			map.put(s.charAt(r), map.get(s.charAt(r)) + 1);
    			maxf = Math.max(map.get(s.charAt(r)), maxf);
        	}
        	else {
        		map.put(s.charAt(l), map.get(s.charAt(l)) - 1);
        		l++;
        	}
        }
        
        return ans;
    }
}
