class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        int ans=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1){
            return 0;
        }
        while(j<n){
            int diff=abs(nums[i]-nums[j]);
            ans=min(diff, ans);
            j++;
            i++;
            // else{
            //     i++;
            // }
        }
        return ans;
    }
};