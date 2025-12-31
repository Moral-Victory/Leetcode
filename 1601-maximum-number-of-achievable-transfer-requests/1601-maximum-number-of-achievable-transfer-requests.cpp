class Solution {
public:
    int cnt = 0;

    void solve(int ind, vector<vector<int>>& requests, vector<int>& v, int taken){
        // ✅ base case
        if (ind == requests.size()) {
            if (count(v.begin(), v.end(), 0) == v.size()) {
                cnt = max(cnt, taken);
            }
            return;
        }

        // ✅ take this request
        v[requests[ind][0]]++;
        v[requests[ind][1]]--;
        solve(ind + 1, requests, v, taken + 1);

        // backtrack
        v[requests[ind][0]]--;
        v[requests[ind][1]]++;

        // ❌ skip this request
        solve(ind + 1, requests, v, taken);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n, 0);
        solve(0, requests, v, 0);
        return cnt;
    }
};