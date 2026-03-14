class Solution {
public:
    void solve(int ind, int n, int k, vector<string>& ans, string& alpha, string s){
        
        if(ind==n){
            ans.push_back(s);
            return;
        }
        for(int i=0; i<alpha.size(); i++){
            if(ind==0){
                s.push_back(alpha[i]);
                solve(ind+1, n, k, ans, alpha, s);
                s.pop_back();
            }
            else if(s[ind-1]!=alpha[i]){
                s.push_back(alpha[i]);
                solve(ind+1, n, k, ans, alpha, s);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        string alpha="abc";
        string s;
        solve(0, n, k, ans, alpha, s);
        if(ans.size() < k) return "";
        return ans[k-1];
    }
};