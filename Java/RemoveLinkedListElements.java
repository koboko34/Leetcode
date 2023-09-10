
public class RemoveLinkedListElements {

	public static void main(String[] args) {
		ListNode nine = new ListNode(9);
		ListNode eight = new ListNode(3, nine);
		ListNode seven = new ListNode(7, eight);
		ListNode six = new ListNode(3, seven);
		ListNode five = new ListNode(5, six);
		ListNode four = new ListNode(4, five);
		ListNode three = new ListNode(3, four);
		ListNode two = new ListNode(1, three);
		ListNode one = new ListNode(1, two);
		
		removeElements(one, 3);
	}
	
	public static ListNode removeElements(ListNode head, int val) {
		// time complexity: O(n)
		// space complexity: O(1)
		
		if (head == null)
			return null;
		
		while (head.next != null && head.val == val)
			head = head.next;
		
		if (head.val == val)
			return null;
		
		ListNode prev = head;
		ListNode cur = head.next;
		while (cur != null) {
			if (cur.val == val) {
				cur = cur.next;
				prev.next = cur;
				continue;
			}
			prev = cur;
			cur = cur.next;
		}
		
		return head;
	}

}
