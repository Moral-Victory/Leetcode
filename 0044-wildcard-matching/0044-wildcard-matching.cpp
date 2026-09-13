class Solution {
public:
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i==0 && j>0){
            for(int t=0; t<=j-1; t++){
                if(p[t]!='*'){
                    return 0;
                }
            }
            return 1;
        }
        if(i>0 && j==0){
            return 0;    
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j]=solve(s, p, i-1, j-1, dp);
        }
        else if(p[j-1]=='*'){
            return dp[i][j]= (solve(s, p, i-1, j, dp) || solve(s, p, i, j-1, dp));
        }
        else{
            return dp[i][j]=0;
        }


    }

    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solve(s, p, m, n, dp);
        vector<int> prev(n+1, -1);
        vector<int> curr(n+1, -1);


        prev[0]=1;
        for(int j = 1; j <= n; j++) {

            prev[j] = 1;

            for(int t = 0; t <= j-1; t++) {
                if(p[t] != '*') {
                    prev[j] = 0;
                    break;
                }
            }
        }

            

        for(int i=1; i<m+1; i++){
            curr[0]=0;
            for(int j=1; j<n+1; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j]= (prev[j] || curr[j-1]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }

        return prev[n];

    }
};