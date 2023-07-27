import java.util.Arrays;

public class ClimbingStairs {

	public static void main(String[] args) {
		System.out.println(climbStairs(4));
	}
	
	public static int climbStairs(int n) {
		if (n == 1)
			return 1;
		
		if (n == 2)
			return 2;
		
		int[] memo = new int[n];
		Arrays.fill(memo, -1);
		memo[n - 1] = 1;
		memo[n - 2] = 1;
		
		int i = 3;
		do {
			memo[n - i] = memo[n - i + 1] + memo[n - i + 2];
			i++;
		} while (memo[0] == -1);
		
		return memo[0] + memo[1];
	}

}
