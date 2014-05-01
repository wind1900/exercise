class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> cand;
        int fac = 1;
        string r = "";
        for (int i = 1; i <= n; i++) {
            cand.push_back(i);
            fac *= i;
        }
        k = (k - 1) % fac;
        for (int i = n; i > 0; i--) {
            fac /= i;
            r += '0' + cand[k / fac];
            cand.erase(cand.begin() + k / fac);
            k = k % fac;
        }
        return r;
    }
    
};
