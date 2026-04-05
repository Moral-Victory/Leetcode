class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, int n, int m, vector<vector<int>>& dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1){
            return dp[n-1][j]=triangle[n-1][j];
        }
        int down=triangle[i][j]+solve(i+1, j, triangle, n, m, dp);
        int down_diagonal=triangle[i][j]+solve(i+1, j+1, triangle, n, m, dp);
        return dp[i][j]=min(down, down_diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, 0, triangle, n, m, dp);
        for(int i=0; i<n; i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int down=triangle[i][j]+dp[i+1][j];
                int down_diagonal=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down, down_diagonal);
            }
        }
        return dp[0][0];
        
    }
};