class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(n-1, m-1, text1, text2, dp);
        for(int i=0; i<n+1; i++){
                dp[i][0]=0;
        }

        for(int i=0; i<m+1; i++){
                dp[0][i]=0;
        }


        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0+max(dp[i][j-1], dp[i-1][j]);
                }
                
            }
        }

        return dp[n][m];


    }

    int minDistance(string word1, string word2) {
        int req = longestCommonSubsequence(word1, word2);
        int m=word1.size();
        int n=word2.size();
        return (m-req)+(n-req);
    }
};