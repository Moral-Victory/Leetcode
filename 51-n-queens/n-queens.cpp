class Solution {
public:
    void distinct_solutions(vector<vector<string>>& ans, vector<string>& board,
                            vector<int>& left_row, vector<int>& upper_row,
                            vector<int>& lower_row, int col, int n) {
        if (col == board[0].size()) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (left_row[row] == 0 && upper_row[row + col] == 0 &&
                lower_row[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                left_row[row] = 1;
                upper_row[row + col] = 1;
                lower_row[n - 1 + col - row] = 1;
                distinct_solutions(ans, board,
                            left_row, upper_row,
                            lower_row, col+1, n);
                board[row][col] = '.';
                left_row[row] = 0;
                upper_row[row + col] = 0;
                lower_row[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        // string s(n, '.');
        // for (int i = 0; i < n; i++) {
        //     board[i] = s;
        // }
        vector<int> left_row(n, 0);
        vector<int> upper_row(2 * n - 1, 0);
        vector<int> lower_row(2 * n - 1, 0);
        distinct_solutions(ans, board,
                            left_row, upper_row,
                            lower_row, 0, n);
        return ans;
    }
};