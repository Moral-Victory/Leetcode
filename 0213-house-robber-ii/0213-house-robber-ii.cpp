class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);

        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            int pick=nums[i];
            if(i-1>0){
                pick+=dp[i-2];
            }
            
            int non_pick=0+dp[i-1];
            dp[i]=max(pick, non_pick); 
        }
        return dp[n-1]; 
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end()-1);
        int l=solve(nums1);
        vector<int> nums2(nums.begin()+1, nums.end());
        int r=solve(nums2);
        return max(l, r);
    }
};