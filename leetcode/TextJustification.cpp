class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> r;
        int l = 0, i = 0, s = words.size();
        while (i < s) {
            vector<string> t;
            t.push_back(words[i]);
            l = words[i++].length();
            while (i < s && l + 1 + words[i].length() <= L) {
                t.push_back(words[i]);
                l += 1 + words[i++].length();
            }
            r.push_back(justify(t, L, i == s));
        }
        return r;
    }
    
    string justify(vector<string> &t, int L, bool last) {
        char *b = new char[L + 1];
        b[L] = 0;
        int bs = L, i = 0, c = t.size(), a, r;
        for (string s : t) {
            bs -= s.length();
        }
        if (last) {
            for (string s : t) {
                s.copy(b + i, s.length());
                i += s.length();
                if (i < L)
                    b[i++] = ' ';
            }
            if (L - i)
                memset(b + i, ' ', sizeof(char) * (L - i));
            return string(b);
        }
        if (c > 1) c--;
        a = bs / c;
        r = bs % c;
        for (string s : t) {
            s.copy(b + i, s.length());
            i += s.length();
            if (c) {
                memset(b + i, ' ', sizeof(char) * a);
                i += a;
                c--;
                if (r) {
                    r--;
                    b[i++] = ' ';
                }
            }
        }
        return string(b);
    }
    
};
