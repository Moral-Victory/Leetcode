class Solution {
public:
    void subsequence(vector<int>& nums,int i,vector<int>& ds,int n,vector<vector<int>> &ans){
        if(i==n){
           ans.push_back(ds); 
           return;
        }
        ds.push_back(nums[i]);
        subsequence(nums,i+1,ds,n,ans);
        ds.pop_back();
        subsequence(nums,i+1,ds,n,ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n=nums.size();
        subsequence(nums,0,ds,n,ans);
        return ans;
    }
};