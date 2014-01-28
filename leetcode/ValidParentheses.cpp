class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (char c : s) {
            switch(c) {
                case ')':
                    if (!t.empty() && t.top() == '(') {
                        t.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!t.empty() && t.top() == '[') {
                        t.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!t.empty() && t.top() == '{') {
                        t.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    t.push(c);
                    break;
            }
        }
        return t.empty();
    }
};
