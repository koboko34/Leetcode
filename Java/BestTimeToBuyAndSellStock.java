
public class BestTimeToBuyAndSellStock {

	public static void main(String[] args) {
		int prices[] = new int[] { 1, 2 };
		maxProfit(prices);
	}
	
	public static int maxProfit(int[] prices) {
		// time complexity: O(n)
		// space complexity: O(1)
		
		if (prices.length == 1)
			return 0;
		
		int profit = 0;
		int maxProfit = 0;
		
		int left = 0;
		int right = 1;
		
		while (right < prices.length) {
			profit = prices[right] - prices[left];
			if (profit < 0) {
				left = right;
				right++;
				continue;
			}
			
			if (profit > maxProfit) {
				maxProfit = profit;
			}
			right++;
		}
		
		return maxProfit;
    }
	

}
