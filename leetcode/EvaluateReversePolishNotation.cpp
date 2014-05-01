class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int a, b;
        for (auto t : tokens) {
            if ((t[0] >= '0' && t[0] <= '9') || t.size() > 1) {
                s.push(atoi(t.c_str()));
            } else {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                switch(t[0]) {
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(b-a);
                        break;
                    case '*':
                        s.push(b*a);
                        break;
                    case '/':
                        s.push(b/a);
                        break;
                }
            }
        }
        return s.top();
    }
};
