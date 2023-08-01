import java.util.Stack;

public class ReverseInteger {

	public static void main(String[] args) {
		reverse(1534236469);
	}
	
	public static int reverse(int x) {
        int solution = 0;
        boolean negative = false;
        if (x < 0) {
        	negative = true;
        	x *= -1;
        }
        
        Stack<Integer> stack = new Stack<>();
        
        while (x > 0) {
        	stack.push(x % 10);
        	x /= 10;
        }
        
        int i = 0;
        while (!stack.empty()) {
        	try {
        		solution = Math.addExact(solution, (int)(stack.pop() * Math.pow(10, i)));
        		i++;
        	} catch (ArithmeticException e) {
        		return 0;
        	}
        }
        
        if (negative)
        	solution *= -1;
        
        return solution;
    }

}
