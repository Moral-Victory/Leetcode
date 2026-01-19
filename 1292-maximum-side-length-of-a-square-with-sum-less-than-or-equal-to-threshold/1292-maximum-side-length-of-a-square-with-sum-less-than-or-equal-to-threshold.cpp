class Solution {
public:
    int m;
    int n;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    void prefix_sum_rows(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        rows.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int rowsum = 0;
            for (int j = 0; j < n; j++) {
                rowsum += mat[i][j];
                rows[i][j] = rowsum;
            }
        }
    }
    void prefix_sum_cols(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        cols.assign(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            int colsum = 0;
            for (int i = 0; i < m; i++) {
                colsum += mat[i][j];
                cols[i][j] = colsum;
            }
        }
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        prefix_sum_rows(mat);
        prefix_sum_cols(mat);
        for (int side = min(m, n); side > 0; side--) {
            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    bool sign = true;
                    int sum=0;
                    for (int r = i; r < i + side; r++) {
                        sum+= (rows[r][j + side - 1] -
                                  (j > 0 ? rows[r][j - 1] : 0));
                        if (sum > threshold) {
                            sign = false;
                            break;
                        }
                    }
                    // if (sign == false) {
                    //     continue;
                    // }
                    if (sign) return side;
                }
            }
        }
        return 0;
    }
};