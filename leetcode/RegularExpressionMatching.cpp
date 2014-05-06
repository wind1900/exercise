class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == 0 && *p == 0) return true;
        if (*p == 0) return (*s == 0);
        if (*(p+1) != '*') {
            if (*p == *s || (*p == '.' && *s != 0)) {
                return isMatch(s+1, p+1);
            } else {
                return false;
            }
        }
        while (*s && (*p == '.' || *p == *s)) {
            if (isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    }
};
