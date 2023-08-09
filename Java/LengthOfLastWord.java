
public class LengthOfLastWord {

	public static void main(String[] args) {
		lengthOfLastWord("Hello world");

	}
	
	public static int lengthOfLastWord(String s) {
        String[] words = s.split(" ");
        return words[words.length - 1].length();
    }

}
