import java.util.ArrayList;
import java.util.HashSet;

public class KeyboardRow {

	public static void main(String[] args) {
		String words[] = { "Hello","Alaska","Dad","Peace" };
		findWords(words);
	}
	
	public static String[] findWords(String[] words) {
        HashSet<Character> topMap = new HashSet<>();
        String charSet = "qwertyuiop";
        for (int i = 0; i < charSet.length(); i++) {
        	topMap.add(charSet.charAt(i));
        	topMap.add(Character.toUpperCase(charSet.charAt(i)));
        }
        
        HashSet<Character> midMap = new HashSet<>();
        charSet = "asdfghjkl";
        for (int i = 0; i < charSet.length(); i++) {
        	midMap.add(charSet.charAt(i));
        	midMap.add(Character.toUpperCase(charSet.charAt(i)));
        }
        
        HashSet<Character> botMap = new HashSet<>();
        charSet = "zxcvbnm";
        for (int i = 0; i < charSet.length(); i++) {
        	botMap.add(charSet.charAt(i));
        	botMap.add(Character.toUpperCase(charSet.charAt(i)));
        }
        
        ArrayList<String> list = new ArrayList<>();
        for (String s : words) {
        	if (hasLetters(s, topMap)) {
        		list.add(s);
        		continue;
        	}
        	if (hasLetters(s, midMap)) {
        		list.add(s);
        		continue;
        	}
        	if (hasLetters(s, botMap)) {
        		list.add(s);
        		continue;
        	}
        }
        
        String[] solution = new String[list.size()];
        for (int i = 0; i < list.size(); i ++)
        	solution[i] = list.get(i);
        
        return solution;
    }
	
	private static boolean hasLetters(String s, HashSet<Character> charSet) {
		for (int i = 0; i < s.length(); i++) {
			if (!charSet.contains(s.charAt(i)))
				return false;
		}
		
		return true;
	}

}
