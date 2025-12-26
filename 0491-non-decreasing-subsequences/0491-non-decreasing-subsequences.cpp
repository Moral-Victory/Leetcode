class Solution {
public:

    void solve(int ind, vector<int>& ds, vector<int>& nums, set<vector<int>>& st) {
        if (ind == nums.size()) {
            if (ds.size() >= 2) {
                st.insert(ds);
            }
            return;
        }
        if(ds.empty() || ds.back()<=nums[ind]){
            ds.push_back(nums[ind]);
            solve(ind+1, ds, nums, st);
            ds.pop_back();
        }
        solve(ind+1, ds, nums, st);
        
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ds;
        solve(0, ds, nums, st);
        return vector<vector<int>>(st.begin(), st.end());
    }
};