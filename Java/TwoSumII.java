import java.util.HashSet;

public class TwoSumII {

	public static void main(String[] args) {
		int nums[] = new int[] { 2, 7, 11, 15 };
		twoSum(nums, 9);
	}
	
	public static int[] twoSum(int[] numbers, int target) {
        // time complexity: O(n)
		// space complexity: O(1)
		
		int ans[] = new int[2];
		
        int left = 0;
        int right = numbers.length - 1;
        int sum;
        
        while (true) {
        	sum = numbers[left] + numbers[right];
        	
        	if (sum == target) {
        		ans[0] = left + 1;
        		ans[1] = right + 1;
        		return ans;
        	}
        	else if (sum < target)
        		left++;
        	else
        		right--;
        }
    }
	
	public static int[] twoSumBS(int[] numbers, int target) {
        // time complexity: O(n log n)
		// space complexity: O(1)
		
		int ans[] = new int[2];
        
        HashSet<Integer> checked = new HashSet<>();
        
        int left, right, mid, goal;
        
        for (int i = 0; i < numbers.length - 1; i++) {
        	if (checked.contains(numbers[i]))
        		continue;
        	
        	checked.add(numbers[i]);
        	goal = target - numbers[i];
        	left = i + 1;
        	right = numbers.length - 1;
        	
        	while (left <= right) {
        		mid = left + (right - left) / 2;
        		
        		if (numbers[mid] == goal) {
        			ans[0] = i + 1;
        			ans[1] = mid + 1;
        			return ans;
        		}
        		else if (numbers[mid] < goal)
        			left = mid + 1;
        		else
        			right = mid - 1;
        	}
        }
        return ans;
    }
	
	public static int[] twoSumIter(int[] numbers, int target) {
        // time complexity: O(n^2)
		// space complexity O(1)
		
		int ans[] = new int[2];
        
        for (int i = 0; i < numbers.length - 1; i++) {
        	for (int j = i + 1; j < numbers.length; j++) {
        		int sum = numbers[i] + numbers[j];
        		if (sum == target) {
        			ans[0] = i + 1;
        			ans[1] = j + 1;
        			return ans;
        		}
        		if (sum > target)
        			break;
        	}
        }
        return ans;
    }

}
