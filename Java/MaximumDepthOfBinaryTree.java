
public class MaximumDepthOfBinaryTree {

	public static void main(String[] args) {

	}

	public static int maxDepth(TreeNode root) {
        // time complexity: O(n)
		// space complexity: O(n)
		
		if (root == null)
        	return 0;
        
        return dfs(root);
    }
	
	private static int dfs(TreeNode node) {
		if (node == null)
			return 0;
		
		return Math.max(dfs(node.left), dfs(node.right)) + 1;
	}
	
}
