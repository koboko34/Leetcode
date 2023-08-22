	
	/** 
	 * Forward declaration of guess API.
	 * @param  num   your guess
	 * @return 	     -1 if num is higher than the picked number
	 *			      1 if num is lower than the picked number
	 *               otherwise return 0
	 * int guess(int num);
	 */

public class GuessGame {

	int number;
	
	public GuessGame(int number) {
		this.number = number;
	}
	
	protected int guess(int num) {
		if (num > number)
			return -1;
		if (num < number)
			return 1;
		return 0;
	}
}
