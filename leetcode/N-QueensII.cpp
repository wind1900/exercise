class Solution {
public:
    int totalNQueens(int n) {
        int *col = new int[n]();
        int *diag = new int[2 * n - 1]();
        int *diag1 = new int[2 * n - 1]();
        int r = 0;
        solve(n, 0, col, diag, diag1, r);
        return r;
    }
    
    void solve(int n, int l, int* col, int* diag, int* diag1, int &r) {
        if (l == n) {
            r++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[i + l] && !diag1[i - l + n - 1]) {
                col[i] = 1;
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
