class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        unordered_map<string, int> d;
        int i, j, l = start.length();
        char c;
        char *buf = new char[l + 1];
        buf[l] = 0;
        string s1, s2;
        q.push(start);
        d[start] = 1;
        while (!q.empty() && d.count(end) == 0) {
            s1 = q.front();
            s1.copy(buf, l, 0);
            q.pop();
            for (i = 0; i < l; i++) {
                c = buf[i];
                for (j = 0; j < 26; j++) {
                    if (c == 'a' + j) continue;
                    buf[i] = 'a' + j;
                    s2 = string(buf);
                    if (dict.count(s2) > 0 && d.count(s2) == 0) {
                        q.push(s2);
                        d[s2] = d[s1] + 1;
                    }
                }
                buf[i] = c;
            }
        }
        if (d.count(end) == 0) return 0;
        return d[end];
    }
    
};
