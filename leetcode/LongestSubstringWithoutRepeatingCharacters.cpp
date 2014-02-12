class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0, t = 0;
        int i = 0, j = 0;
        bool used[26] = {false};
        while (i < s.length() && j < s.length()) {
            while (j < s.length() && !used[s[j] - 'a']) {
                used[s[j++] - 'a'] = true;
            }
            r = max(r, j - i);
            used[s[i++] - 'a'] = false;
        }
        return r;
    }
};
