class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int i = 0, j;
        int r = 0;
        while (i < height.size()) {
            if (s.empty() || height[s.top()] <= height[i]) {
                s.push(i);
                i++;
            }
            else {
                j = s.top();
                s.pop();
                if (s.empty()) {
                    r = max(r, i * height[j]);
                } else {
                    r = max(r, (i - s.top() - 1) * height[j]);
                }
            }
        }
        if (!s.empty()) {
            i = s.top();
            while (!s.empty()) {
                j = s.top();
                s.pop();
                if (s.empty()) {
                    r = max(r, (i + 1) * height[j]);
                } else {
                    r = max(r, (i - s.top()) * height[j]);
                }
            }
        }
        return r;
    }
};
