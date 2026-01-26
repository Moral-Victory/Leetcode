class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            ans=max(nums[i]+nums[n-i-1], ans);
        }
        return ans;
    }
};