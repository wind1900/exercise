class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> l(s.length(), 0);
        stack<int> st;
        int r = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (!st.empty()) {
                l[i] = i - st.top() + 1;
                if (st.top() > 1) l[i] += l[st.top() - 1];
                r = max(l[i], r);
                st.pop();
            }
        }
        return r;
    }
};
