class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> m{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> p, q;
        p.push_back("");
        for (char c : digits) {
            int i = c - '2';
            for (string s : p) {
                for (char c1 : m[i]) {
                    q.push_back(s + c1);
                }
            }
            p = q;
            q.clear();
        }
        return p;
    }
};
