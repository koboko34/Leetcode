import java.util.ArrayList;
import java.util.HashMap;

class TimePair {
	int timestamp;
	String value;
	TimePair(int timestamp, String value) { this.timestamp = timestamp; this.value = value; }
}

public class TimeMap {

	public static void main(String[] args) {
		TimeMap timeMap = new TimeMap();
		timeMap.set("foo", "bar", 1);
		timeMap.get("foo" , 1);
		timeMap.get("foo", 3);
		timeMap.set("foo", "bar2", 4);
		timeMap.get("foo", 4);
		timeMap.get("foo", 5);
	}
	
	// time complexity: O(log n)
	// time complexity: O(n)
	
	HashMap<String, ArrayList<TimePair>> map = new HashMap<>();
	
    public TimeMap() {
        
    }
    
    public void set(String key, String value, int timestamp) {
        if (!map.containsKey(key))
        	map.put(key, new ArrayList<TimePair>());

    	map.get(key).add(new TimePair(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        if (!map.containsKey(key))
        	return "";
        
        ArrayList<TimePair> list = map.get(key);
    	        
        int l = 0;
        int r = list.size() - 1;
        int mid;
        int closest = -1;
        
        if (r == 0)
        	return list.get(0).timestamp <= timestamp ? list.get(0).value : "";
        
        while (l <= r) {
        	mid = (l + r) / 2;
        	
        	if (list.get(mid).timestamp > timestamp) {
        		r = mid - 1;
        	}
        	else {
        		if (closest == -1 || (timestamp - list.get(closest).timestamp) > (timestamp - list.get(mid).timestamp)) {
        			closest = mid;
        			l = mid + 1;
        		}
        		else if (mid + 1 < list.size() && list.get(mid + 1).timestamp > timestamp)
        			break;
        	}
        }
        
    	return closest == -1 ? "" : list.get(closest).value;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */

