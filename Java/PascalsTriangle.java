import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class PascalsTriangle {

	public static void main(String[] args) {
		generate(5);
	}
	
	public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pt = new ArrayList<>();
        pt.add(Arrays.asList(1));
        
        if (numRows == 1)
        	return pt;
        
        pt.add(Arrays.asList(1, 1));
        if (numRows == 2)
        	return pt;
        
        
        for (int row = 2; row <= numRows - 1; row++) {
        	ArrayList<Integer> arr = new ArrayList<>();
        	
        	arr.add(1);
        	for (int i = 0; i < pt.get(row - 1).size() - 1; i++) {
        		int left = pt.get(row - 1).get(i);
        		int right = pt.get(row - 1).get(i + 1);
        		int total = left + right;
        		
        		arr.add(total);
        	}
        	arr.add(1);
        	
        	pt.add(arr);
        }
        
        return pt;
    }
	

}
