import java.util.List;
import java.util.ArrayList;

public class BinaryTreePreorderTraversal {

	public static void main(String[] args) {

	}
	
	public static List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> solution = new ArrayList<Integer>();

        if (root == null)
            return solution;
                
        solution.add(root.val);
        if (root.left != null) {
        	List<Integer> nodes = preorderTraversal(root.left);
        	for (Integer i : nodes) {
        		solution.add(i);
        	}
        }
        if (root.right != null) {
        	List<Integer> nodes = preorderTraversal(root.right);
        	for (Integer i : nodes) {
        		solution.add(i);
        	}
        }
        
        return solution;        	
    }

}
