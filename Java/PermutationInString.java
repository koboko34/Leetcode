import java.util.HashMap;

public class PermutationInString {

	public static void main(String[] args) {
		String s1 = "abc";
		String s2 = "bbbca";
		checkInclusion(s1, s2);
	}
	
	public static boolean checkInclusion(String s1, String s2) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		HashMap<Character, Integer> map1 = new HashMap<>();
        for (int i = 0; i < s1.length(); i++) {
        	if (map1.containsKey(s1.charAt(i))) {
        		map1.put(s1.charAt(i), map1.get(s1.charAt(i)) + 1);
        	}
        	else {
        		map1.put(s1.charAt(i), 1);
        	}
        }
        
        HashMap<Character, Integer> map2 = new HashMap<>();
        int l = 0;
        int r = 0;
        
        while (r < s2.length()) {
        	if (map1.containsKey(s2.charAt(r))) {
        		if (map2.containsKey(s2.charAt(r))) {
            		map2.put(s2.charAt(r), map2.get(s2.charAt(r)) + 1);
            	}
            	else {
            		map2.put(s2.charAt(r), 1);
            	}
        		
        		if (r - l + 1 == s1.length()) {
        			if (map1.equals(map2)) {
        				return true;
        			}
        			else {
        				if (map2.get(s2.charAt(l)) == 1) {
                    		map2.remove(s2.charAt(l));
                    	}
                    	else {
                    		map2.put(s2.charAt(l), map2.get(s2.charAt(l)) - 1);
                    	}
        				l++;
        			}
        		}
        	}
        	else {
        		map2.clear();
        		l = r + 1;
        	}
        	
        	r++;
        }
        
		return map1.equals(map2);
    }
}
