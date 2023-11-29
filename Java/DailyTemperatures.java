import java.util.Stack;

public class DailyTemperatures {

	public static void main(String[] args) {
		int[] temps = new int[] {73,74,75,71,69,72,76,73};
		dailyTemperatures(temps);
	}
	
	public static int[] dailyTemperatures(int[] temperatures) {
        // time complexity = O(n)
		// space complexity = O(n)
		
		int[] ans = new int[temperatures.length];
        
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < temperatures.length; i++) {
        	while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
        			ans[stack.peek()] = i - stack.peek();
        			stack.pop();
        	}
        	
        	stack.push(i);
        }
        
        return ans;
    }

}
