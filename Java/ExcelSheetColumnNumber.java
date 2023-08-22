
public class ExcelSheetColumnNumber {

	public static void main(String[] args) {
		titleToNumber("ZY");
	}

	public static int titleToNumber(String columnTitle) {
        // time complexity: O(n)
		// space complexity: O(1)
		
		int ans = 0;
		
		for (int i = 0; i < columnTitle.length(); i++) {
        	char c = columnTitle.charAt(columnTitle.length() - i - 1);
        	
        	int val = (c - 'A' + 1) * (int)Math.pow(26, i);
        	ans += val;
        }
		
		return ans;
    }
}
