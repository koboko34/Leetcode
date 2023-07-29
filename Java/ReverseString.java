
public class ReverseString {

	public static void main(String[] args) {
		char[] s = { 'h', 'e', 'l', 'l', 'o' };
		reverseString(s);
	}
	
	public static void reverseString(char[] s) {        
        if (s.length < 2)
            return;
        
        for (int i = 0; i < (s.length / 2); i++) {
        	char temp = s[i];
        	
        	s[i] = s[s.length - i - 1];
        	s[s.length - i - 1] = temp;
        }
    }

}
