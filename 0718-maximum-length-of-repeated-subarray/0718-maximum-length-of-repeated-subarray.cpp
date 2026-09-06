class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        vector<int> curr(n+1, -1);
        vector<int> prev(n+1, -1);
        for(int i=0; i<=n; i++){
            prev[i]=0;
        }
        curr[0]=0;

        int ans=0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(nums1[i-1]==nums2[j-1]){
                    curr[j]=1+prev[j-1];
                    ans=max(ans, curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
            curr[0]=0;
        }
        return ans;

    }
};