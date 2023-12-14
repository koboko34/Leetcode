import java.util.LinkedList;
import java.util.Queue;

public class InvertBinaryTree {

	public static void main(String[] args) {

	}
	
	public static TreeNode invertTree(TreeNode root) {
		// time complexity: O(n)
		// space complexity: O(n)
		if (root == null)
			return root;
		
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		queue.add(root);
		
		while (!queue.isEmpty()) {
			TreeNode node = queue.remove();
			
			if (node.left != null)
				queue.add(node.left);
			
			if (node.right != null)
				queue.add(node.right);
			
			invert(node);
		}
		
		return root;
	}
	
	public static void invert(TreeNode node) {
		if (node == null)
        	return;
		
        TreeNode temp = node.left;
        node.left = node.right;
        node.right = temp;
	}
	
	public static TreeNode invertTreeRecursive(TreeNode root) {
		// time complexity: O(n)
		// space complexity: O(n)
		if (root == null)
        	return root;
		
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        
        invertTreeRecursive(root.left);
        invertTreeRecursive(root.right);
        
		return root;
    }

}
