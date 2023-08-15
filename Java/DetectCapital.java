
public class DetectCapital {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static boolean detectCapitalUse(String word) {
        if (word.length() <= 1)
        	return true;
		
        boolean upper = Character.isUpperCase(word.charAt(1));

		if (Character.isLowerCase(word.charAt(0))) {
        	for (int i = 1; i < word.length(); i++) {
            	if (Character.isUpperCase(word.charAt(i)))
            			return false;
            }
        }
		else if (upper) {
        	for (int i = 1; i < word.length(); i++) {
        		if (Character.isLowerCase(word.charAt(i))) {
        			return false;
        		}
            }
        }
        else {
        	for (int i = 1; i < word.length(); i++) {
        		if (Character.isUpperCase(word.charAt(i))) {
        			return false;
        		}
            }	
	    }
        
        return true;
    }

}
