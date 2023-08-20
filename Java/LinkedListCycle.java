import java.util.HashSet;

public class LinkedListCycle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static boolean hasCycle(ListNode head) {
		// time complexity: O(n)
		// space complexity: O(1)
		
		if (head == null)
			return false;
		
		ListNode slow = head;
		ListNode fast = head;
		
		while (fast.next != null && fast.next.next != null) {
			slow = slow.next;
			fast = fast.next.next;
			
			if (slow == fast)
				return true;
		}
		
		return false;
	}
	
	public static boolean hasCycleHashSet(ListNode head) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		if (head == null)
        	return false;
		
		HashSet<ListNode> map = new HashSet<>();
		map.add(head);
        
        while (head.next != null) {
        	if (map.contains(head.next))
        		return true;
        	
        	head = head.next;
        	map.add(head);
        }
        
        return false;
    }

}
