import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.LinkedList;

public class IslandPerimeter {

	public static void main(String[] args) {
		int grid[][] = new int[][] {{1, 1}, {0, 0}};
		islandPerimeter(grid);
	}

	public static int islandPerimeter(int[][] grid) {
        // time complexity: O(n^2)
		// space complexity: O(n)
		
		int perimeter = 0;
        
        ArrayDeque<Pair> queue = new ArrayDeque<>();
        HashMap<Integer, LinkedList<Integer>> visited = new HashMap<>();
        
        for (int i = 0; i < grid.length; i++) {
        	for (int j = 0; j < grid[i].length; j++) {
        		if (grid[i][j] == 1) {
        			Pair p = new Pair(i, j);
        			queue.add(p);
        			LinkedList<Integer> list = new LinkedList<>();
        			list.add(j);
        			visited.put(i, list);
        			break;
        		}
        	}
        	if (!queue.isEmpty())
        		break;
        }
        
        while (!queue.isEmpty()) {
        	Pair p = queue.pop();
        	
        	int walls = 0;
        	
        	// up
        	if (p.first > 0 && grid[p.first - 1][p.second] == 1) {
        		Pair p2 = new Pair(p.first - 1, p.second);
        		checkWall(p2, visited, queue);
        	}
        	else
        		walls++;
        	
        	// down
        	if (p.first < grid.length - 1 && grid[p.first + 1][p.second] == 1) {
        		Pair p2 = new Pair(p.first + 1, p.second);
        		checkWall(p2, visited, queue);
        	}
        	else
        		walls++;
        	
        	// left
        	if (p.second > 0 && grid[p.first][p.second - 1] == 1) {
        		Pair p2 = new Pair(p.first, p.second - 1);
        		checkWall(p2, visited, queue);
        	}
        	else
        		walls++;
        	
        	// right
        	if (p.second < grid[p.first].length - 1 && grid[p.first][p.second + 1] == 1) {
        		Pair p2 = new Pair(p.first, p.second + 1);
        		checkWall(p2, visited, queue);
        	}
        	else
        		walls++;
        		
        	perimeter += walls;
        }
        
        return perimeter;
    }
	
	private static void checkWall(Pair p2, HashMap<Integer, LinkedList<Integer>> visited,
			ArrayDeque<Pair> queue) {
		if (visited.containsKey(p2.first)) {
			if (!visited.get(p2.first).contains(p2.second)) {
    			queue.add(p2);
    			visited.get(p2.first).add(p2.second);
			}
		}
		else {
			LinkedList<Integer> list = new LinkedList<>();
			list.add(p2.second);
			visited.put(p2.first, list);
			queue.add(p2);
		}
	}
}
