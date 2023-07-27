public class MergeSortedArray {

	public static void main(String[] args) {
		int[] first = {0};
		int[] second = {1};
		
		merge(first, 0, second, 1);

	}
	
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
    	int cur = m + n - 1;
    	m--;
    	n--;
    	
    	while (cur >= 0) {
    		if (n < 0 || m >= 0 && nums1[m] > nums2[n]) {
    			nums1[cur] = nums1[m];
    			m--;
    		} else {
    			nums1[cur] = nums2[n];
    			n--;
    		}
			cur--;
    	}
    }

}
