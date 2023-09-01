
public class ReverseBits {

	public static void main(String[] args) {

	}
	
	public int reverseBits(int n) {
        int ans = 0;
        
        for (int i = 0; i < 32; i++) {
        	int mask = n;
        	mask >>>= i;
        	ans |= mask;
        }
        
        return ans;
    }

}
