import java.util.ArrayDeque;
import java.util.Stack;

public class PalindromeLinkedList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static boolean isPalindrome(ListNode head) {
		// time complexity: O(n)
		// space complexity: O(1)
		
		if (head == null || head.next == null)
			return true;
		
		ListNode slow = head;
		ListNode fast = head;
		
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
		
		ListNode prev = null;
		ListNode cur = slow;
		ListNode next;
		
		while (cur != null) {
			next = cur.next;
			cur.next = prev;
			prev = cur;
			cur = next;
		}
		
		ListNode left = head;
		ListNode right = prev;
		while (left != null && right != null) {
			if (left.val != right.val)
				return false;
			
			left = left.next;
			right = right.next;
		}
		
		return true;
	}
	
	public static boolean isPalindromeStackQueue(ListNode head) {
		// time complexity: O(n)
		// space complexity: O(n)
		
		Stack<Integer> stack = new Stack<>();
        ArrayDeque<Integer> queue = new ArrayDeque<>();
		
        while (head != null) {
        	stack.push(head.val);
        	queue.add(head.val);
        	head = head.next;
        }
        
        int halfSize = stack.size() / 2;
        while (stack.size() > halfSize) {
        	if (stack.pop() != queue.pop())
        		return false;
        }
		
		return true;
    }

}
