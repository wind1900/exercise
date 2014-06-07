class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int i, j, w, h;
        w = board.size();
        if (w == 0) return;
        h = board[0].size();
        vector<pair<int, int>> q;
        pair<int, int> p;
        for (i = 0; i < h; i++) {
            if (board[0][i] == 'O') {
                q.push_back(make_pair(0, i));
                board[0][i] = 'y';
            }
            if (board[w-1][i] == 'O') {
                q.push_back(make_pair(w-1, i));
                board[w-1][i] = 'y';
            }
        }
        for (i = 0; i < w; i++) {
            if (board[i][0] == 'O') {
                q.push_back(make_pair(i, 0));
                board[i][0] = 'y';
            }
            if (board[i][h-1] == 'O') {
                q.push_back(make_pair(i, h-1));
                board[i][h-1] = 'y';
            }
        }
        while (!q.empty()) {
            p = q.back();
            q.pop_back();
            i = p.first;
            j = p.second;
            if (i > 0 && board[i-1][j] == 'O') {
                q.push_back(make_pair(i-1, j));
                board[i-1][j] = 'y';
            }
            if (i < w - 1 && board[i+1][j] == 'O') {
                q.push_back(make_pair(i+1, j));
                board[i+1][j] = 'y';
            }
            if (j > 0 && board[i][j-1] == 'O') {
                q.push_back(make_pair(i, j-1));
                board[i][j-1] = 'y';
            }
            if (j < h - 1 && board[i][j+1] == 'O') {
                q.push_back(make_pair(i, j+1));
                board[i][j+1] = 'y';
            }
        }
        for (i = 0; i < w; i++) {
            for (j = 0; j < h; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'y') board[i][j] = 'O';
            }
        }
    }
};
