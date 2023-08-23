import java.util.HashSet;

public class IntersectionOfTwoLinkedLists {

	public static void main(String[] args) {

	}
	
	public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // time complexity: O(n)
		// space complexity: O(1)
		
		if (headA == null || headB == null)
        	return null;
		
		int lenA = 0;
		int lenB = 0;
		
		ListNode listA = headA;
		ListNode listB = headB;
		
		while (listA != null) {
			lenA++;
			listA = listA.next;
		}
		
		while (listB != null) {
			lenB++;
			listB = listB.next;
		}
		
		listA = headA;
		listB = headB;
		
		int diff = lenA - lenB;
		if (diff > 0) {
			while (diff != 0) {
				listA = listA.next;
				diff--;
			}
		}
		else if (diff < 0) {
			while (diff != 0) {
				listB = listB.next;
				diff++;
			}
		}
		
		while (listA != null) {
			if (listA == listB)
				return listA;
			
			listA = listA.next;
			listB = listB.next;
		}
		
		return null;
	}
	
	public static ListNode getIntersectionNodeHashSet(ListNode headA, ListNode headB) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		if (headA == null || headB == null)
        	return null;
		
		HashSet<ListNode> nodes = new HashSet<>();
        
        ListNode listA = headA;
        ListNode listB = headB;
        
        while (listA != null && listB != null) {
        	if (nodes.contains(listA))
        		return listA;
        	nodes.add(listA);
        	
        	if (nodes.contains(listB))
        		return listB;
        	nodes.add(listB);
        	
        	listA = listA.next;
        	listB = listB.next;
        }
        
        while (listA != null) {
        	if (nodes.contains(listA))
        		return listA;
        	nodes.add(listA);
        	listA = listA.next;
        }
        
        while (listB != null) {
        	if (nodes.contains(listB))
        		return listB;
        	nodes.add(listB);
        	listB = listB.next;
        }
        
        return null;
    }

}
