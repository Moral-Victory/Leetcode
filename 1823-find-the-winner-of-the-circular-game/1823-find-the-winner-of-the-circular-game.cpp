class Solution {
public:

    int solve(int i, vector<int> &ds, int k){
        if(ds.size()==1){
            return ds[0];
        }
        i = (i + k - 1) % ds.size();
        ds.erase(ds.begin() + i);
        return solve(i, ds, k);
    }

    int findTheWinner(int n, int k) {
        vector<int> ds(n);
        for (int i = 0; i < n; i++) {
            ds[i] = i + 1;
        }
        return solve(0, ds, k);
    }
};