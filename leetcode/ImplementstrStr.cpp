class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (*needle == 0) return haystack;
        int i = -1, j = 1, b = 0;
        vector<int> p;
        p.push_back(-1);
        while (needle[j]) {
            if (needle[j] == needle[i+1]) {
                p.push_back(i+1);
                i++;
                j++;
            } else if (i == -1) {
                j++;
                p.push_back(-1);
            } else {
                i = p[i];
            }
        }
        i = 0;
        j = 0;
        while (needle[i]) {
            if (haystack[j] == 0) return NULL;
            i++;
            j++;
        }
        b = i-2;
        i = -1;
        j = 0;
        while (haystack[j+b-i]) {
            if (needle[i+1] == 0) return haystack + (j - i - 1);
            if (haystack[j] == needle[i+1]) {
                j++;
                i++;
            } else if (i == -1) {
                j++;
            } else {
                i = p[i];
            }
        }
        return NULL;
    }
};
