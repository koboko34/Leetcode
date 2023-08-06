
public class DoubleListNode {
    int val;
    DoubleListNode next;
    DoubleListNode prev;
    DoubleListNode() {}
    DoubleListNode(int val) { this.val = val; }
    DoubleListNode(int val, DoubleListNode next) { this.val = val; this.next = next; }
    DoubleListNode(int val, DoubleListNode next, DoubleListNode prev) { this.val = val; this.next = next; this.prev = prev; }
    DoubleListNode(int val, Object o, DoubleListNode prev) { this.val = val; this.next = null; this.prev = prev; }
}
