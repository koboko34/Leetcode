
public class AddDigits {

	public static void main(String[] args) {
		addDigits(38);

	}
	
	public static int addDigits(int num) {
        if (num < 10)
        	return num;
        
        while (num >= 10) {
        	int temp = 0;
        	while (num != 0) {
        		temp += num % 10;
        		num /= 10;
        	}
        	num = temp;
        }
        	
        return num;
    }
}
