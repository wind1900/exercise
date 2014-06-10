class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> r;
        int i = 0, l = L[0].length(), s = S.length();
        unordered_map<string, pair<int, int>> m;
        for (string s : L) {
            if (m.count(s) == 0) {
                m[s] = make_pair(i++, 0);
            }
            m[s].second++;
        }
        for (i = 0; i < l; i++) {
            vector<int> seq = generate(S, m, i, l);
            check(seq, m, r, i, L, l);
        }
        return r;
    }
    
    vector<int> generate(string S, unordered_map<string, pair<int, int>> &m, int i, int l) {
        vector<int> r;
        string s;
        int j = 0;
        while (i + j + l - 1 < S.length()) {
            s = S.substr(i + j, l);
            j += l;
            if (m.count(s) == 0) {
                r.push_back(-1);
            } else {
                r.push_back(m[s].first);
            }
        }
        return r;
    }
    
    void check(vector<int> &seq, unordered_map<string, pair<int, int>> &m, vector<int> &r, int i, vector<string> &L, int l) {
        int j = 0, k = 0, z = m.size();
        vector<int> c(z, 0);
        for (string s : L) {
            c[m[s].first] = m[s].second;
        }
        vector<int> t = c;
        while (k < seq.size()) {
            while (k < seq.size() && seq[k] >= 0 && t[seq[k]] > 0) {
                t[seq[k]]--;
                k++;
            }
            if (k - j == L.size()) r.push_back(i + j * l);
            if (k < seq.size() && seq[k] == -1) {
                j = k + 1;
                k = j;
                t = c;
            } else {
                t[seq[j++]]++;
            }
        }
    }
};
