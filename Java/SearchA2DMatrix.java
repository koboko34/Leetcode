
public class SearchA2DMatrix {

	public static void main(String[] args) {
		int[][] matrix = new int[1][2];
		matrix[0][0] = 1;
		matrix[0][1] = 3;
		searchMatrix(matrix, 3);
	}
	
	public static boolean searchMatrix(int[][] matrix, int target) {
        // time complexity: O(log m + log n)
		// space complexity: O(1)
		
		int l = 0, r = matrix.length - 1;
        int row = (r - l) / 2;
        int n = matrix[0].length;
        
        while (l < r) {        	
        	if (matrix[row][0] < target) {
        		if (matrix[row][n - 1] >= target) {
        			break;
        		}
        		l = row + 1;
        		row = l + (r - l) / 2;
        	}
        	else if (matrix[row][0] > target) {
        		r = row - 1;
        		row = l + (r - l) / 2;
        	}
        	else {
        		return true;
        	}
        }
        
        if (n == 1)
        	return matrix[row][0] == target;
        
        l = 0;
        r = n - 1;
        int mid = (r - l) / 2;
        while (l <= r) {
        	if (matrix[row][mid] < target) {
        		l = mid + 1;
        		mid = l + (r - l) / 2;
        	}
        	else if (matrix[row][mid] > target) {
        		r = mid - 1;
        		mid = l + (r - l) / 2;
        	}
        	else {
        		return true;
        	}
        }
        
		return false;
    }

}
