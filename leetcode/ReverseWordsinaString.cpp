class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j;
        vector<string> v;
        string r = "";
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') i++;
            if (i >= s.length()) break;
            j = i + 1;
            while (j < s.length() && s[j] != ' ') j++;
            v.push_back(s.substr(i, j - i));
            i = j;
        }
        if (v.empty()) {
            s = r;
            return;
        }
        r = v.back();
        for (auto it = v.rbegin(); ++it != v.rend();) {
            r += " " + *it;
        }
        s = r;
    }
};
