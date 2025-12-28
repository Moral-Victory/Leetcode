class Solution {
public:
    int n;
    int ans = INT_MAX;
    void solve(int idx, vector<int>& cookies, int k, vector<int> &children){
        if(idx>=n){
            int unfairness = *max_element(begin(children), end(children));
            ans = min(ans, unfairness);
            return;
        }

        
        for(int i=0; i<k; i++){
            children[i]+=cookies[idx];
            solve(idx+1, cookies, k, children);
            children[i]-=cookies[idx];
        }
        
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        n = cookies.size();
        solve(0, cookies, k, children);  
        return ans;
    }
};