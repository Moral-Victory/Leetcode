class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        // return solve(n-1, sum, arr, dp);
        
        for(int i=1; i<n+1; i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum){
            dp[1][arr[0]]=true;
        }
        
        for(int i=2; i<n+1; i++){
            for(int j=1; j<=sum; j++){
                int non_take=dp[i-1][j];
                int take=false;
                if(arr[i-1]<=j){
                    // sum-=arr[ind];
                    // take=solve(ind-1, sum, arr, dp);
                    // sum+=arr[ind];
                    take=dp[i-1][j-arr[i-1]];
                }
                dp[i][j]=take||non_take;
            }
        }
        return dp[n][sum];
        
    }


    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        return isSubsetSum(nums, sum/2);
    }
};