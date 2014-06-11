class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = 0, *pp = 0;
        while (*s) {
            if (*p == '?' || *p == *s) {
                p++;
                s++;
            } else if (*p == '*') {
                p++;
                pp = p;
                ss = s;
            } else if (pp) {
                p = pp;
                ss++;
                s = ss;
            } else {
                return false;
            }
        }
        while (*p == '*') p++;
        return *p == 0;
    }
};
