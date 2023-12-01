
public class ContainerWithMostWater {

	public static void main(String[] args) {
		int[] height = new int[] {1,8,6,2,5,4,8,3,7};
		maxArea(height);
	}
	
	public static int maxArea(int[] height) {
        // time complexity: O(n)
		// space complexity: O(1)
		
		int area = 0;
        
        int l = 0;
        int r = height.length - 1;
        while (l < r) {
        	int curArea = (r - l) * Math.min(height[l], height[r]);
        	area = Math.max(area, curArea);
        	
        	if (height[l] <= height[r]) {
        		l++;
        	}
        	else {
        		r--;
        	}
        }
        
        return area;
    }

}
