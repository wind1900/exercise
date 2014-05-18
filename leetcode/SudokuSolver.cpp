class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        bool row[9][9];
        bool col[9][9];
        bool box[9][9];
        bool done = false;
        int i, j, n;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                row[i][j] = false;
                col[i][j] = false;
                box[i][j] = false;
            }
        }
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    n = board[i][j] - '0';
                    row[i][n-1] = true;
                    col[j][n-1] = true;
                    box[i/3*3+j/3][n-1] = true;
                }
            }
        }
        search(0, 0, row, col, box, board, done);
    }
    
    void search(int i, int j, bool row[9][9], bool col[9][9], bool box[9][9], vector<vector<char>> &board, bool &done) {
        if (i == 9) {
            done = true;
            return;
        }
        int ii = i, jj = j + 1;
        if (jj == 9) {
            ii++;
            jj = 0;
        }
        if (board[i][j] != '.') {
            search(ii, jj, row, col, box, board, done);
            return;
        }
        for (int n = 0; n < 9; n++) {
            if (row[i][n]) continue;
            if (col[j][n]) continue;
            if (box[i/3*3+j/3][n]) continue;
            row[i][n] = true;
            col[j][n] = true;
            box[i/3*3+j/3][n] = true;
            board[i][j] = '1' + n;
            search(ii, jj, row, col, box, board, done);
            if (done) return;
            board[i][j] = '.';
            row[i][n] = false;
            col[j][n] = false;
            box[i/3*3+j/3][n] = false;
        }
    }
    
};
