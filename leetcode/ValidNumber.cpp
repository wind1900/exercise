class Solution {
public:
    bool isNumber(const char *s) {
        bool bm = false;
        while (*s == ' ') s++;
        if (*s == '+' || *s == '-') s++;
        if (*s == '.') {
            bm = true;
        }
        if (!bm && (*s < '0' || *s > '9')) return false;
        while (*s >= '0' && *s <= '9') {
            s++;
        }
        if (*s == '.') {
            s++;
            if (bm && (*s < '0' || *s > '9')) return false;
            while (*s >= '0' && *s <= '9') s++;
        }
        if (*s == 'e') {
            s++;
            if (*s == '+' || *s == '-') s++;
            if (*s < '0' || *s > '9') return false;
            while (*s >= '0' && *s <= '9') {
                s++;
            }
        }
        while (*s == ' ') s++;
        return *s == 0;
    }
};
