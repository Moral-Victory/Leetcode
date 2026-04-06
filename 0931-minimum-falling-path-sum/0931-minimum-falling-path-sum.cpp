class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp){
        
        if(j<0||j>=m){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==0){
            return matrix[0][j];
        }
        int left_diag=solve(i-1, j-1, matrix, n, m, dp);
        int up=solve(i-1, j, matrix, n, m, dp);
        int right_diag=solve(i-1, j+1, matrix, n, m, dp);
        return dp[i][j]=matrix[i][j]+min(min(left_diag, up), right_diag);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        // for(int j=0; j<m; j++){
        //     ans=min(ans, solve(n-1, j, matrix, n, m, dp));
        // }
        for(int j=0; j<m; j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int left_diag=INT_MAX;
                if(j>0) left_diag=dp[i-1][j-1];
                int up=dp[i-1][j];
                int right_diag=INT_MAX;
                if(j<m-1) right_diag=dp[i-1][j+1];
                dp[i][j]=matrix[i][j]+min(min(left_diag, up), right_diag);
            }
        }

        for(int j = 0; j < m; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};