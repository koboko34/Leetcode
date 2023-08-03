import java.util.HashMap;

public class ValidAnagram {

	public static void main(String[] args) {
		isAnagram("anagram", "nagaram");

	}
	
	public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
        	return false;
        
        int arr[] = new int[26];
        
        for (int i = 0; i < s.length(); i++) {
        	arr[s.charAt(i) - 'a']++;
        	arr[t.charAt(i) - 'a']--;
        }
        
        for (int i : arr) {
        	if (i != 0)
        		return false;
        }
        return true;
    }
	
	public static boolean isAnagramHashmap(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
        	map.put(s.charAt(i), map.get(s.charAt(i)) == null ? 1 : map.get(s.charAt(i))+ 1);
        }
        
        for (int i = 0; i < t.length(); i++) {
        	char c = t.charAt(i);
        	
        	if (map.containsKey(c)) {
        		map.replace(c, map.get(c) - 1);
	        	if (map.get(c) <= 0)
	        		map.remove(c);
	        	continue;
        	}
        	return false;
        }
        
        return map.isEmpty();
    }

}
