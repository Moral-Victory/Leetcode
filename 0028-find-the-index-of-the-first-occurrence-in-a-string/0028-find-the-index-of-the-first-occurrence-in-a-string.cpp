class Solution {
public:
    
    void lps_find(string s, vector<int>& LPS) {
        int n=s.size();
        // vector<int> LPS(n, 0);
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
    }

    int strStr(string haystack, string needle) {
        vector<int> LPS(needle.size(), 0);
        lps_find(needle, LPS);
        int first=0;
        int second=0;
        while(first<haystack.size() && second<needle.size()){
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=LPS[second-1];   
                }
            }
        }
        if(second==needle.size()){
            return first-second;
        }
        return -1;

    }
};