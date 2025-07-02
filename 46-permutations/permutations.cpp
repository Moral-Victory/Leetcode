class Solution {
public:
    void permutations(vector<int>& nums,vector<int>& ds, int n,
                      vector<vector<int>>& ans, vector<int>& freq
) {
        if (ds.size()==n) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                permutations(nums,ds, n, ans, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> freq(n, 0);
        permutations(nums,ds, n, ans, freq);
        return ans;
    }
};