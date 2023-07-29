import java.util.HashMap;

public class LongestSubstringWithoutRepeatingCharacters {
	
	public static void main(String[] args) {
		System.out.println(lengthOfLongestSubstring("abcabcbb"));
	}
	
	public static int lengthOfLongestSubstring(String s) {
		if (s.isEmpty())
			return 0;
        
		HashMap<Character, Boolean> map = new HashMap<>();
		
		int left = 0;
		int right = 0;
		int max = 0;
		int len = 0;
		
		while (right < s.length()) {
			char cRight = s.charAt(right);
			if (map.get(cRight) == null || map.get(cRight) == false) {
				map.put(cRight, true);
				right++;
				continue;
			}
			
			len = right - left;
			if (len > max)
				max = len;
			
			char cLeft = s.charAt(left);
			while (cLeft != cRight) {
				map.remove(cLeft);
				left++;
				cLeft = s.charAt(left);
			}
			
			left++;
			right++;
		}
		
		len = right - left;
		if (len > max)
			return len;
        
		return max;
	}
}
