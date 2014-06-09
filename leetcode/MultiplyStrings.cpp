class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length(), i, j, k;
        char *s1 = new char[l1+1];
        char *s2 = new char[l2+1];
        char *s = new char[l1+l2+1];
        memset(s1, 0, sizeof(char) * (l1 + 1));
        memset(s2, 0, sizeof(char) * (l2 + 1));
        memset(s, 0, sizeof(char) * (l1 + l2 + 1));
        for (i = 0; i < l1; i++) {
            s1[i] = num1[l1-i-1] - '0';
        }
        for (i = 0; i < l2; i++) {
            s2[i] = num2[l2-i-1] - '0';
        }
        for (i = 0; i < l1; i++) {
            for (j = 0; j < l2; j++) {
                s[i+j] += s1[i] * s2[j];
                s[i+j+1] += s[i+j] / 10;
                s[i+j] = s[i+j] % 10;
            }
        }
        i = 0;
        j = l1 + l2;
        while (s[j] == 0 && j > 0) j--;
        while (i < j) {
            s[i] += '0';
            s[j] += '0';
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];
            i++;
            j--;
        }
        if (i == j) s[i] += '0';
        return string(s);
    }

};
