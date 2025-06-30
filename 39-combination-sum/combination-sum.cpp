class Solution {
public:
    void combination(vector<int>& candidates, int i, vector<int>& ds, int n,
                     vector<vector<int>>& ans, int target, int sum_diff) {
        if (i == n) {
            if (sum_diff == 0) {
                ans.push_back(ds);
                return;
            } else {
                return;
            }
        }
        if (candidates[i] <= sum_diff) {
            ds.push_back(candidates[i]);
            sum_diff -= candidates[i];
            combination(candidates, i, ds, n, ans, target, sum_diff);
            ds.pop_back();
            sum_diff += candidates[i];
        }

        
        combination(candidates, i + 1, ds, n, ans, target, sum_diff);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = candidates.size();
        combination(candidates, 0, ds, n, ans, target, target);
        return ans;
    }
};