import java.util.ArrayList;
import java.util.List;

public class GenerateParentheses {

	public static void main(String[] args) {
		generateParenthesis(3);
	}
	
	public static List<String> generateParenthesis(int n) {	
		List<String> ans = new ArrayList<>();
        backtrack(ans, 0, 0, "", n);
        return ans;
    }
	
	public static void backtrack(List<String> ans, int left, int right, String s, int n) {
		if (s.length() == n * 2) {
			ans.add(s);
			return;
		}
		
		if (left < n) {
			backtrack(ans, left + 1, right, s + "(", n);
		}
		
		if (right < left) {
			backtrack(ans, left, right + 1, s + ")", n);
		}
	}

}
