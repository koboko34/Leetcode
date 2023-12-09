public class ConvertBinaryNumberInLinkedListToInteger {

	public static void main(String[] args) {
		
	}

	public static int getDecimalValue(ListNode head) {
		int decimal = 0;
		
		while (head != null) {
			decimal = decimal * 2 + head.val;
			head = head.next;
		}
		
		return decimal;
    }
}
