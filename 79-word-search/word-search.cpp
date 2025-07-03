class Solution {
public:
    bool find_word(vector<vector<char>>& board, string word, int ind,
                   vector<vector<int>>& directions, int i, int j, int m, int n) {
        if (ind == word.size()) {
            return true;
        }
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] == '$') {
            return false;
        }
        if (board[i][j] != word[ind]) {
            return false;
        }
        char temp = board[i][j] ;
        board[i][j] = '$';
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (find_word(board, word, ind + 1, directions, new_i, new_j, m,
                          n)) {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> directions;
        directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] &&
                    find_word(board, word, 0, directions, i, j, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }
};