import java.util.ArrayList;
import java.util.List;

public class BinaryTreeInorderTraversal {

	public static void main(String[] args) {
		
	}
	
	public static List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> solution = new ArrayList<Integer>();

        if (root == null)
            return solution;
                
        if (root.left != null) {
        	List<Integer> nodes = inorderTraversal(root.left);
        	for (Integer i : nodes) {
        		solution.add(i);
        	}
        }
        solution.add(root.val);
        if (root.right != null) {
        	List<Integer> nodes = inorderTraversal(root.right);
        	for (Integer i : nodes) {
        		solution.add(i);
        	}
        }
        
        return solution;        	
    }

}
