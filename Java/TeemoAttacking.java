import java.util.HashSet;

public class TeemoAttacking {

	public static void main(String[] args) {
		int timeSeries[] = new int[] {1, 4};
		findPoisonedDuration(timeSeries, 2);
	}
	
	public static int findPoisonedDuration(int[] timeSeries, int duration) {
        if (timeSeries.length == 1)
        	return duration;
		
		int solution = 0;
        
		int i = 0;
		while (i + 1 <= timeSeries.length - 1) {
			if (timeSeries[i + 1] - timeSeries[i] < duration)
				solution += timeSeries[i + 1] - timeSeries[i];
			else
				solution += duration;
			
			i++;
		}
		
		solution += duration;
		return solution;
		
    }
	
	public static int findPoisonedDurationHashSet(int[] timeSeries, int duration) {
        HashSet<Integer> intervals = new HashSet<>();
        
        int right = Integer.MAX_VALUE;
        for (int i = timeSeries.length - 1; i >= 0; i--)
        {
        	for (int j = 0; j < duration && timeSeries[i] + j < right; j++)
        		intervals.add(timeSeries[i] + j);
        	
        	right = timeSeries[i];
        }
        
        return intervals.size();
    }

}
