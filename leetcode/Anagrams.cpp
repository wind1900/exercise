class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> g;
        vector<string> r;
        for (auto &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            g[t].push_back(s);
        }
        for (auto &v : g) {
            if (v.second.size() > 1) {
                r.insert(r.end(), v.second.begin(), v.second.end());
            }
        }
        return r;
    }
};