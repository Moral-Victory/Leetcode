class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               ((i > 0 && j > 0) ? prefix[i - 1][j - 1] : 0) +
                               mat[i][j];
            }
        }

        auto find_sum = [&](int i, int j, int r, int c) {
            int sum = prefix[r][c];
            if (i > 0) {
                sum -= prefix[i - 1][c];
            }
            if (j > 0) {
                sum -= prefix[r][j - 1];
            }
            if (i > 0 && j > 0) {
                sum += prefix[i - 1][j - 1];
            }
            return sum;
        };
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int offset = ans; offset <= min(n - j - 1, m - i - 1);
                     offset++) {
                    int r = i + offset;
                    int c = j + offset;
                    int sum = find_sum(i, j, r, c);
                    if (sum <= threshold) {
                        ans = max(ans, offset + 1);
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};