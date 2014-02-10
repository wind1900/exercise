class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.length();
        int bl = b.length();
        int rl = max(al, bl);
        int c = 0;
        string r(rl, '0');
        for (int i = 0; i < rl; i++) {
            if (i < al && a[al - i - 1] == '1') c++;
            if (i < bl && b[bl - i - 1] == '1') c++;
            r[rl - i - 1] = '0' + (c & 1);
            c = c >> 1;
        }
        if (c) r = '1' + r;
        return r;
    }
};
