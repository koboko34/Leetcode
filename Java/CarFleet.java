import java.util.Collections;
import java.util.Map;
import java.util.Stack;
import java.util.TreeMap;

public class CarFleet {

	public static void main(String[] args) {
		int target = 12;
		int[] position = new int[] {10,8,0,5,3};
		int[] speed = new int[] {2,4,1,1,3};
		
		carFleet(target, position, speed);
	}
	
	public static int carFleet(int target, int[] position, int[] speed) {
        // time complexity: O(n log n)
		// space complexity: O(n)
		
		int count = 0;
        
		TreeMap<Integer, Integer> sortedMap = new TreeMap<>(Collections.reverseOrder());
		
		for (int i = 0; i < position.length; i++) {
			sortedMap.put(position[i], speed[i]);
		}
        
        Stack<Map.Entry<Integer, Integer>> stack = new Stack<>();
        
        for (Map.Entry<Integer, Integer> entry : sortedMap.entrySet()) {
        	boolean shouldContinue = false;
        	
        	while (!stack.isEmpty()) {
        		if (!joinsFleet(target, stack.peek(), entry)) {
        			stack.pop();
        			continue;
        		}
        			
        			shouldContinue = true;
        			break;
        	}
        	
        	if (shouldContinue)
        		continue;
        	
        	stack.push(entry);
        	count++;
        }
        
        return count;
    }
	
	public static boolean joinsFleet(int target, Map.Entry<Integer, Integer> front, Map.Entry<Integer, Integer> back) {
		float timeFront = (float)(target - front.getKey()) / (float)front.getValue();
		float timeBack = (float)(target - back.getKey()) / (float)back.getValue();
		
		return timeBack <= timeFront;
	}
}
