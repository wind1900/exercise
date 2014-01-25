class Solution {
public:
    int maxArea(vector<int> &height) {
        int s = 0, e = height.size() - 1;
        int r = 0;
        while (s < e) {
            r = max(r, min(height[s], height[e]) * (e - s));
            if (height[s] > height[e]) {
                e--;
            } else {
                s++;
            }
        }
        return r;
    }
};
