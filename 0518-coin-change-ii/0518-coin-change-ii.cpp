class Solution {
public:

    int solve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
                return (target%coins[0]==0);
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int not_take=solve(ind-1, target, coins, dp);
        int take=0;
        if(coins[ind]<=target){
            take=solve(ind, target-coins[ind], coins, dp);
        }
        return dp[ind][target]=not_take+take;
    }

    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount+1, 0));
        
        for(int j=0; j<amount+1; j++){
            if(j%coins[0]==0){
                dp[0][j]=1;
            }
            else{
                dp[0][j]=0;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<amount+1; j++){
                unsigned long long not_take=dp[i-1][j];
                unsigned long long take=0;
                if(coins[i]<=j){
                    take=dp[i][j-coins[i]];
                }
                dp[i][j]=not_take+take;
            }
        }
        return (int)dp[n-1][amount];


        // return solve(n-1, amount, coins, dp);
    }
};