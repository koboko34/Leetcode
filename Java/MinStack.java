import java.util.PriorityQueue;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

public class MinStack {

    public static void main (String[] args) {
    	MinStack s = new MinStack();
    	s.push(2147483646);
    	s.push(2147483646);
    	s.push(2147483647);
    	System.out.println(s.top());
    	s.pop();
    	s.getMin();
    	s.pop();
    	s.push(2147483647);
    	System.out.println(s.top());
    	System.out.println(s.getMin());
    	s.push(-2147483648);
    	System.out.println(s.top());
    	System.out.println(s.getMin());
    	s.pop();
    	System.out.println(s.getMin());
    	
    }
	
	DoubleListNode tail = null;
    DoubleListNode head = null;
	
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    
	public MinStack() {
        
    }
    
    public void push(int val) {
        DoubleListNode node = new DoubleListNode(val, null, tail);
        if (tail != null)
        	tail.next = node;
        
        tail = node;
        if (head == null)
        	head = node;
        
        minHeap.add(node.val);
    }
    
    public void pop() {
    	minHeap.remove(tail.val);
    	
    	tail = tail.prev;
    	if (tail != null)
    		tail.next = null;
    }
    
    public int top() {
        return tail.val;
    }
    
    public int getMin() {
        return minHeap.peek();
    }
}

