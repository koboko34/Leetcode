import java.util.HashSet;

public class ValidSudoku {

	public static void main(String[] args) {
		
	}
	
	public static boolean isValidSudoku(char[][] board) {
        HashSet<Character> set = new HashSet<>();
        
		// check row
		for (int i = 0; i < 9; i++) {
			set.clear();
			
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
				
				if (set.contains(board[i][j]))
					return false;
				
				set.add(board[i][j]);
			}
		}
        
		// check column
		for (int i = 0; i < 9; i++) {
			set.clear();
			
			for (int j = 0; j < 9; j++) {
				if (board[j][i] == '.')
					continue;
				
				if (set.contains(board[j][i]))
					return false;
				
				set.add(board[j][i]);
			}
		}
		
		// check box
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!boxValid(board, i, j))
					return false;
			}
		}
		
		return true;
    }
	
	private static boolean boxValid(char[][] board, int x, int y) {
        HashSet<Character> set = new HashSet<>();
		for (int i = 0 + (3 * y); i < 3 + (3 * y); i++) {
			for (int j = 0 + (3 * x); j < 3 + (3 * x); j++) {
				if (board[i][j] == '.')
					continue;
				
				if (set.contains(board[i][j]))
					return false;
				
				set.add(board[i][j]);
			}
		}
		
		return true;
	}

}
