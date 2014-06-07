class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i = 0, j;
        string ss;
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') i++;
            if (i >= path.size()) break;
            for (j = i; j < path.size() && path[j] != '/'; j++);
            ss =path.substr(i, j - i);
            if (ss.compare(".") == 0) {
                
            } else if (ss.compare("..") == 0) {
                if (!s.empty()) s.pop();
            } else {
                s.push(ss);
            }
            i = j;
        }
        if (s.empty()) return "/";
        string r;
        while (!s.empty()) {
            r = "/" + s.top() + r;
            s.pop();
        }
        return r;
    }
};
