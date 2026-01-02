class Solution {
public:
    void solve(int i, int j, int m, int n, int gold, int& gold_max, vector<vector<int>>& grid){
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            gold_max=max(gold_max, gold);
            return;
        }
        int temp = grid[i][j];
        gold+=grid[i][j];
        grid[i][j]=0;
        int dr[4] = {-1, 1, 0, 0};  // row movement
        int dc[4] = {0, 0, -1, 1};  // col movement
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            solve(nr, nc, m, n, gold, gold_max, grid);
        }
        grid[i][j] = temp;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int gold_max=0;
        int gold=0;
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                solve(i, j, m, n, gold, gold_max, grid);
                ans=max(gold_max, ans);
            }
        }
        return ans;
    }
};