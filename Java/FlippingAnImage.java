
public class FlippingAnImage {

	public static void main(String[] args) {
		int[][] image = new int[][] {{1,1,0},{1,0,1},{0,0,0}};
		flipAndInvertImage(image);
	}
	
	public static int[][] flipAndInvertImage(int[][] image) {
        // time complexity: O(n)
		// space complexity: O(1)
		
		int length = image.length;
		
		for (int i = 0; i < length; i++) {
        	for (int j = 0; j < length / 2; j++) {
        		int temp = image[i][j];
        		image[i][j] = image[i][length - 1 - j];
        		image[i][length - 1 - j] = temp;
        	}
        }
		
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				image[i][j] = image[i][j] == 0 ? 1 : 0;
			}
		}
		
		return image;
    }

}
