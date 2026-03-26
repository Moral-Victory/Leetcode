class Solution {
public:
    // int mod=(int)(2*1e9);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> dp(m, 0);
        for(int i=0; i<m; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j]==1){
                    temp[j]=0;
                }
                else if(i==0 && j==0){
                    temp[j]=1;
                }
                else{
                    int left=0;
                    int up=0;
                    if(i>0){
                        up = dp[j];
                    }
                    if(j>0){
                        left = temp[j-1];
                    }
                    temp[j] = left + up;
                }    
            }
            dp=temp;
        }
        return dp[n-1]; 
    }
};