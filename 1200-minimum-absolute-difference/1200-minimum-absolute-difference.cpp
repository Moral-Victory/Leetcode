class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int diff = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 0; i < n - 1; i++) {
            int d = arr[i+1] - arr[i]; // sorted => no need abs

            if (d < diff) {
                diff = d;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            } else if (d == diff) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};
