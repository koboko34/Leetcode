import java.util.HashSet;

public class RemoveDuplicatesFromSortedList {

	public static void main(String[] args) {
		ListNode five = new ListNode(3);
		ListNode four = new ListNode(3, five);
		ListNode three = new ListNode(2, four);
		ListNode two = new ListNode(1, three);
		ListNode one = new ListNode(1, two);
		deleteDuplicates(one);
	}
	
	public static ListNode deleteDuplicates(ListNode head) {
		ListNode cur = head;
		
		while (cur != null) {
			if (cur.next == null)
				break;
			
			if (cur.val == cur.next.val) {
				cur.next = cur.next.next;
				continue;
			}
			
			cur = cur.next;
		}
		
		return head;
	}
	
	public static ListNode deleteDuplicatesHashSet(ListNode head) {		
		if (head == null || head.next == null)
        	return head;
		
        ListNode cur = head;
        ListNode last = head;
        HashSet<Integer> set = new HashSet<>();
        set.add(cur.val);
        cur = cur.next;
        
        while (cur != null) {
        	if (set.contains(cur.val)) {
        		cur = cur.next;
        		continue;
        	}
        	
        	set.add(cur.val);
        	last.next = cur;
        	last = cur;
        	cur = cur.next;
        }
        
        last.next = null;
        
		return head;
    }

}
