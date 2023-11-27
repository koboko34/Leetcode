import java.util.Stack;

public class EvaluateReversePolishNotation {

	public static void main(String[] args) {
		
	}
	
	public static int evalRPN(String[] tokens) {
		// time complexity: O(n)
		// space complexity: O(n)
		
		Stack<Integer> stack = new Stack<>();
		int b;
		int a;
		
		for (int i = 0; i < tokens.length; i++) {			
			switch (tokens[i]) {
			case "+":
				stack.push(stack.pop() + stack.pop());
				break;
			case "-":
				b = stack.pop();
				a = stack.pop();
				stack.push(a - b);
				break;
			case "*":
				stack.push(stack.pop() * stack.pop());
				break;
			case "/":
				b = stack.pop();
				a = stack.pop();
				stack.push(a / b);
				break;
			default:
				stack.push(Integer.valueOf(tokens[i]));
				continue;
			}
		}
		
		return stack.peek();
    }

}
