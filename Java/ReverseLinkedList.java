
public class ReverseLinkedList {

	public static void main(String[] args) {
		ListNode five = new ListNode(5);
		ListNode four = new ListNode(4, five);
		ListNode three = new ListNode(3, four);
		ListNode two = new ListNode(2, three);
		ListNode one = new ListNode(1, two);
		
		reverseListRecursive(one);
	}
	
	public static ListNode reverseListIterative(ListNode head) {
        if (head == null)
        	return head;
		
        ListNode prev = null;
        ListNode cur = head;
        ListNode next = cur.next;
        cur.next = prev;
                
        while (next != null) {
        	prev = cur;
        	cur = next;
        	next = cur.next;
        	cur.next = prev;
        }
        
        return cur;
    }
	
	public static ListNode reverseListRecursive(ListNode head) {		
		if (head.next == null)
			return head;
		
		ListNode newHead = reverseListRecursive(head.next);
		head.next.next = head;
		head.next = null;
		return newHead;
		
	}
	
}
