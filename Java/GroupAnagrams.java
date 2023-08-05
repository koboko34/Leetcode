import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class GroupAnagrams {

	public static void main(String[] args) {
		String words[] = new String[] {"eat","tea","tan","ate","nat","bat"};
		
		groupAnagrams(words);

	}

	public static List<List<String>> groupAnagrams(String[] strs) {
        // time complexity: O(n log n)
		// space complexity O(n)
		
		if (strs.length == 0)
        	return new ArrayList<>();
        
        HashMap<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
        	char[] c = s.toCharArray();
        	Arrays.sort(c);
        	String newStr = String.valueOf(c);
        	if (!map.containsKey(newStr))
        		map.put(newStr, new ArrayList<String>());
        	map.get(newStr).add(s);
        }
        
        return new ArrayList<>(map.values());
    }
	
	public static List<List<String>> groupAnagramsSlow(String[] strs) {
        List<List<String>> anagramList = new ArrayList<>();
        
        for (int i = 0; i < strs.length; i++) {
        	boolean shouldContinue = false;
        	for (List<String> list : anagramList) {
        		if (!list.isEmpty() && isAnagram(strs[i], list.get(0))) {
        			list.add(strs[i]);
        			shouldContinue = true;
        			break;
        		}
        	}
        	if (shouldContinue)
        		continue;
        	
        	ArrayList<String> newList = new ArrayList<>();
        	newList.add(strs[i]);
        	anagramList.add(newList);
        }
        
        return anagramList;
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
}
