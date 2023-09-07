import java.util.Deque;

public class MinimumDepthOfBinaryTree {

	public static void main(String[] args) {

	}

	public static int minDepth(TreeNode root) {
		// time complexity: O(?)
		// space complexity: O(?)
		
		if (root == null)
			return 0;
		
		int depth = 1;
		
		Deque<TreeNode> queue = new Deque<>();
		queue.add(root);
		Deque<Integer> level = new Deque<>();
		level.add(1);
		
		while (!queue.isEmpty()) {
			TreeNode node = queue.pop();
			if (node.left == null && node.right == null)
				return level.poll();
			
			if (node.left != null) {
				queue.add(node.left);
				level.add(level.peek() + 1);
			}
			
			if (node.right != null) {
				queue.add(node.right);
				level.add(level.peek() + 1);
			}
			
			level.pop();
		}
	}
}
