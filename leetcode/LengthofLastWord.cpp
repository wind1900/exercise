class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int r = 0;
        while (*s) {
            r = 0;
            while (*s && *s != ' ') {
                r++;
                s++;
            }
            while (*s == ' ') {
                s++;
            }
        }
        return r;
    }
};
