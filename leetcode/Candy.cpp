class Solution {
public:
    int candy(vector<int> &ratings) {
        int i, s = 0, l = ratings.size();
        int *c = new int[l];
        int *d = new int[l];
        vector<int> z;
        for (i = 0; i < l; i++) {
            c[i] = 1;
            d[i] = 0;
            if (i > 0 && ratings[i] > ratings[i-1]) {
                d[i]++;
            }
            if (i < l - 1 && ratings[i] > ratings[i+1]) {
                d[i]++;
            }
            if (d[i] == 0) z.push_back(i);
        }
        while (!z.empty()) {
            i = z.back();
            z.pop_back();
            s += c[i];
            if (i > 0 && ratings[i-1] > ratings[i]) {
                d[i-1]--;
                if (d[i-1] == 0) {
                    c[i-1] = c[i] + 1;
                    if (i-1 > 0 && ratings[i-1] > ratings[i-2]) {
                        c[i-1] = max(c[i-1], c[i-2] + 1);
                    }
                    z.push_back(i-1);
                }
            }
            if (i < l - 1 && ratings[i+1] > ratings[i]) {
                d[i+1]--;
                if (d[i+1] == 0) {
                    c[i+1] = c[i] + 1;
                    if (i+1 < l-1 && ratings[i+1] > ratings[i+2]) {
                        c[i+1] = max(c[i+1], c[i+2]+1);
                    }
                    z.push_back(i+1);
                }
            }
        }
        return s;
    }
};
