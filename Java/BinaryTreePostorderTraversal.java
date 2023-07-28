import java.util.ArrayList;
import java.util.List;

public class BinaryTreePostorderTraversal {

	public static void main(String[] args) {

	}
	
	public static List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> solution = new ArrayList<Integer>();

        if (root == null)
            return solution;
                
        if (root.left != null) {
        	List<Integer> nodes = postorderTraversal(root.left);
        	for (Integer i : nodes) {
        		solution.add(i);
        	}
        }
        if (root.right != null) {
        	List<Integer> nodes = postorderTraversal(root.right);
        	for (Integer i : nodes) {
        		solution.add(i);
        	}
        }
        solution.add(root.val);
        
        return solution;        	
    }

}
