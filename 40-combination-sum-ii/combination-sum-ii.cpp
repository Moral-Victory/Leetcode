class Solution {
public:
    void combination(vector<int>& candidates, int target,
                     vector<vector<int>>& ans, vector<int>& ds, int ind,
                     int sumdiff, int n) {

        if (sumdiff == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < n; i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > sumdiff) {
                break;
            }
            ds.push_back(candidates[i]);
            sumdiff -= candidates[i];
            combination(candidates, target, ans, ds, i + 1, sumdiff, n);
            ds.pop_back();
            sumdiff += candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        int n = candidates.size();
        combination(candidates, target, ans, ds, 0, target, n);
        return ans;
    }
};