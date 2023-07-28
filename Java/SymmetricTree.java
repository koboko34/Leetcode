import java.util.Stack;

public class SymmetricTree {

	public static void main(String[] args) {
		// Input: root = [1,2,2,2,null,2]
		
		TreeNode five = new TreeNode(2);
		TreeNode four = new TreeNode(2);
		TreeNode three = new TreeNode(2, five, null);
		TreeNode two = new TreeNode(2, four, null);
		TreeNode one = new TreeNode(1, two, three);
		
		System.out.println(isSymmetric(one));
	}
	
	public static boolean isSymmetric(TreeNode root) {
		if (root == null)
			return true;
		
		Stack<TreeNode> stack = new Stack<>();
		stack.push(root.left);
		stack.push(root.right);
		
		while (!stack.isEmpty()) {
			TreeNode first = stack.pop();
			TreeNode second = stack.pop();
			
			if (first == null && second == null)
				continue;
			if (first == null || second == null || first.val != second.val)
				return false;
			stack.push(first.left);
			stack.push(second.right);
			stack.push(first.right);
			stack.push(second.left);
		}
		
		return true;
    }

}
