class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        int l = start.length(), i, j;
        char *b = new char[l + 1];
        char c;
        string s, ss;
        unordered_map<string, int> d;
        unordered_map<string, vector<string>> n;
        vector<vector<string>> r;
        queue<string> q;
        d[start] = 0;
        q.push(start);
        b[l] = 0;
        while (!q.empty()) {
            s = q.front();
            if (d.count(end) > 0 && d[s] >= d[end]) break;
            q.pop();
            s.copy(b, l);
            for (i = 0; i < l; i++) {
                c = b[i];
                for (j = 'a'; j <= 'z'; j++) {
                    if (c == j) continue;
                    b[i] = j;
                    ss = string(b);
                    if (dict.count(ss) > 0) {
                        if (d.count(ss) == 0) {
                            n[ss].push_back(s);
                            d[ss] = d[s] + 1;
                            q.push(ss);
                        } else if (d[ss] == d[s] + 1) {
                            n[ss].push_back(s);
                        }
                    }
                }
                b[i] = c;
            }
        }
        if (n.count(end) == 0) return r;
        r.push_back(vector<string>(1, end));
        i = d[end];
        while (i--) {
            vector<vector<string>> t;
            for (vector<string> v : r) {
                v.insert(v.begin(), "");
                for (string s : n[v[1]]) {
                    v[0] = s;
                    t.push_back(v);
                }
            }
            r = t;
        }
        return r;
    }
};
