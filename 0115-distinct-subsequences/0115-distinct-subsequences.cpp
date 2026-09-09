class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return dp[i][j]= solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        }
        else{
            return dp[i][j]= solve(i-1, j, s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, s, t, dp);

        vector<vector<double>> dp(m+1, vector<double>(n+1, -1));
        vector<double> prev(n+1, -1);
        vector<double> curr(n+1, -1);
        prev[0]=1;
        curr[0]=1;
        for(int i=1; i<=n; i++){
            prev[i]=0;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                curr[j]= prev[j-1] + prev[j];
                }
            else{
                curr[j]= prev[j];
                }
            }
            prev=curr;
        }
        return (int)prev[n];

    }
};