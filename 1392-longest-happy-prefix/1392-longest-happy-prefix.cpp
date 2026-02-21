class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> LPS(n, 0);
        int pref=0;
        int suff=1;
        while(suff<n){
            if(s[pref]==s[suff]){
                LPS[suff]=pref+1;
                suff++;
                pref++;
            }
            else{
                if(pref==0){
                    LPS[suff]=0;
                    suff++;
                }
                else{
                    pref=LPS[pref-1];
                }
            }
        }
        string ans=s.substr(0, LPS[n-1]);
        return ans;
    }
};