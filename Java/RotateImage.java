
public class RotateImage {

	public static void main(String[] args) {
		int matrix[][] = new int[][] {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		
		rotate(matrix);
	}

	public static void rotate(int[][] matrix) {
        int n = matrix.length;
        
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bot = n - 1;
        
        while (left < right) {
        	for (int i = 0; left + i < right; i++) {
        		int temp = matrix[top][left + i];
        		matrix[top][left + i] = matrix[bot - i][left];
        		matrix[bot - i][left] = matrix[bot][right - i];
        		matrix[bot][right - i] = matrix[top + i][right];
        		matrix[top + i][right] = temp;        		
        	}
        	
        	left++;
        	right--;
        	top++;
        	bot--;
        }
    }
}
