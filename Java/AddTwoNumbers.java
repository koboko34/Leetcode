import java.util.Stack;

public class AddTwoNumbers {

	public static void main(String[] args) {
		ListNode ten1 = new ListNode(1);
		ListNode nine1 = new ListNode(1, ten1);
		ListNode eight1 = new ListNode(1, nine1);
		ListNode seven1 = new ListNode(1, eight1);
		ListNode six1 = new ListNode(1, seven1);
		ListNode five1 = new ListNode(1, six1);
		ListNode four1 = new ListNode(1, five1);
		ListNode three1 = new ListNode(1, four1);
		ListNode two1 = new ListNode(1, three1);
		ListNode one1 = new ListNode(1, two1);
		ListNode l1 = new ListNode(1, one1);
		
		ListNode ten = new ListNode(1);
		ListNode nine = new ListNode(1, ten);
		ListNode eight = new ListNode(1, nine);
		ListNode seven = new ListNode(1, eight);
		ListNode six = new ListNode(1, seven);
		ListNode five = new ListNode(1, six);
		ListNode four = new ListNode(1, five);
		ListNode three = new ListNode(1, four);
		ListNode two = new ListNode(1, three);
		ListNode one = new ListNode(1, two);
		ListNode l2 = new ListNode(1, one);
		
		addTwoNumbers(l1, l2);
	}
	
	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode solution = new ListNode();
		ListNode head = solution;

		boolean overflow = false;
		boolean first = true;
		
		while (l1 != null && l2 != null) {
			int temp = l1.val + l2.val + (overflow ? 1 : 0);
			if (temp > 9) {
				temp -= 10;
				overflow = true;
			}
			else
				overflow = false;
			
			if (!first) {
				solution.next = new ListNode();
				solution = solution.next;
			}
			solution.val = temp;
			l1 = l1.next;
			l2 = l2.next;
			first = false;
		}
		
		if (l1 == null && l2 != null) {
			while (overflow && l2 != null) {
				int temp = l2.val + 1;
				if (temp > 9)
					temp -= 10;
				else
					overflow = false;
				solution.next = new ListNode(temp);
				solution = solution.next;
				l2 = l2.next;
			}
			
			if (l2 != null)
			{
				solution.next = l2;
				return head;
			}
		}
		
		if (l2 == null && l1 != null) {
			while (overflow && l1 != null) {
				int temp = l1.val + 1;
				if (temp > 9)
					temp -= 10;
				else
					overflow = false;
				solution.next = new ListNode(temp);
				solution = solution.next;
				l1 = l1.next;
			}
			
			if (l1 != null)
			{
				solution.next = l1;
				return head;
			}
		}
		
		if (l1 == null && l2 == null) {
			if (overflow) {
				solution.next = new ListNode(1);
			}
		}
		
		return head;
    }
	
	public static ListNode addTwoNumbersStack(ListNode l1, ListNode l2) {
        // neat solution, however can overflow if number is greater than a long
		
		ListNode solution = new ListNode();
        
        Stack<Long> stack = new Stack<>();
        while (l1 != null) {
        	stack.push((long) l1.val);
        	l1 = l1.next;
        }
        long i = (long) Math.pow(10, stack.size() - 1);
        long num1 = 0;
        while (!stack.empty()) {
        	num1 += i * stack.pop();
        	i /= 10;
        }
        
        while (l2 != null) {
        	stack.push((long) l2.val);
        	l2 = l2.next;
        }
        i = (long) Math.pow(10, stack.size() - 1);
        long num2 = 0;
        while (!stack.empty()) {
        	num2 += i * stack.pop();
        	i /= 10;
        }
        
        long sum = num1 + num2;
        
        if (sum == 0) {
        	solution.val = 0;
        	return solution;
        }
        
        ListNode head = solution;
        solution.val = (int) (sum % 10);
        sum /= 10;
        
        while (sum > 0) {
            solution.next = new ListNode((int) (sum % 10));
            solution = solution.next;
            sum /= 10;
        }
        
        return head;
    }
}
