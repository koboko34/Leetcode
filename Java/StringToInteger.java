import java.util.ArrayDeque;
import java.util.Deque;

public class StringToInteger {

	public static void main(String[] args) {
		powExact(2, 3);
		powExact(3, 3);
		powExact(4, 4);
		
		myAtoi("-6147483648");
	}
	
	public static int myAtoi(String s) {
		int asciiCharToInt = 48;
		int solution = 0;
        boolean started = false;
        boolean negative = false;
        boolean leadingZero = true;
        Deque<Integer> queue = new ArrayDeque<>();
        
        for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ') {
				if (started)
					break;
				continue;
			}
			if (s.charAt(i) == '-') {
				if (started)
					break;
				negative = true;
				started = true;
				continue;
			}
			if (s.charAt(i) == '+') {
				if (started)
					break;
				started = true;
				continue;
			}
			
			if (Character.isAlphabetic(s.charAt(i))) {
				break;
			}
			
			if (leadingZero && s.charAt(i) == '0') {
				started = true;
				continue;
			}
			
			if (Character.isDigit(s.charAt(i))) {
				queue.add(s.charAt(i) - asciiCharToInt);
				started = true;
				leadingZero = false;
				continue;
			}
			
			break;
        }
        
        while (!queue.isEmpty()) {
        	int exp;
        	
        	try {
        	exp = powExact(10, queue.size() - 1);
        	}
        	catch (ArithmeticException e) {
        		if (negative)
        			return -(int)Math.pow(2, 31) - 1;
        		return (int)Math.pow(2, 31) - 1;
        	}
        	
        	int toAdd = 0;
        	try {
        		toAdd = Math.multiplyExact(queue.pop(), exp);
        	}
        	catch (ArithmeticException e) {
        		if (negative)
        			return -(int)Math.pow(2, 31) - 1;
        		return (int)Math.pow(2, 31);
        	}
        	
        	try {
        		solution = Math.addExact(solution, toAdd);
        	}
        	catch (ArithmeticException e) {
        		if (negative)
        			return -(int)Math.pow(2, 31) - 1;
        		return (int)Math.pow(2, 31);
        	}
        }
        
        return solution * (negative ? -1 : 1);
    }
	
	private static int powExact(int num, int exp) {
		if (exp < 0)
			throw new ArithmeticException();
		
		if (exp == 0)
			return 1;
		
		if (exp == 1)
			return num;
		
		int ans = num;
		while (exp > 1) {
			try {
			ans = Math.multiplyExact(ans, num);
			exp--;
			}
			catch (ArithmeticException e) {
				throw e;
			}
		}
		
		return ans;
	}

}
