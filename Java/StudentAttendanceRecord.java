public class StudentAttendanceRecord {

	public static void main(String[] args) {

	}

	public static boolean checkRecord(String s) {
        int absentCount = 0;
        int lateCount = 0;
		
		for (int i = 0; i < s.length(); i++) {
        	switch (s.charAt(i)) {
        		case 'P':
        			lateCount = 0;
        			continue;
        		case 'L':
        			if (lateCount == 2)
        				return false;
        			lateCount++;
        			continue;
        		case 'A':
        			if (absentCount == 1)
        				return false;
        			absentCount++;
        			lateCount = 0;
        			continue;
        	}
        }
		
		return true;
    }
}
