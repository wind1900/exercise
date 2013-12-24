class Solution {
public:
	int romanToInt(string s) {
		int r = 0;
		for (int i = 0; i < s.size(); i++) {
		    if (i > 0 && map(s[i]) > map(s[i-1])) {
		        r += map(s[i]) - 2 * map(s[i-1]);
		    } else {
		        r += map(s[i]);
		    }
		}
		return r;
	}
	
	int map(char c) {
	    switch (c) {
	        case 'I':
	            return 1;
	        case 'V':
	            return 5;
	        case 'X':
	            return 10;
	        case 'L':
	            return 50;
	        case 'C':
	            return 100;
	        case 'D':
	            return 500;
	        case 'M':
	            return 1000;
	    }
	    return 0;
	}
};