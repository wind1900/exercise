class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> used;
        int len = 1;
        for (int i : num) used[i] = false;
        for (int i : num) {
            if (used[i]) continue;
            int t = 1;
            for (int j = i - 1; used.find(j) != used.end(); j--) {
                t++;
                used[j] = true;
            }
            for (int j = i + 1; used.find(j) != used.end(); j++) {
                t++;
                used[j] = true;
            }
            len = max(t, len);
        }
        return len;
    }
};
