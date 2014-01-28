class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        int *col = new int[n]();
        int *diag = new int[2 * n - 1]();
        int *diag1 = new int[2 * n - 1]();
        vector<vector<string> > r;
        solve(n, 0, col, diag, diag1, r);
        return r;
    }
    
    void solve(int n, int l, int* col, int* diag, int* diag1, vector<vector<string>> &r) {
        if (l == n) {
            vector<string> v(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                v[col[i] - 1][i] = 'Q';
            }
            r.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[i + l] && !diag1[i - l + n - 1]) {
                col[i] = l + 1;
                diag[i + l] = 1;
                diag1[i - l + n - 1] = 1;
                solve(n, l + 1, col, diag, diag1, r);
                col[i] = 0;
                diag[i + l] = 0;
                diag1[i - l + n - 1] = 0;
            }
        }
    }
};
