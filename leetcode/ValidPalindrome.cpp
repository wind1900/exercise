class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        int a, b;
        while (i < j) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                a = s[i];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                a = s[i] + 'a' - 'A';
            } else {
                i++;
                continue;
            }
            if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')) {
                b = s[j];
            } else if (s[j] >= 'A' && s[j] <= 'Z') {
                b = s[j] + 'a' - 'A';
            } else {
                j--;
                continue;
            }
            if (a != b) return false;
            i++;
            j--;
        }
        return true;
    }
};
