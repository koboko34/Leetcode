
public class ConvertSortedArrayToBinarySearchTree {

	public static void main(String[] args) {

	}
	
	public static TreeNode sortedArrayToBST(int[] nums) {
        // time complexity: O(n)
		// space complexity: O(log n)
		
		return addNode(0, nums.length - 1, nums);
    }
	
	private static TreeNode addNode(int left, int right, int[] nums) {
		if (left > right)
			return null;
		
		int mid = ((right - left) / 2) + left;
		TreeNode node = new TreeNode(
				nums[mid], 
				addNode(left, mid - 1, nums), 
				addNode(mid + 1, right, nums)
				);
		return node;
	}

}
