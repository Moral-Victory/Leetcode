class Solution {
public:
    int m;
    int n;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    void prefix_sum_rows(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        rows.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int rowsum = 0;
            for (int j = 0; j < n; j++) {
                rowsum += grid[i][j];
                rows[i][j] = rowsum;
            }
        }
    }
    void prefix_sum_cols(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        cols.assign(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            int colsum = 0;
            for (int i = 0; i < m; i++) {
                colsum += grid[i][j];
                cols[i][j] = colsum;
            }
        }
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        prefix_sum_rows(grid);
        prefix_sum_cols(grid);

        for (int side = min(m, n); side > 0; side--) {
            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    int targetsum =
                        rows[i][j + side - 1] - (j > 0 ? rows[i][j - 1] : 0);
                    bool sign = true;
                    for (int r = i + 1; r < i + side; r++) {
                        int sum = rows[r][j + side - 1] -
                                  (j > 0 ? rows[r][j - 1] : 0);
                        if (sum != targetsum) {
                            sign = false;
                            break;
                        }
                    }
                    if (sign == false) {
                        continue;
                    }
                    for (int c = j; c < j + side; c++) {
                        int sum = cols[i + side - 1][c] -
                                  (i > 0 ? cols[i - 1][c] : 0);
                        if (sum != targetsum) {
                            sign = false;
                            break;
                        }
                    }
                    if (sign == false) {
                        continue;
                    }
                    int diag = 0;
                    int anti_diag = 0;
                    for (int k = 0; k < side; k++) {
                        diag += grid[i + k][j + k];
                        anti_diag += grid[i + k][j + side - 1 - k];
                        
                    }
                    if (diag == targetsum && anti_diag == targetsum) {
                            return side;
                        }
                }
            }
        }

        return -1;
    }
};