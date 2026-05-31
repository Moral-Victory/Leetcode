class Solution {
public:

    int findWays(vector<int>& arr, int k)
    {
    	// Write your code here.
    	int n=arr.size();
        // int mod =1e9+7;
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
    
    	    // for(int i=0; i<n; i++){
            //     dp[i][0]=1;
            // }
            // if(arr[0]<=k){
            //     dp[0][arr[0]]=1;
            // }
    
            if(arr[0] == 0) dp[0][0] = 2; 
            else dp[0][0] = 1; 
            if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
            
            for(int i=1; i<n; i++){
                for(int j=0; j<=k; j++){
                    int non_take=dp[i-1][j];
                    int take=0;
                    if(arr[i]<=j){
                        // sum-=arr[ind];
                        // take=solve(ind-1, sum, arr, dp);
                        // sum+=arr[ind];
                        take=dp[i-1][j-arr[i]];
                    }
                    // dp[i][j]=(take+non_take)%(mod);
                    dp[i][j]=(take+non_take);
                }
            }
            int zeroes=0;
            for(int i=0; i<n; i++){
                if(arr[i]==0){
                   zeroes++; 
                }  
            }
            // return zeroes;
            // return dp[n-1][k]*pow(2, zeroes);
            return dp[n-1][k];
    
    };

    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];            
        }
        if(sum-diff < 0){
            return 0;
        }
        if((sum-diff)%2==1){
            return 0;
        }
        
        
        return findWays(arr, (sum - diff) / 2);
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};