class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int w, h, i, j;
        w = board.size();
        h = board[0].size();
        for (i = 0; i < w; i++) {
            for (j = 0; j < h; j++) {
                if (board[i][j] == word[0] && search(board, word, i, j, 1)) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, string &word, int i, int j, int s) {
        if (s == word.length()) return true;
        char c = board[i][j];
        board[i][j] = '.';
        if (i > 0 && board[i-1][j] == word[s] && search(board, word, i-1, j, s+1)) return true;
        if (i < board.size() - 1 && board[i+1][j] == word[s] && search(board, word, i+1, j, s+1)) return true;
        if (j > 0 && board[i][j-1] == word[s] && search(board, word, i, j-1, s+1)) return true;
        if (j < board[0].size() - 1 && board[i][j+1] == word[s] && search(board, word, i, j+1, s+1)) return true;
        board[i][j] = c;
        return false;
    }
};
