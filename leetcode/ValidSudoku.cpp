class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[9][9], col[9][9], box[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                row[i][j] = true;
                col[i][j] = true;
                box[i][j] = true;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    if (row[i][num] && col[j][num] && box[boxId(i, j)][num]) {
                        row[i][num] = false;
                        col[j][num] = false;
                        box[boxId(i, j)][num] = false;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
    
    int boxId(int i, int j) {
        return (i / 3) * 3 + j / 3;
    }
};
