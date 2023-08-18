
public class CanPlaceFlowers {

	public static void main(String[] args) {

	}
	
	public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        if (n == 0)
        	return true;
		
		if (flowerbed.length == 1) {
        	if (flowerbed[0] == 0)
        		return true;
        	return false;
        }
		
		if (flowerbed[0] == 0 && flowerbed[1] == 0) {
			flowerbed[0] = 1;
			if (n == 1)
				return true;
			if (flowerbed.length == 2)
				return false;
			n--;
		}
		
		for (int i = 1; i < flowerbed.length - 1; i++) {
        	if (flowerbed[i] == 1)
        		continue;
        	
        	if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
        		flowerbed[i] = 1;
        		if (n == 1)
        			return true;
        		n--;
        	}
        }
		
		if (flowerbed[flowerbed.length - 1] == 0 && flowerbed[flowerbed.length - 2] == 0
				&& n == 1)
			return true;
		
		return false;
    }

}
