import java.util.Arrays;

public class KokoEatingBananas {

	public static void main(String[] args) {
		int[] piles = new int[] {30,11,23,4,20};
		minEatingSpeed(piles, 5);
	}
	
	public static int minEatingSpeed(int[] piles, int h) {
		int l = 1;
		int r = Arrays.stream(piles).max().getAsInt();
		int mid;
		
		while (l < r) {
			mid = (l + r) / 2;
			
			if (canEatInTime(piles, mid, h)) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		
		return l;
    }
	
	public static boolean canEatInTime(int piles[], int mid, int h) {
		int hours = 0;
		for (int p : piles) {
			int div = p / mid;
			hours += div;
			if (p % mid != 0) {
				hours++;
			}
		}
		return hours <= h;
	}
}
