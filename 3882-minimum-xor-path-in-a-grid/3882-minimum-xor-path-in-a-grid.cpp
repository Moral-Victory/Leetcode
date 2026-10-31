class Solution {
public:

    // int solve(int i, int j, vector<vector<int>>& grid, int& ans, int m, int n, vector<vector<int>>& vis, vector<vector<int>>& dp){

    //         if(i<0 || j<0 || i>m || j>n){
    //             return INT_MAX;
    //         }
            
    //         if(i==0 && j==0){
    //             return dp[i][j]=grid[0][0];
    //         }
    //         // if(dp[i][j]!=-1){
    //         //     return -1;
    //         // }

    //         // for(int k=0; k<2; k++){
    //         //         int i_new=i+rows[k];
    //         //         int j_new=j+cols[k];
    //         //         if(i_new>=0 && j_new>=0 && i_new<m && j_new<n && vis[i_new][j_new]!=1){
    //         //             vis[i_new][j_new]=1;
    //         //             dp[i_new][j_new]=solve(i_new, j_new, sum^grid[i_new][j_new], rows, cols, grid, ans, m, n, vis, dp);
    //         //             vis[i_new][j_new]=0;
    //         //         }
    //         //     }

    //         int up=grid[i][j]^solve(i, j-1, grid, ans, m, n, vis, dp);
    //         int left=grid[i][j]^solve(i-1, j, grid, ans, m, n, vis, dp);

    //         return dp[i][j]=min(up, left);
    //     }

    // solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp(m, vector<int>(n, vector<int>(1024, 0)))){
        
        
    // }



    int minCost(vector<vector<int>>& grid) {
        // int m=grid.size();
        // int n=grid[0].size();
        // int sum=grid[m-1][n-1];
        // vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        // vis[m-1][n-1]=1;
        // vector<int> rows={-1, 0};
        // vector<int> cols={0, -1};
        // int ans=INT_MAX;
        

        // solve(m-1, n-1, grid, ans, m, n, vis, dp);
        // return dp[m-1][n-1];

        
        int l=grid.size();
        int m=grid[0].size();
        // int n=grid[1].size();
        vector<vector<bitset<1024>>> dp(l, vector<bitset<1024>>(m));
        // dp[0][0][grid[0][0]] = 1;

        for(int i=0; i<l; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                  dp[0][0][grid[0][0]] = 1;  
                  continue;
                } 

                bitset<1024> up;
                bitset<1024> left;

                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                bitset<1024> combined = left|up;

                for(int k=0; k<1024; k++){
                    if(combined[k]){
                        int val=k^grid[i][j];
                        dp[i][j][val]=1;
                    }
                }
            }
        }
        int ans;

        for(int k=0; k<1024; k++){
            if(dp[l-1][m-1][k]){
                return k;
                break;
            }
        }
        return -1;




    }
};