public class ValidPalindrome {

	public static void main(String[] args) {
		System.out.println(isPalindrome("rotator"));
	}
	
	public static boolean isPalindrome(String s) {		
		if (s.isEmpty())
			return true;
		
		s = s.toLowerCase();
		int head = 0;
		int tail = s.length() - 1;
		
		while (head < tail) {
			if (!Character.isLetterOrDigit(s.charAt(head))) {
				head++;
				continue;
			}
			else if (!Character.isLetterOrDigit(s.charAt(tail))) {
				tail--;
				continue;
			}
			else if (s.charAt(head) != s.charAt(tail)) {
				return false;
			}
			head++;
			tail--;
		}
		return true;
	}

}
